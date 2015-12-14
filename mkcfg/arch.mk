###############################################################################
#
# Copyright (C) 2015 Panda.Xiong <yaxi1984@gmail.com>
#
# This library is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
# 
#  This library is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Lesser General Public License for more details.
# 
#  You should have received a copy of the GNU Lesser General Public License
#  along with this library.  If not, see <http://www.gnu.org/licenses/>.
#
# History:
#    2015.08.02    Panda.Xiong       Create
#
###############################################################################

ifeq (cortex-m4,$(CPU_ARCH))
  # set project compiler
  export CROSS_COMPILE_PREFIX := arm-none-eabi-

  # cpu option
  CPU_OPTS = -mcpu=$(CPU_ARCH) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16
else
  $(error "Unsupport cpu architecture!")
endif

# Cross compiler define
CC        = $(CROSS_COMPILE_PREFIX)gcc
CXX       = $(CROSS_COMPILE_PREFIX)g++
LD        = $(CROSS_COMPILE_PREFIX)ld
AR        = $(CROSS_COMPILE_PREFIX)gcc-ar
AS        = $(CROSS_COMPILE_PREFIX)as
RANLIB    = $(CROSS_COMPILE_PREFIX)gcc-ranlib
NM        = $(CROSS_COMPILE_PREFIX)nm
OBJCOPY   = $(CROSS_COMPILE_PREFIX)objcopy
OBJDUMP   = $(CROSS_COMPILE_PREFIX)objdump
STRIP     = $(CROSS_COMPILE_PREFIX)strip
SIZE      = $(CROSS_COMPILE_PREFIX)size

#===============================================================================

CPU_OPTS += -g -std=c99 -O2 -m$(CPU_ENDIAN)-endian                             \
            -D__$(subst -,_,$(CPU_ARCH))__                                     \
            -D__$(CPU_TYPE)__                                                  \
            -D__$(CPU_ENDIAN)_endian__

# -Wall turns on the following warning flags:
#    -Waddress
#    -Warray-bounds (only with -O2)
#    -Wc++0x-compat
#    -Wchar-subscripts
#    -Wenum-compare (in C/Objc; this is on by default in C++)
#    -Wimplicit-int
#    -Wimplicit-function-declaration
#    -Wcomment
#    -Wformat
#    -Wmain (only for C/ObjC and unless -ffreestanding)
#    -Wmissing-braces
#    -Wnonnull
#    -Wparentheses
#    -Wpointer-sign
#    -Wreorder
#    -Wreturn-type
#    -Wsequence-point
#    -Wsign-compare (only in C++)
#    -Wstrict-aliasing
#    -Wstrict-overflow=1
#    -Wswitch
#    -Wtrigraphs
#    -Wuninitialized
#    -Wunknown-pragmas
#    -Wunused-function
#    -Wunused-label
#    -Wunused-value
#    -Wunused-variable
#    -Wvolatile-register-var
#
# -Wextra
#   This enables some extra warning flags that are not enabled by -Wall.
#   (This option used to be called -W. The older name is still supported,
#   but the newer name is more descriptive.)
#    -Wclobbered
#    -Wempty-body
#    -Wignored-qualifiers
#    -Wmissing-field-initializers
#    -Wmissing-parameter-type (C only)
#    -Wold-style-declaration (C only)
#    -Woverride-init
#    -Wsign-compare
#    -Wtype-limits
#    -Wuninitialized
#    -Wunused-parameter (only with -Wunused or -Wall)
#
# for more details:
# see  http://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#Warning-Options
CPU_OPTS += -funsigned-char -funsigned-bitfields -flto                         \
            -Wall -Wpointer-arith -Wstrict-prototypes -Winline -Wundef

# use more strict compiling rule
CPU_OPTS += -W -Wfloat-equal -Wshadow -Wbad-function-cast -Wcast-qual          \
            -Wcast-align -Waggregate-return -Wpacked -Wwrite-strings

# treat all warning as error
CPU_OPTS += -Werror

#==============================================================================

# options used for *.a files
ARFLAG = -crv

# options used for linker
LD_FLAGS = -nostartfiles -Wl,--gc-sections                                     \
           --specs=nano.specs --specs=nosys.specs

#==============================================================================
