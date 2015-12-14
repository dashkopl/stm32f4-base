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
 *   cfg_hw_def.h
 * DESCRIPTION:
 *   Product hardware definition.
 * HISTORY:
 *   2015.8.4        PANDA         Create
 *
 *****************************************************************************/


#ifdef DECLARE_IO

/*          Name                    IO        Mode          Direction               Init    Description */

/* PORT A */
DECLARE_IO(IO_PA0,                _IO(PA0),  MODE_IO,      IO_OUTPUT_PUSHPULL,      LOW,    "")
DECLARE_IO(IO_TEC_SW1_OUT,        _IO(P0.1), MODE_IO,      IO_OUTPUT_PUSHPULL,      LOW,    "")
DECLARE_IO(IO_RXCDR_LOL_IN,       _IO(P0.2), MODE_PLA,     IO_INPUT_PULLUP_ENABLE,  LOW,    "")
DECLARE_IO(IO_RXCDR_LOS_IN,       _IO(P0.3), MODE_PLA,     IO_INPUT_PULLUP_ENABLE,  LOW,    "")
DECLARE_IO(IO_TXCDR_RSTn_OUT,     _IO(P0.4), MODE_IO,      IO_OUTPUT_PUSHPULL,      LOW,    "")
DECLARE_IO(IO_RXCDR_RSTn_OUT,     _IO(P0.5), MODE_IO,      IO_OUTPUT_PUSHPULL,      LOW,    "")
DECLARE_IO(IO_RXPWR_EN_OUT,       _IO(P0.6), MODE_IO,      IO_OUTPUT_PUSHPULL,      LOW,    "")
DECLARE_IO(IO_RXLOS_OUT,          _IO(P0.7), MODE_PLA,     IO_INPUT_PULLUP_ENABLE,  LOW,    "")

/* PORT 1 */
DECLARE_IO(UART_RXD,              _IO(P1.0), MODE_AUX1,    IO_INPUT_PULLUP_ENABLE,  HIGH,   "")
DECLARE_IO(UART_TXD,              _IO(P1.1), MODE_AUX1,    IO_INPUT_PULLUP_ENABLE,  HIGH,   "")
DECLARE_IO(IO_TEC_EN_OUT,         _IO(P1.2), MODE_IO,      IO_OUTPUT_PUSHPULL,      LOW,    "")
DECLARE_IO(IO_PWR_EN_OUT,         _IO(P1.3), MODE_IO,      IO_OUTPUT_PUSHPULL,      LOW,    "")
DECLARE_IO(I2CM_SCL,              _IO(P1.4), MODE_IO,      IO_OUTPUT_OPENDRAIN,     HIGH,   "")
DECLARE_IO(I2CM_SDA,              _IO(P1.5), MODE_IO,      IO_OUTPUT_OPENDRAIN,     HIGH,   "")
DECLARE_IO(IO_LD_DIS_OUT,         _IO(P1.6), MODE_IO,      IO_OUTPUT_PUSHPULL,      HIGH,   "")
DECLARE_IO(IO_TXPWR_EN_OUT,       _IO(P1.7), MODE_IO,      IO_OUTPUT_PUSHPULL,      LOW,    "")

/* PORT 2 */
DECLARE_IO(IO_TXCDR_DIS_OUT,      _IO(P2.0), MODE_IO,      IO_OUTPUT_PUSHPULL,      HIGH,   "")
DECLARE_IO(IO_Reserved_P2_1,      _IO(P2.1), MODE_IO,      IO_INPUT_PULLUP_ENABLE,  HIGH,   "")
DECLARE_IO(IO_TXCDR_LOSL_IN,      _IO(P2.2), MODE_IO,      IO_INPUT_PULLUP_ENABLE,  HIGH,   "")
DECLARE_IO(IO_VND_IO_C,           _IO(P2.3), MODE_IO,      IO_INPUT_PULLUP_ENABLE,  HIGH,   "")
DECLARE_IO(IO_TXDIS_IN,           _IO(P2.4), MODE_IRQ,     IO_INPUT_PULLUP_ENABLE,  HIGH,   "")
DECLARE_IO(IO_Reserved_P2_5,      _IO(P2.5), MODE_IO,      IO_INPUT_PULLUP_ENABLE,  HIGH,   "")
DECLARE_IO(IO_MODLOPWR_IN,        _IO(P2.6), MODE_IRQ,     IO_INPUT_PULLUP_ENABLE,  HIGH,   "")
DECLARE_IO(IO_MODRSTn_IN,         _IO(P2.7), MODE_IRQ,     IO_INPUT_PULLUP_ENABLE,  HIGH,   "")

/* PORT 3 */
DECLARE_IO(MDIO_PORTADDR0_IN,     _IO(P3.0), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")
DECLARE_IO(MDIO_PORTADDR1_IN,     _IO(P3.1), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")
DECLARE_IO(MDIO_PORTADDR2_IN,     _IO(P3.2), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")
DECLARE_IO(IO_DRIVER_EN_OUT,      _IO(P3.3), MODE_IO,      IO_OUTPUT_PUSHPULL,      LOW,    "")
DECLARE_IO(IO_Reserved_P3_4,      _IO(P3.4), MODE_IO,      IO_INPUT_PULLUP_ENABLE,  HIGH,   "")
DECLARE_IO(MDIO_MDC_IN,           _IO(P3.5), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")
DECLARE_IO(MDIO_MDIO_IN,          _IO(P3.6), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")
DECLARE_IO(IO_GLBALRMn_OUT,       _IO(P3.7), MODE_IO,      IO_OUTPUT_PUSHPULL,      HIGH,   "")

/* PORT 4 */
DECLARE_IO(ADC_RXPWR_CH0,         _IO(P4.2), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")
DECLARE_IO(ADC_RXPWR_CH3,         _IO(P4.3), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")
DECLARE_IO(ADC_TXPWR_CH3,         _IO(P4.4), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")
DECLARE_IO(ADC_TXPWR_CH2,         _IO(P4.5), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")
DECLARE_IO(ADC_TXPWR_CH1,         _IO(P4.6), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")
DECLARE_IO(ADC_TXPWR_CH0,         _IO(P4.7), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")

/* PORT 5 */
DECLARE_IO(DAC_LDTEMPSet_Fine,    _IO(P5.0), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")
DECLARE_IO(DAC_VG1,               _IO(P5.1), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")
DECLARE_IO(DAC_DRV_ADJ,           _IO(P5.2), MODE_AUX1,    IO_INPUT_PULLUP_DISABLE, HIGH,   "")
DECLARE_IO(IO_Reserved_P2_3,      _IO(P5.3), MODE_IO,      IO_INPUT_PULLUP_ENABLE,  HIGH,   "")

#endif
