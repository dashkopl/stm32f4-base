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
 *   compiler_porting.h
 * DESCRIPTION:
 *   N/A
 * HISTORY:
 *   2015.8.4        PANDA         Create
 *
 *****************************************************************************/

#ifndef __COMPILER_PORTING_H
#define __COMPILER_PORTING_H


#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>
#include "arm.h"


#define NOP()           __NOP()

/* Converts a bit number into a byte value */
#define _BV(b)          (1UL << (b))

/* ROL: Left Roll-Shift for data;
 * ROR: Right Roll-Shift for data;
 */
#define ROL(v, n)       do { (v) = (((v) << (n)) | ((v) >> (8*sizeof(v)-(n)))); } while (0)
#define ROR(v, n)       do { (v) = (((v) >> (n)) | ((v) << (8*sizeof(v)-(n)))); } while (0)

/* Swap data:  Big-Endian  <-->  Little-Endian */
#define SWAP_16(x)      (uint16_t)(__REV16((uint16_t)(x)))
#define SWAP_32(x)      (uint32_t)(__REV((uint32_t)(x)))
#define SWAP_64(x)      (uint64_t)(SWAP_32((uint64_t)(x)>>32) | SWAP_32((uint64_t)(x)<<32))

#define __ram           __section(".data")
#define __code          const


#endif /* __COMPILER_PORTING_H */

