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
 *   drv_io.c
 * DESCRIPTION:
 *   N/A
 * HISTORY:
 *   2015.8.4        PANDA         Create
 *
 *****************************************************************************/

#include "drv.h"


/******************************************************************************
 * FUNCTION NAME:
 *      DRV_IO_Init
 * DESCRIPTION:
 *      IO Driver Init.
 * PARAMETERS:
 *      N/A
 * RETURN:
 *      N/A
 * NOTES:
 *      N/A
 * HISTORY:
 *      2015.8.5        PANDA         Create
 *****************************************************************************/
void DRV_IO_Init(void)
{
    rcc_periph_clock_enable(RCC_GPIOA);

#define DECLARE_IO(_name, _io, _mode, _dir, _init, _desc)                   \
    do                                                                      \
    {                                                                       \
        DRV_IO_SetMode(IO(_name), (_mode));                                 \
        DRV_IO_Write(IO(_name), (_init));                                   \
        DRV_IO_SetDirection(IO(_name), (_dir));                             \
    } while (0);

#include "cfg_hw_def.h"

#undef DECLARE_IO
}

