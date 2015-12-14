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

# set makefile name
MAKEFILE_NAME = Makefile

#==============================================================================

# current directory
CURRENT_DIR := $(subst \,/,$(shell pwd))

# final build directory
BUILD_DIR := $(TOP_DIR)/build
OBJ_DIR   := $(BUILD_DIR)/obj
LIB_DIR   := $(BUILD_DIR)/lib
IMAGE_DIR := $(BUILD_DIR)/image

#==============================================================================

include $(PROJECT_DIR)/project.mk
include $(CFG_DIR)/arch.mk

#==============================================================================

ECHO    = echo
CAT     = cat
CP      = cp
MV      = mv -f
RM		= rm -f
MKDIR	= mkdir -p
MAKE    = make
SIGN    = sign
USAGE   = calc_usage

#==============================================================================

# USER_OPTS : user options and include path
#USER_OPTS  =
#USR_INC    =

# project include path, this will send to all sub-directories
#PROJECT_INC =

# all include path
ALL_INC	= $(USR_INC) $(PROJECT_INC)

#==============================================================================

# options used for *.S files
AFLAGS = $(strip $(CPU_OPTS) $(PROJECT_OPTS) $(USER_OPTS) $(addprefix -I,$(sort $(ALL_INC))))

# options used for *.c files
CFLAGS = $(strip $(CPU_OPTS) $(PROJECT_OPTS) $(USER_OPTS) $(addprefix -I,$(sort $(ALL_INC))))

#==============================================================================
