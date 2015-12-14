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

include $(CFG_DIR)/config.mk

#==============================================================================

# The Makefile will auto-search all sub-directories under current directory,
#  if the directory contains a fixed Makefile name, defined in MAKEFILE_NAME,
#  it will be added into sub-directory list to be build.
SUB_DIR := $(sort $(patsubst %/,%,$(dir $(wildcard $(CURRENT_DIR)/*/$(MAKEFILE_NAME)))))

#==============================================================================

LIB	      := libapp.a

#==============================================================================

SRC_DIR   := 

#==============================================================================

# User options and include path
USER_OPTS :=
USR_INC   :=

#==============================================================================

# If the A_OBJS is empty, auto scan all *.S files,
# If the C_OBJS is empty, auto scan all *.c files,
# If A_OBJS is not empty, use the specified *.S files in A_OBJS,
# If C_OBJS is not empty, use the specified *.c files in C_OBJS,
#  to compile.
#
# All the source files will be searched from the specified directorys 
#  lists in SRC_DIR.
# By default, the current directory of Makefile is included,
#  and no need to specified in SRC_DIR.
A_OBJS    :=
C_OBJS    :=

# If you do not want some source files to be compiled, list here.
# This is only valid, while one of A_OBJS/C_OBJS is empty.
EXCLUDES  :=

#==============================================================================

include $(CFG_DIR)/make_target.mk

###############################################################################

