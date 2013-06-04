/* Copyright (C) 2010 Mobile Sorcery AB

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License, version 2, as published by
the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.
*/

//
// GeoPointLayer.cpp
//
// Author: Lars Ake Vinberg
//

#include "MapConfig.h"
#include <mastdlib.h>

#include "MemoryMgr.h"
#include "GeoPointLayer.h"
#include "DebugPrintf.h"
#include "MapViewport.h"

namespace MAP
{
	//-------------------------------------------------------------------------
	GeoPointLayer::GeoPointLayer( ) :
	//-------------------------------------------------------------------------
		mDataSource( NULL ),
		mSelectedItem( 0 )
	{
	}

	//-------------------------------------------------------------------------
	void GeoPointLayer::draw( MapViewport* viewport, const Rect& bounds, MagnificationType magnification, bool isLayerSelected )
	//-------------------------------------------------------------------------
	{
		Enumerator<GeoPoint*> e = Enumerator<GeoPoint*>( *this );

		while ( e.moveNext( ) )
		{
			GeoPoint* item = e.current( );
			drawItem( viewport, item, bounds, magnification, false, false );
		}
		//
		// Draw description text
		//
		if ( isLayerSelected )
		{
			GeoPoint* item = getItem( mSelectedItem );
			if ( item != NULL )
			{
				drawItem( viewport, item, bounds, magnification, true, true );
			}
		}
	}

	//-------------------------------------------------------------------------
	void GeoPointLayer::drawItem( MapViewport* viewport, GeoPoint* item, const Rect& bounds, MagnificationType magnification, bool selected, bool drawText )
	//-------------------------------------------------------------------------
	{
		// temporary hack.
		if(viewport->isZooming()) return;
	
		MAPoint2d widgetPx = getScreenPixel(viewport, magnification, item);

		/* Removed to make items always be rendered.
		if ( widgetPx.x >= bounds.x && 
			widgetPx.x < bounds.width && 
			widgetPx.y >= bounds.y && 
			widgetPx.y < bounds.height )
		{
		*/
			GeoPointLayerRenderer* renderer = getRenderer( );
			//
			// Render marker
			//
			renderer->renderItem( this, item, bounds, bounds.x + widgetPx.x, bounds.y + widgetPx.y, selected );
			//
			// Render item text
			//
			if ( drawText )
			{
				renderer->renderItemText( this, item, bounds, bounds.x + widgetPx.x, bounds.y + widgetPx.y );
			}
		//}
	}

	//-------------------------------------------------------------------------
	GeoPointDataSource* GeoPointLayer::getDataSource( ) const
	//-------------------------------------------------------------------------
	{
		return mDataSource;
	}

	//-------------------------------------------------------------------------
	void GeoPointLayer::setDataSource( GeoPointDataSource* dataSource )
	//-------------------------------------------------------------------------
	{
		deleteobject( mDataSource );
		mDataSource = dataSource;
		mDataSource->addListener( this );
	}

	//-------------------------------------------------------------------------
	int GeoPointLayer::size( )
	//-------------------------------------------------------------------------
	{
		return mDataSource->size( );
	}

	//-------------------------------------------------------------------------
	GeoPoint* GeoPointLayer::getItem( int index )
	//-------------------------------------------------------------------------
	{
		GeoPoint* item = mDataSource->getItem( index );
		return item;
	}

	//-------------------------------------------------------------------------
	void GeoPointLayer::dataChanged( GeoPointDataSource* sender )
	//-------------------------------------------------------------------------
	{
		onContentChanged( );
	}

	//-------------------------------------------------------------------------
	void GeoPointLayer::loadComplete( GeoPointDataSource* sender )
	//-------------------------------------------------------------------------
	{
		onContentChanged( );
	}

	//-------------------------------------------------------------------------
	void GeoPointLayer::selectItem( int index )
	//-------------------------------------------------------------------------
	{
		if (index != mSelectedItem) {
			mSelectedItem = index;
			onContentChanged( );
		}
	}

