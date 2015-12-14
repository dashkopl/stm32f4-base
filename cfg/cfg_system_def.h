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
 *   cfg_system_def.h
 * DESCRIPTION:
 *   Product system definition configuration:
 *    -> Set to 1, enable  this driver/function;
 *    -> Set to 0, disable this driver/function;
 * HISTORY:
 *   2015.8.4        PANDA         Create
 *
 *****************************************************************************/

#ifndef __CFG_SYSTEM_DEF_H
#define __CFG_SYSTEM_DEF_H


#define NA              0
#define NO_COOKIE       0

/* Target CPU Definition */
#define CPU_TYPE                    "STM32F407VET6"

/* CPU Clock */
#define CPU_OSC_FREQUENCY           25000000UL  /* Hz */
#define CPU_CORE_CLOCK              168000000UL /* Hz */

/* Peripherals Driver */
#define DRV_UART_SUPPORT            1   /* UART                 */
 #define DRV_UART_BAUDRATE          115200UL    /* bps */
#define DRV_WATCHDOG_SUPPORT        0   /* Watchdog             */
#define DRV_VECTOR_SUPPORT          0   /* Vector               */
#define DRV_EXCEPTION_SUPPORT       0   /* Exception            */
#define DRV_DMA_SUPPORT             0   /* DMA                  */
#define DRV_FLASH_SUPPORT           0   /* Flash                */
#define DRV_TIMER_SUPPORT           0   /* Timer                */
#define DRV_SWI_SUPPORT             0   /* SWI                  */
#define DRV_I2CM_SUPPORT            0   /* I2C Master           */
 #define DRV_I2CM_RATE              400 /* I2C Master Rate: 80/100/200/400KHz */
#define DRV_SPIM_SUPPORT            0   /* SPI Master           */
 #define DRV_SPIM_RATE              20  /* SPI Master Rate: 1/2/4/8/12/20MHz */
#define DRV_PWM_SUPPORT             0   /* PWM                  */
#define DRV_VREF_SUPPORT            0   /* Voltage Reference    */
#define DRV_ADC_SUPPORT             0   /* ADC                  */
#define DRV_DAC_SUPPORT             0   /* DAC                  */
#define DRV_EPP_SUPPORT             0   /* EPP                  */
#define DRV_TEMP_SUPPORT            0   /* Temperature Sensor   */
 #define DRV_TEMP_DS18B20_SUPPORT   (0 && DRV_TEMP_SUPPORT) /* DS18B20 */

/* Miscellaneous */
#define SYSTEM_TICK_SUPPORT         0   /* System Tick Timer    */
#define STACK_CHECK_SUPPORT         0   /* Stack Check          */
#define STDIO_SUPPORT               0   /* Standard IO          */
#define CLI_SUPPORT                 0   /* CLI                  */


#endif /* __CFG_SYSTEM_DEF_H */

