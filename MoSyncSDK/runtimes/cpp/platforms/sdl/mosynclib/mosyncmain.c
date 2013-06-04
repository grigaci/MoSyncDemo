/* Copyright (C) 2009 Mobile Sorcery AB

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

typedef int (*mainfunc)();

//__attribute__((dllimport)) 
int mosyncLibMain(int argc, char** argv, mainfunc maMain);

int MAMain();

#ifdef WIN32
#include <windows.h>

//int main(int argc, char** argv) {
int APIENTRY WinMain(HINSTANCE a, HINSTANCE b, LPSTR c, int d) {
#else
int main() {
#endif
	return mosyncLibMain(0, 0, MAMain);
}
