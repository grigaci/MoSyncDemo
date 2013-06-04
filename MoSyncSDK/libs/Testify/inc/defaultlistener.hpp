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

/** \file defaultlistener.hpp
 * \brief Default listener for Testify
 *
 * \author Ali Mosavian
 *
 * Created on 1 Mar 2010
 */

#ifndef __STDTESTLISTENER_HPP__
#define __STDTESTLISTENER_HPP__

#include "common.h"
#include "testlistener.hpp"

NAMESPACE_BEGIN( Testify )

/**
 * @brief The default listener. Prints everything out to stdout.
 *
 */
class DefaultListener : public TestListener
{
private:
	char m_indent[32];
	int  m_nestLevel;
	bool m_testFailed;

	/**
	 * Internal, increase indentation level
	 */
	void indentInc ( void );

	/**
	 * Internal, decreases indentation level
	 */
	void indentDec ( void );

public:
	/**
	 * Constructor
	 */
	DefaultListener ( void );

	/**
	 * Notifies the listener that a test suite has started
	 *
	 * @param n Suite name
	 */
	virtual void beginSuite ( const char *n );

	/**
	 * Notifies the listener that a test suite has ended
	 *
	 */
	virtual void endSuite ( void );

	/**
	 * Notifies the listener that a test case has started
	 *
	 * @param n Suite name
	 */
	virtual void beginTestCase ( const char *n );

	/**
	 * Notifies the listener that a test case has ended
	 *
	 */
	virtual void endTestCase ( void );

	/**
	 * Notifies the listener that a test has started
	 *
	 * @param n Test name
	 */
	virtual void beginTest ( const char *n );

	/**
	 * Notifies the listener that a test has ended
	 *
	 */
	virtual void endTest ( void );

	/**
	 * Called once before any tests have been run
	 */
	virtual void beginUnit ( void );

	/**
	 * Called after all tests (functions and cases) have
	 * been run.
	 *
	 * @param t Number of tests run
	 * @param f Number of tests failed
	 */
	virtual void endUnit ( int t, int f );

	/**
	 * Notifies the listener that the test failed
	 *
	 * @param f File name
	 * @param l Line in file
	 * @param a Assertion that failed
	 */
	virtual void testFailed ( const char *f,
							  int l,
							  const char *a );
};


NAMESPACE_END

#endif /* __STDTESTLISTENER_HPP__ */
