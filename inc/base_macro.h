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
 *   base_macro.h
 * DESCRIPTION:
 *   N/A
 * HISTORY:
 *   2015.8.5        PANDA         Create
 *
 *****************************************************************************/

#ifndef __BASE_MACRO_H
#define __BASE_MACRO_H


#include "cfg_system_def.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <malloc.h>
#include <errno.h>
#include "_stdlib.h"
#include "_stdio.h"
#include "_string.h"


/* volatile/none-volatile address access */
#define VP64                *(volatile uint64_t *)(uint32_t)
#define VP32                *(volatile uint32_t *)(uint32_t)
#define VP16                *(volatile uint16_t *)(uint32_t)
#define VP8                 *(volatile uint8_t  *)(uint32_t)
#define P64                 *(uint64_t *)(uint32_t)
#define P32                 *(uint32_t *)(uint32_t)
#define P16                 *(uint16_t *)(uint32_t)
#define P8                  *(uint8_t  *)(uint32_t)

/* combined macro generation, maximum 3 level delay expanding */
#define _COMBINE2_DELAY0(a,b)           a##b
#define _COMBINE3_DELAY0(a,b,c)         a##b##c
#define _COMBINE4_DELAY0(a,b,c,d)       a##b##c##d
#define _COMBINE5_DELAY0(a,b,c,d,e)     a##b##c##d##e
#define _COMBINE2_DELAY1(a,b)           _COMBINE2_DELAY0(a,b)
#define _COMBINE2_DELAY2(a,b)           _COMBINE2_DELAY1(a,b)
#define _COMBINE2_DELAY3(a,b)           _COMBINE2_DELAY2(a,b)
#define _COMBINE3_DELAY1(a,b,c)         _COMBINE3_DELAY0(a,b,c)
#define _COMBINE3_DELAY2(a,b,c)         _COMBINE3_DELAY1(a,b,c)
#define _COMBINE3_DELAY3(a,b,c)         _COMBINE3_DELAY2(a,b,c)
#define _COMBINE4_DELAY1(a,b,c,d)       _COMBINE4_DELAY0(a,b,c,d)
#define _COMBINE4_DELAY2(a,b,c,d)       _COMBINE4_DELAY1(a,b,c,d)
#define _COMBINE4_DELAY3(a,b,c,d)       _COMBINE4_DELAY2(a,b,c,d)
#define _COMBINE5_DELAY1(a,b,c,d,e)     _COMBINE5_DELAY0(a,b,c,d,e)
#define _COMBINE5_DELAY2(a,b,c,d,e)     _COMBINE5_DELAY1(a,b,c,d,e)
#define _COMBINE5_DELAY3(a,b,c,d,e)     _COMBINE5_DELAY2(a,b,c,d,e)
#define COMBINE(a,b)                    _COMBINE2_DELAY3(a,b)
#define COMBINE2(a,b)                   _COMBINE2_DELAY3(a,b)
#define COMBINE3(a,b,c)                 _COMBINE3_DELAY3(a,b,c)
#define COMBINE4(a,b,c,d)               _COMBINE4_DELAY3(a,b,c,d)
#define COMBINE5(a,b,c,d,e)             _COMBINE5_DELAY3(a,b,c,d,e)

#define _TOSTR_DELAY0(v)                # v
#define _TOSTR_DELAY1(v)                _TOSTR_DELAY0(v)
#define _TOSTR_DELAY2(v)                _TOSTR_DELAY1(v)
#define _TOSTR_DELAY3(v)                _TOSTR_DELAY2(v)
#define TOSTR(v)                        _TOSTR_DELAY3(v)

/* remove warning */
#define NO_WARNING(x)       do { if (x) {} } while (0)

/* calculate the total element of an array */
#define COUNT_OF(n)         (int32_t)(sizeof(n) / sizeof((n)[0]))

/* calculate the Byte Offset of member in struct.
 *
 * e.g:
 *  typedef struct
 *  {
 *      int  a;
 *      int  b;
 *      char c;
 *  } TYPE_S;
 *
 * To get the Byte Offset of (c) in TYPE_S, just use offsetof(TYPE_S, c).
 *  acturally, the offset in this sample is 8.
 */
