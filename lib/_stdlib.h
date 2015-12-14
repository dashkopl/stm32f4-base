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
 *   _stdlib.h
 * DESCRIPTION:
 *   Extended stdlib.
 * HISTORY:
 *   2015.8.4        PANDA         Create
 *
 *****************************************************************************/

#ifndef ___STDLIB_H
#define ___STDLIB_H


#if 1

void _uitoa(unsigned int value, char *string, unsigned char radix);
void _itoa(int value, char *string, unsigned char radix);
void _ftoa(double value, char *string, int digits, char e_notation);

#endif


/* memory allocation related */
#if 1

#define _malloc(_n)     ({                                                  \
                            void *_p = (void *)malloc((int)(_n));           \
                            if ((uint32_t)_p == (uint32_t)NULL)             \
                            {                                               \
                                __fatal("malloc %d(B) failed!",             \
                                        (uint32_t)(_n));                    \
                            }                                               \
                            memset(_p, 0x0, (uint32_t)(_n));                \
                            _p;                                             \
                        })
#define _free(_p)       do {                                                \
                            free(_p);                                       \
                            _p = NULL;                                      \
                        } while (0)

#endif


#endif /* ___STDLIB_H */

