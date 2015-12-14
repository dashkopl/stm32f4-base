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
 *   drv_int.h
 * DESCRIPTION:
 *   N/A
 * HISTORY:
 *   2015.8.4        PANDA         Create
 *
 *****************************************************************************/

#ifndef __DRV_INT_H
#define __DRV_INT_H


/* enable/disable global interrupt */
#define DRV_INT_GlobalEnableInterrupt()     __enable_irq()
#define DRV_INT_GlobalDisableInterrupt()    __disable_irq()

/* lock/unlock global interrupt */
#define DRV_INT_LockGlobalInterrupt()       (DRV_INT_IsGlobalInterruptLocked()? TRUE : (DRV_INT_GlobalDisableInterrupt(), FALSE))
#define DRV_INT_UnlockGlobalInterrupt(_s)   __set_PRIMASK(_s)
#define DRV_INT_IsGlobalInterruptLocked()   (__get_PRIMASK() == 1)


#endif /* __DRV_INT_H */