#undef offsetof
#ifdef __compiler_offsetof
 #define offsetof(t, m)     __compiler_offsetof(t, m)
#else
 #define offsetof(t, m)     ((size_t) &((t *)0)->m)
#endif

/* bit operation */
#define SET_BIT(n, b)       do { (n) |= (1UL << (uint8_t)(b));  } while (0)
#define CLR_BIT(n, b)       do { (n) &= ~(1UL << (uint8_t)(b)); } while (0)
#define READ_BIT(n, b)      ((bool)(((n) >> (uint8_t)(b)) & 1UL))
#define REVERSE_BIT(n, b)   do { (n) ^= (1UL << (uint8_t)(b)); } while (0)
#define WRITE_BIT(n, b, v)  do { (n) = ((n) & ~(1UL << (uint8_t)(b))) | ((uint32_t)(v) << (uint8_t)(b)); } while (0)

/* Get mask.
 *
 * e.g:
 *   if get 10-bit mask started from bit0, it will return 0x3FF.
 *   if get 10-bit mask started from bit5, it will return 0x7FE0.
 *
 * Note:
 *   1. the range of (start) : 0 <= start <= 31
 *      the range of (n)     : 0 <= n <= 31
 *   2. by default, this will return 32-bit mask, if only need 8-bit or 16-bit mask,
 *      you should limit the result like this:
 *         8-bit :  (uint8_t)(GET_MASK(0, 5))  --- Start from bit0, occupy 5 bits;
 *        16-bit : (uint16_t)(GET_MASK(3, 7))  --- Start from bit3, occupy 7 bits;
 */
#define GET_MASK(start, n)  (((0x1UL << (uint8_t)(n)) - 1) << (uint8_t)(start))

/* operate memory as big-endian */
#define SET_BE_16(_buf, _v)                                                     \
    do {                                                                        \
        ((uint8_t *)(_buf))[0] = (uint8_t)(((uint16_t)(_v) >> 8) & 0xFFUL);     \
        ((uint8_t *)(_buf))[1] = (uint8_t)(((uint16_t)(_v) >> 0) & 0xFFUL);     \
    } while (0)
#define GET_BE_16(_buf)     (uint16_t)                                          \
                            ( ((uint16_t)(((const uint8_t *)(_buf))[0]) << 8)   \
                            | ((uint16_t)(((const uint8_t *)(_buf))[1]) << 0) )
#define SET_BE_32(_buf, _v)                                                     \
    do {                                                                        \
        ((uint8_t *)(_buf))[0] = (uint8_t)(((uint32_t)(_v) >> 24) & 0xFFUL);    \
        ((uint8_t *)(_buf))[1] = (uint8_t)(((uint32_t)(_v) >> 16) & 0xFFUL);    \
        ((uint8_t *)(_buf))[2] = (uint8_t)(((uint32_t)(_v) >>  8) & 0xFFUL);    \
        ((uint8_t *)(_buf))[3] = (uint8_t)(((uint32_t)(_v) >>  0) & 0xFFUL);    \
    } while (0)
#define GET_BE_32(_buf)     ( ((uint32_t)(((const uint8_t *)(_buf))[0]) << 24)  \
                            | ((uint32_t)(((const uint8_t *)(_buf))[1]) << 16)  \
                            | ((uint32_t)(((const uint8_t *)(_buf))[2]) <<  8)  \
                            | ((uint32_t)(((const uint8_t *)(_buf))[3]) <<  0) )
#define SET_BE_64(_buf, _v)                                                     \
    do {                                                                        \
        ((uint8_t *)(_buf))[0] = (uint8_t)(((uint64_t)(_v) >> 56) & 0xFFULL);   \
        ((uint8_t *)(_buf))[1] = (uint8_t)(((uint64_t)(_v) >> 48) & 0xFFULL);   \
        ((uint8_t *)(_buf))[2] = (uint8_t)(((uint64_t)(_v) >> 40) & 0xFFULL);   \
        ((uint8_t *)(_buf))[3] = (uint8_t)(((uint64_t)(_v) >> 32) & 0xFFULL);   \
        ((uint8_t *)(_buf))[4] = (uint8_t)(((uint64_t)(_v) >> 24) & 0xFFULL);   \
        ((uint8_t *)(_buf))[5] = (uint8_t)(((uint64_t)(_v) >> 16) & 0xFFULL);   \
        ((uint8_t *)(_buf))[6] = (uint8_t)(((uint64_t)(_v) >>  8) & 0xFFULL);   \
        ((uint8_t *)(_buf))[7] = (uint8_t)(((uint64_t)(_v) >>  0) & 0xFFULL);   \
    } while (0)