	//-------------------------------------------------------------------------
	void GeoPointLayer::selectNextItem( )
	//-------------------------------------------------------------------------
	{
		int newSelectedItem = mSelectedItem;
		newSelectedItem++;
		if ( newSelectedItem >= mDataSource->size( ) )
			newSelectedItem = 0;
		selectItem( newSelectedItem );
	}

	//-------------------------------------------------------------------------
	void GeoPointLayer::selectPreviousItem( )
	//-------------------------------------------------------------------------
	{
		int newSelectedItem = mSelectedItem;
		newSelectedItem--;
		if ( newSelectedItem < 0 )
			newSelectedItem = mDataSource->size( ) - 1;
		selectItem( newSelectedItem );
	}

	//-------------------------------------------------------------------------
	void GeoPointLayer::activateSelectedItem( )
	//-------------------------------------------------------------------------
	{
		GeoPoint* current = getItem( mSelectedItem );
		if ( current == NULL )
			return;

		Vector<IGeoPointLayerListener*>* l = getBroadcasterListeners<IGeoPointLayerListener>( *this );
		for ( int i = 0; i < l->size( ); i ++ )
			(*l)[i]->itemActivated( this, current );
	}

	static inline double Max( double x, double y ) { return x > y ? x : y; }
	static inline double Min( double x, double y ) { return x < y ? x : y; }

	const double LargeNum = 1E20;

	//-------------------------------------------------------------------------
	void GeoPointLayer::selectItemAtPixel( MapViewport *viewport, MagnificationType magnification, MAPoint2d screenPixel )
	//-------------------------------------------------------------------------
	{
		// If there's a point at this pixel coordinate, make it the selected point
		Enumerator<GeoPoint*> e = Enumerator<GeoPoint*>( *this );
		int selectedIndex = -1;
		int index = 0;

		while ( e.moveNext( ) )
		{
			GeoPoint* item = e.current( );
			MAPoint2d widgetPixel = getScreenPixel(viewport, magnification, item);

			if (abs(widgetPixel.x - screenPixel.x) < item->getMarkerSize() &&
				abs(widgetPixel.y - screenPixel.y) < item->getMarkerSize()) {
				Rect r = mRenderer->getItemRect(this, item, widgetPixel.x, widgetPixel.y, index == mSelectedItem);
				if (r.contains(screenPixel.x, screenPixel.y)) {
					selectedIndex = index;
				}
			}

			index++;
		}

		if (selectedIndex != -1) {
			selectItem(selectedIndex);
		}
	}

	//-------------------------------------------------------------------------
	void GeoPointLayer::getBoundingBox( double& left, double& top, double& right, double& bottom )
	//-------------------------------------------------------------------------
	{
		Enumerator<GeoPoint*> e = Enumerator<GeoPoint*>( *this );

		while ( e.moveNext( ) )
		{
			GeoPoint* item = e.current( );
			LonLat location = item->getLocation( );
			left = Min( left, location.lon );
			right = Max( right, location.lon );
			top = Max( top, location.lat );
			bottom = Min( bottom, location.lat );
		}
	}

	//-------------------------------------------------------------------------
	LonLat GeoPointLayer::getSelectedItemLocation( )
	//-------------------------------------------------------------------------
	{
		GeoPoint* current = getItem( mSelectedItem );
		return current ? current->getLocation( ) : LonLat( );
	}

	//-------------------------------------------------------------------------
	MAPoint2d GeoPointLayer::getScreenPixel( MapViewport* viewport, MagnificationType magnification, GeoPoint* item )
	//-------------------------------------------------------------------------
	{
		PixelCoordinate worldPx = item->getCachedPixelLocation( );
		if ( worldPx.getMagnification() != magnification )
		{
			LonLat lonlat = item->getLocation( );
			worldPx = lonlat.toPixels( magnification );
			item->setCachedPixelLocation( worldPx );
		}
		return viewport->worldPixelToViewport( worldPx );
	}
}
