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
 *   drv_rcc.c
 * DESCRIPTION:
 *   RCC(Reset and clock control) related.
 * HISTORY:
 *   2015.8.4        PANDA         Create
 *
 *****************************************************************************/

#include "drv.h"
#include "libopencm3/stm32/rcc.h"


static void drv_rcc_SetupClock(void)
{
  #if (CPU_CORE_CLOCK == 48000000UL)

   #if (CPU_OSC_FREQUENCY == 8000000UL)
    rcc_clock_setup_hse_3v3(&hse_8mhz_3v3[CLOCK_3V3_48MHZ]);
   #elif (CPU_OSC_FREQUENCY == 12000000UL)
    rcc_clock_setup_hse_3v3(&hse_12mhz_3v3[CLOCK_3V3_48MHZ]);
   #elif (CPU_OSC_FREQUENCY == 16000000UL)
    rcc_clock_setup_hse_3v3(&hse_16mhz_3v3[CLOCK_3V3_48MHZ]);
   #elif (CPU_OSC_FREQUENCY == 25000000UL)
    rcc_clock_setup_hse_3v3(&hse_25mhz_3v3[CLOCK_3V3_48MHZ]);
   #else
    #error "Unsupported OSC Frequency!"
   #endif

  #elif (CPU_CORE_CLOCK == 84000000UL)

   #if (CPU_OSC_FREQUENCY == 8000000UL)
    rcc_clock_setup_hse_3v3(&hse_8mhz_3v3[CLOCK_3V3_84MHZ]);
   #elif (CPU_OSC_FREQUENCY == 12000000UL)
    rcc_clock_setup_hse_3v3(&hse_12mhz_3v3[CLOCK_3V3_84MHZ]);
   #elif (CPU_OSC_FREQUENCY == 16000000UL)
    rcc_clock_setup_hse_3v3(&hse_16mhz_3v3[CLOCK_3V3_84MHZ]);
   #elif (CPU_OSC_FREQUENCY == 25000000UL)
    rcc_clock_setup_hse_3v3(&hse_25mhz_3v3[CLOCK_3V3_84MHZ]);
   #else
    #error "Unsupported OSC Frequency!"
   #endif

  #elif (CPU_CORE_CLOCK == 120000000UL)
   #if (CPU_OSC_FREQUENCY == 8000000UL)
    rcc_clock_setup_hse_3v3(&hse_8mhz_3v3[CLOCK_3V3_120MHZ]);
   #elif (CPU_OSC_FREQUENCY == 12000000UL)
    rcc_clock_setup_hse_3v3(&hse_12mhz_3v3[CLOCK_3V3_120MHZ]);
   #elif (CPU_OSC_FREQUENCY == 16000000UL)
    rcc_clock_setup_hse_3v3(&hse_16mhz_3v3[CLOCK_3V3_120MHZ]);
   #elif (CPU_OSC_FREQUENCY == 25000000UL)
    rcc_clock_setup_hse_3v3(&hse_25mhz_3v3[CLOCK_3V3_120MHZ]);
   #else
    #error "Unsupported OSC Frequency!"
   #endif

  #elif (CPU_CORE_CLOCK == 168000000UL)

   #if (CPU_OSC_FREQUENCY == 8000000UL)
    rcc_clock_setup_hse_3v3(&hse_8mhz_3v3[CLOCK_3V3_168MHZ]);
   #elif (CPU_OSC_FREQUENCY == 12000000UL)
    rcc_clock_setup_hse_3v3(&hse_12mhz_3v3[CLOCK_3V3_168MHZ]);
   #elif (CPU_OSC_FREQUENCY == 16000000UL)
    rcc_clock_setup_hse_3v3(&hse_16mhz_3v3[CLOCK_3V3_168MHZ]);
   #elif (CPU_OSC_FREQUENCY == 25000000UL)
    rcc_clock_setup_hse_3v3(&hse_25mhz_3v3[CLOCK_3V3_168MHZ]);
   #else
    #error "Unsupported OSC Frequency!"
   #endif

  #else
    #error "Unsupported Core Frequency!"
  #endif
}


/******************************************************************************
 * FUNCTION NAME:
 *      DRV_RCC_Init
 * DESCRIPTION:
 *      Init RCC.
 * PARAMETERS:
 *      N/A
 * RETURN:
 *      N/A
 * NOTES:
 *      N/A
 * HISTORY:
 *      2015.8.4        PANDA         Create
 *****************************************************************************/
void DRV_RCC_Init(void)
{
    drv_rcc_SetupClock();
}