#define GET_BE_64(_buf)     ( ((uint64_t)(((const uint8_t *)(_buf))[0]) << 56)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[1]) << 48)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[2]) << 40)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[3]) << 32)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[4]) << 24)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[5]) << 16)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[6]) <<  8)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[7]) <<  0) )

/* operate memory as little-endian */
#define SET_LE_16(_buf, _v)                                                     \
    do {                                                                        \
        ((uint8_t *)(_buf))[1] = (uint8_t)(((uint16_t)(_v) >> 8) & 0xFFUL);     \
        ((uint8_t *)(_buf))[0] = (uint8_t)(((uint16_t)(_v) >> 0) & 0xFFUL);     \
    } while (0)
#define GET_LE_16(_buf)     (uint16_t)                                          \
                            ( ((uint16_t)(((const uint8_t *)(_buf))[1]) << 8)   \
                            | ((uint16_t)(((const uint8_t *)(_buf))[0]) << 0) )
#define SET_LE_32(_buf, _v)                                                     \
    do {                                                                        \
        ((uint8_t *)(_buf))[3] = (uint8_t)(((uint32_t)(_v) >> 24) & 0xFFUL);    \
        ((uint8_t *)(_buf))[2] = (uint8_t)(((uint32_t)(_v) >> 16) & 0xFFUL);    \
        ((uint8_t *)(_buf))[1] = (uint8_t)(((uint32_t)(_v) >>  8) & 0xFFUL);    \
        ((uint8_t *)(_buf))[0] = (uint8_t)(((uint32_t)(_v) >>  0) & 0xFFUL);    \
    } while (0)
#define GET_LE_32(_buf)     ( ((uint32_t)(((const uint8_t *)(_buf))[3]) << 24)  \
                            | ((uint32_t)(((const uint8_t *)(_buf))[2]) << 16)  \
                            | ((uint32_t)(((const uint8_t *)(_buf))[1]) <<  8)  \
                            | ((uint32_t)(((const uint8_t *)(_buf))[0]) <<  0) )
#define SET_LE_64(_buf, _v)                                                     \
    do {                                                                        \
        ((uint8_t *)(_buf))[7] = (uint8_t)(((uint64_t)(_v) >> 56) & 0xFFULL);   \
        ((uint8_t *)(_buf))[6] = (uint8_t)(((uint64_t)(_v) >> 48) & 0xFFULL);   \
        ((uint8_t *)(_buf))[5] = (uint8_t)(((uint64_t)(_v) >> 40) & 0xFFULL);   \
        ((uint8_t *)(_buf))[4] = (uint8_t)(((uint64_t)(_v) >> 32) & 0xFFULL);   \
        ((uint8_t *)(_buf))[3] = (uint8_t)(((uint64_t)(_v) >> 24) & 0xFFULL);   \
        ((uint8_t *)(_buf))[2] = (uint8_t)(((uint64_t)(_v) >> 16) & 0xFFULL);   \
        ((uint8_t *)(_buf))[1] = (uint8_t)(((uint64_t)(_v) >>  8) & 0xFFULL);   \
        ((uint8_t *)(_buf))[0] = (uint8_t)(((uint64_t)(_v) >>  0) & 0xFFULL);   \
    } while (0)
#define GET_LE_64(_buf)     ( ((uint64_t)(((const uint8_t *)(_buf))[7]) << 56)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[6]) << 48)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[5]) << 40)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[4]) << 32)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[3]) << 24)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[2]) << 16)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[1]) <<  8)  \
                            | ((uint64_t)(((const uint8_t *)(_buf))[0]) <<  0) )


#endif /* __BASE_MACRO_H */

