/* Copyright (C) 2009 Ali Mosavian

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
#include "testify.hpp"

using namespace Testify;

/**
 * A test case
 */
class MyTestCase : public TestCase
{
public:
	MyTestCase( )
	: TestCase( "MyTestCase2" )
	{
		// Add tests
		addTest( bind( &MyTestCase::myTest1, this ), "testMethod1" );
		addTest( bind( &MyTestCase::myTest2, this ), "testMethod2" );
		addTest( bind( &MyTestCase::myTest3, this ), "testMethod3" );
	}

	/**
	 * The actual tests here
	 */
	void myTest1 ( void )
	{
		TESTIFY_ASSERT( 1 );
	}


	void myTest2 ( void )
	{
		TESTIFY_ASSERT( 0 );
	}


	void myTest3 ( void )
	{
		TESTIFY_ASSERT( 1 );
	}
};

/**
 * A test function
 */
static void Test2 ( void )
{
	TESTIFY_ASSERT( "dbc" == "abc" );
}

/**
 * A test function
 */
static void Test3 ( int a, float b )
{
	TESTIFY_ASSERT( a == b );
}



/**
 * The hook
 */
static Test *array[] = { Test::create( bind( Test2 ), "Test2" ),
						 Test::create( bind( Test3, 1, 3.0f ), "Test3" ),
						 new MyTestCase( ),
						 NULL };

static TestHook hook( array );

