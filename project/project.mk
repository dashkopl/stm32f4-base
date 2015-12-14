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

# libopencm3 related definition
OPENCM3_TOP_DIR     := U:/OpenSource/libopencm3
OPENCM3_INCLUDE_DIR	:= $(OPENCM3_TOP_DIR)/include
OPENCM3_LIB_DIR		:= $(OPENCM3_TOP_DIR)/lib
OPENCM3_SCRIPT_DIR	:= $(OPENCM3_TOP_DIR)/scripts

$(info libopencm3 library path: "$(OPENCM3_TOP_DIR)")

# add libopencm3 into project include path
PROJECT_INC     := $(OPENCM3_INCLUDE_DIR)
PROJECT_LIB_DIR := $(OPENCM3_LIB_DIR)
PROJECT_LIB     := $(OPENCM3_LIB_DIR)/libopencm3_stm32f4.a

# project options definition
PROJECT_OPTS = -DSTM32F4

