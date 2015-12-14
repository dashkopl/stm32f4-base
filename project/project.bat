:: ############################################################################
::
:: Copyright (C) 2015 Panda.Xiong <yaxi1984@gmail.com>
::
:: This library is free software: you can redistribute it and/or modify
:: it under the terms of the GNU Lesser General Public License as published by
:: the Free Software Foundation, either version 3 of the License, or
::  (at your option) any later version.
:: 
::  This library is distributed in the hope that it will be useful,
::  but WITHOUT ANY WARRANTY; without even the implied warranty of
::  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
::  GNU Lesser General Public License for more details.
:: 
::  You should have received a copy of the GNU Lesser General Public License
::  along with this library.  If not, see <http://www.gnu.org/licenses/>.
::
:: History:
::    2015.08.02    Panda.Xiong       Create
::
:: ############################################################################

@echo off

:: ============================================================================
::  +++ Porting Area Start +++
:: ============================================================================

:: set project related parameters
set CPU_ARCH=cortex-m4
set CPU_TYPE=stm32f407ve
set CPU_ENDIAN=little

:: ============================================================================
::  --- Porting Area End ---
:: ============================================================================

:: set project name as current directory name
for %%i in ("%CD%") do set PROJECT_NAME=%%~ni

:: set compiler base path
if "%COMPILER_BASE%" == "" (
  set COMPILER_BASE=D:\compiler
)

:: add base tools & project compiler search path
path %CD%\!tools\bin;U:\Programs\ST-Link\ST-LINK_Utility
path %COMPILER_BASE%\gcc-arm-none-eabi-4_9-2015q2-20150609-win32\bin;%PATH%
path %COMPILER_BASE%\bin;%PATH%

:: set title & clear screen
title %PROJECT_NAME%
cls

:: display the supported commands.
echo.
echo   Available Commands :
echo  ******************************************************************************
echo   make         : Compile, and build the firmware.
echo   make clean   : Clean the compiled objects/firmware.
echo   make install : Install the compiled firmware into DUT.
echo  ******************************************************************************
echo.

:: ============================================================================
