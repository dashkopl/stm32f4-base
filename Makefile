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

# set other directory, used by makefile
export TOP_DIR     := $(subst \,/,$(shell pwd))
export CFG_DIR     := $(TOP_DIR)/mkcfg
export PROJECT_DIR := $(TOP_DIR)/project

include $(CFG_DIR)/config.mk

# For "make release" command, add _RELEASE_ definition to compiler flags.
ifeq (release,$(MAKECMDGOALS))
 export PROJECT_OPTS += -D_RELEASE_
endif

#==============================================================================

# The Makefile will auto-search all sub-directories under current directory,
#  if the directory contains a fixed Makefile name, defined in MAKEFILE_NAME,
#  it will be added into sub-directory list to be build.
SUB_DIR := $(sort $(patsubst %/,%,$(dir $(wildcard $(CURRENT_DIR)/*/$(MAKEFILE_NAME)))))

# Scan all sub-directories which contains .c/.h files under current directory,
#  maximum sub-directories depth 16.
EXCLUDE_DIR := $(CURRENT_DIR)/.svn                   \
               $(CURRENT_DIR)/.git                   \
               $(CURRENT_DIR)/!tools                 \
               $(CURRENT_DIR)/build                  \
               $(CURRENT_DIR)/doc                    \
               $(CURRENT_DIR)/mkcfg
INC_DIR := $(dir $(shell find $(CURRENT_DIR) -name '*.[ch]' -depth -maxdepth 3 -type f))
INC_DIR := $(sort $(patsubst %/,%,$(subst \,/,$(INC_DIR))))
INC_DIR := $(filter-out $(EXCLUDE_DIR),$(INC_DIR))

#==============================================================================

# Project include path, this will send to all sub-directories listed in SUB_DIR.
export PROJECT_INC += $(INC_DIR)

#==============================================================================

include $(CFG_DIR)/make_target.mk

###############################################################################

install: $(IMAGE_DIR)/$(PROJECT_NAME).bin
	ST-LINK_CLI -c SWD LPM -P $< 0x08000000 -V after_programming -Run

###############################################################################

