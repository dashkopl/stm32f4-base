/******************************************************************************
 *
 * (C) Copyright 2005-2050
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License as
 *   published by the Free Software Foundation; either version 2 of
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 *   MA 02111-1307 USA
 *
 * FILE NAME:
 *   _stdio.h
 * DESCRIPTION:
 *   Extended stdio.
 * HISTORY:
 *   2015.8.4        PANDA         Create
 *
 *****************************************************************************/

#ifndef ___STDIO_H
#define ___STDIO_H


#if STDIO_SUPPORT

#define NO_PENDING  (0)
#define PENDING     (-1)

int  _getchar(int pending);
void _putchar(char ch);
void _puts(const char *str);
int  _sprintf(char *buffer, const char *fmt, ...)  __attribute__((format(printf,2,3)));
int  _printf(const char *fmt, ...)                 __attribute__((format(printf,1,2)));

#define getchar(...)            _getchar(__VA_ARGS__)
#define putchar(...)            _putchar(__VA_ARGS__)
#define puts(...)               _puts(__VA_ARGS__)
#define sprintf(...)            _sprintf(__VA_ARGS__)
#define printf(...)             _printf(__VA_ARGS__)

#else

#define getchar(...)            /* do nothing */
#define putchar(...)            /* do nothing */
#define puts(...)               /* do nothing */
#define sprintf(...)            /* do nothing */
#define printf(...)             /* do nothing */

#endif


#endif /* ___STDIO_H */

