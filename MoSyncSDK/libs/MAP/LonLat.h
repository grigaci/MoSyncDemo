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

/** 
* \file LonLat.h
* \brief Latitude and longitude coordinates, conversion to metres and pixels
* \author Lars-Åke Vinberg
*/

#ifndef LONLAT_H_
#define LONLAT_H_

#include <MAUtil/Geometry.h>
#include <maapi.h>
#include "madmath.h"
#include "PixelCoordinate.h"

namespace MAP
{
	static const double PI = 3.14159265358979323846;
	//
	// Resolution in pixels per meter at equator, at zoom level 0
	//
	static const double InitialResolution = 2.0 * PI * 6378137.09 / /*TileSize*/256; // 256 is size of google full tile at zoom 0
	//
	// Inverse of InitialResolution
	//
	static const double InvInitialResolution = 256 / ( 2.0 * PI * 6378137.09 ); // 256 is size of google full tile at zoom 0
	//
	// Origin offset in meters
	//
	static const double OriginShift = PI * 6378137.09;


 #if 0 // put these in magnification type later on and keep a flag ...
	/**
	 * Returns resolution in meters per pixel at equator.
	 */
	inline double resolution( int magnification )
	{
		return InitialResolution / ( 1 << magnification );
	}

	/**
	 * Returns the inverse of resolution.
	 */
	inline double invResolution( int magnification)
	{
		return ( 1 << magnification ) * InvInitialResolution;
	}
#endif

	inline double resolution( double magnification )
	{
		return InitialResolution / pow(2.0, magnification);
	}
		
	inline double invResolution( double magnification)
	{
		return pow(2.0, magnification) * InvInitialResolution;
	}

