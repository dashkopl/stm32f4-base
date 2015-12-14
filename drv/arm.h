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
 *   arm.h
 * DESCRIPTION:
 *   N/A
 * HISTORY:
 *   2015.8.4        PANDA         Create
 *
 *****************************************************************************/

#ifndef __ARM_H
#define __ARM_H


#if (!defined(__cortex_m3__) && !defined(__cortex_m4__))
 #error "Only support Cortex-M3/M4 yet!"
#endif

#if defined(__GNUC__)
 /* note: these macros may be pre-defined by gcc */
 #ifndef __dead2
  #define __dead2               __attribute__((__noreturn__))
 #endif
 #ifndef __pure2
  #define __pure2               __attribute__((__const__))
 #endif
 #ifndef __unused
  #define __unused              __attribute__((__unused__))
 #endif
 #ifndef __used
  #define __used                __attribute__((__used__))
 #endif
 #ifndef __packed
  #define __packed              __attribute__((__packed__))
 #endif
 #ifndef __aligned
  #define __aligned(x)          __attribute__((__aligned__(x)))
 #endif
 #ifndef __section
  #define __section(x)          __attribute__((__section__(x)))
 #endif
 #ifndef __noinline
  #define __noinline            __attribute__ (( noinline ))
 #endif
 #ifndef __naked
  #define __naked               __attribute__ (( naked ))
 #endif
 #ifndef __weak
  #define __weak                __attribute__ (( weak ))
 #endif
 #ifndef __alias
  #define __alias(s)            __attribute__ (( alias(s) ))
 #endif
 #ifndef __asm
  #define __asm(args...)        __asm__ __volatile__ (args)
 #endif
#elif defined(lint)
 #define __attribute__(args...) /* empty */
 #define __dead2                /* empty */
 #define __pure2                /* empty */
 #define __unused               /* empty */
 #define __used                 /* empty */
 #define __packed               /* empty */
 #define __aligned(x)           /* empty */
 #define __section(x)           /* empty */
 #define __noinline             /* empty */
 #define __naked                /* empty */
 #define __weak                 /* empty */
 #define __alias(s)             /* empty */
 #define __asm(args...)         /* empty */
#else
 #error "Only support GCC compiler yet!"
#endif

/* bit-band alias address operation */
#define _BITBAND_ADDR(_addr, _bit)          (((uint32_t)(_addr) & 0xF0000000)       \
                                             + 0x2000000                            \
                                             + (((uint32_t)(_addr) & 0xFFFFF) << 5) \
                                             + ((uint8_t)(_bit) << 2))
#define BITBAND_WRITE_BIT(_addr, _bit, _v)  do { (VP32(_BITBAND_ADDR((_addr), (_bit)))) = ((uint8_t)(_v) & 0x1); } while (0)
#define BITBAND_READ_BIT(_addr, _bit)       (uint8_t)((VP32(_BITBAND_ADDR((_addr), (_bit)))) & 0x1)


#endif /* __ARM_H */