	//=========================================================================
	/**
	 * \brief This class maintains a coordinate in latitude / longitude,
	 * and provides conversion function to and from other coordinate systems.
	 */
	template <typename MagnificationT>
	class LonLatT
	//=========================================================================
	{
	public:
	private:
		/**
		 * Converts a pixel coordinate at a given zoom level of pyramid to EPSG:900913
		 */
		static void pixelsToMeters( const double pixelX, const double pixelY, const MagnificationT magnification, double& meterX, double& meterY )
		{
			double res = resolution( (double)magnification );
			meterX = pixelX * res - OriginShift;
			meterY = pixelY * res - OriginShift;
		}
		/**
		 * Converts EPSG:900913 to pyramid pixel coordinates in given zoom level.
		 */
		static void metersToPixels( const double meterX, const double meterY, const MagnificationT magnification, double& pixelX, double& pixelY )
		{
			double invres = invResolution( (double)magnification );
			pixelX = ( meterX + OriginShift ) * invres;
			pixelY = ( meterY + OriginShift ) * invres;
		}

		static double exp( double x ) { return pow( M_E, x ); }

		/**
		 * Converts XY point from Spherical Mercator EPSG:900913 to lat/lon in WGS84 Datum.
		 */
		static void metersToLonLat( const double metersX, const double metersY, double& lon, double& lat )
		{
			lon = metersX / OriginShift * 180.0;

			lat = 360.0 / PI * atan( exp( metersY * PI / OriginShift ) ) - 90.0;
		}
		/**
		 * Converts given lat/lon in WGS84 Datum to XY in Spherical Mercator EPSG:900913.
		 */
		static void lonLatToMeters( const double lon, const double lat, double& meterX, double& meterY )
		{
			meterX = lon * OriginShift / 180.0;
			meterY = log( tan( ( 90.0 + lat ) * PI / 360.0 ) ) * OriginShift / PI;
		}
		/**
		 * Returns a tile covering region in given pixel coordinates.
		 */
		static void pixelsToTile( const int tileSize, const double pixelX, const double pixelY, int& tileX, int& tileY )
		{
			tileX = int( ceil( pixelX / (double)tileSize ) - 1 );
			tileY = int( ceil( pixelY / (double)tileSize ) - 1 );
		}

		//NOTE: Keep for now

		//
		// Returns tile for given mercator coordinates.
		//
		//static void MetersToTile( const int tileSize, const double meterX, const double meterY, const int magnification, int& tileX, int& tileY )
		//{
		//	double pixelX, pixelY;
		//	MetersToPixels( meterX, meterY, magnification, pixelX, pixelY );
		//	PixelsToTile( tileSize, pixelX, pixelY, tileX, tileY );
		//}
		//
		// Returns bounds of the given tile in EPSG:900913 coordinates.
		//
		//static void TileBounds( const int tileSize, const int tileX, const int tileY, const int magnification, double& meterLeft, double& meterBottom, double& meterRight, double& meterTop )
		//{
		//	PixelsToMeters( tileX * tileSize, tileY * tileSize, magnification, meterLeft, meterBottom );
		//	PixelsToMeters( ( tileX + 1 ) * tileSize, ( tileY + 1 ) * tileSize, magnification, meterRight, meterTop );
		//}
		//
		// Returns bounds of the given tile in latutude/longitude using WGS84 datum.
		//
		//static void TileLonLatBounds( const int tileSize, const int tileX, const int tileY, const int magnification, double& minx, double& miny, double& maxx, double& maxy )
		//{
		//	double meterLeft, meterBottom, meterRight, meterTop;
		//	TileBounds( tileSize, tileX, tileY, magnification, meterLeft, meterBottom, meterRight, meterTop );
		//	MetersToLonLat( meterLeft, meterBottom, minx, miny );
		//	MetersToLonLat( meterRight, meterTop, maxx, maxy );
		//}

		//static void TileToQuadTree( const int tileX, const int tileY, const int zoom, char* buffer )
		//{
		//	int x = tileX;
		//	int y = ( ( 1 << zoom ) - 1) - tileY;
		//	char* p = buffer;
		//	for ( int i = zoom; i > 0; i-- )
		//	{
		//		int digit = 0;
		//		int mask = 1 << ( i - 1 );
		//		if ( ( x & mask ) != 0 )
		//			digit += 1;
		//		if ( ( y & mask ) != 0 )
		//			digit += 2;
		//		*p = (char)( '0' + digit );
		//		p++;
		//	}
		//	*p = '\0';
		//}

		// END NOTE

	public:
		/**
		 * Longitude
		 */
		double lon;
		/**
		 * Latitude
		 */
		double lat;
		/**
		 * Creates a LonLat initialized to (0, 0).
		 */
		LonLatT( )
		:	lon( 0 ),
			lat( 0 )
		{
		}
		/**
		 * Creates a LonLat.
		 */
		LonLatT( const double _lon, const double _lat )
		: lon( _lon ),
			lat( _lat )
		{
		}
		/**
		 * Creates a LonLat from thr given global pixel coordinate.
		 */
		LonLatT( const PixelCoordinateT<MagnificationT>& px )
		{
			double meterX, meterY;
			pixelsToMeters( px.getX( ), px.getY( ), px.getMagnification( ), meterX, meterY );
			metersToLonLat( meterX, meterY, lon, lat );
		}
		/**
		 * Creates a LonLat from the given global meter coordinates.
		 */
		static LonLatT<MagnificationT> fromMeters( const double meterX, const double meterY )
		{
			double lon, lat;
			metersToLonLat( meterX, meterY, lon, lat );
			return LonLatT<MagnificationT>( lon, lat );
		}
		/*
		 * tests if LonLat is invalid
		 */
		bool isValid( ) const
		{
		//	return lon != 0.0 && lat != 0.0;
			return (int)lon && (int)lat;
		}
		
		// NOTE: Keep for now

		//
		// Convert tile lower left corner plus pixel offset to WGS84 lat/lon.
		//
		//LonLat( const int tileSize, const MapTileCoordinate& tile, const double offsetX, const double offsetY )
		//{
		//	// tile to meters
		//	double meterLeft, meterBottom, meterRight, meterTop;
		//	TileBounds( tileSize, tile.getX( ), tile.getY( ), tile.getMagnification( ), meterLeft, meterBottom, meterRight, meterTop );
		//	// meters to pixels,
		//	double pixelX, pixelY;
		//	MetersToPixels( meterLeft, meterBottom, tile.getMagnification( ), pixelX, pixelY );
		//	// add pixels
		//	pixelX += offsetX;
		//	pixelY += offsetY;
		//	// pixels to lonlat
		//	double meterX, meterY;
		//	PixelsToMeters( pixelX, pixelY, tile.getMagnification( ), meterX, meterY );
		//	MetersToLonLat( meterX, meterY, Lon, Lat );
		//}

		// END NOTE

		/**
		 * Converts this to global pixel coordinates.
		 * Projection is assumed to be spherical Mercator (as opposed to ellipsoidal).
		 * This results in a slight Y-axis error.
		 * Spherical Mercator is chosen for compatibility with online tile servers
		 * such as Google Maps and Microsoft Virtual Earth.
		 */
		const PixelCoordinateT<MagnificationT> toPixels( MagnificationT magnification ) const
		{
			double meterX, meterY;
			lonLatToMeters( lon, lat, meterX, meterY );
			double pixelX, pixelY;
			metersToPixels( meterX, meterY, magnification, pixelX, pixelY );

			// These pixel values are always positive, so (int)(p + 0.5f) works as
			// poor man's rounding
			return PixelCoordinateT<MagnificationT>( magnification, (int)(pixelX + 0.5f), (int)(pixelY + 0.5f) );

		}
		/**
		 * Convert this to meters.
		 */
		void toMeters( double& meterX, double& meterY ) const
		{
			lonLatToMeters( lon, lat, meterX, meterY );
		}

		// NOTE: Keep for now

		//
		//MapTileCoordinate ToTile( const int tileSize, int magnification ) const
		//{
		//	double meterX, meterY;
		//	LonLatToMeters( Lon, Lat, meterX, meterY );
		//	int tileX, tileY;
		//	MetersToTile( tileSize, meterX, meterY, magnification, tileX, tileY );
		//	return MapTileCoordinate( tileX, tileY, magnification );
		//}

		//static void test( double lon, double lat )
		//{
		//	printf( "=== TEST===" );
		//	printf( "Lon = %f", lon );
		//	printf( "Lat = %f", lat );
		//	double mx, my;
		//	lonLatToMeters( lon, lat, mx, my );
		//	printf( "mx = %f", mx );
		//	printf( "my = %f", my );
		//	double llx, lly;
		//	metersToLonLat( mx, my, llx, lly );
		//	printf( "Lon = %f", llx );
		//	printf( "Lat = %f", lly );
		//}

		// END NOTE

	};
	
	typedef LonLatT<int> LonLatI;
	typedef LonLatT<double> LonLatD;
	typedef LonLatT<MagnificationType> LonLat;
}

#endif // LONLAT_H_
