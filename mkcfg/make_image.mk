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

# all libraries & targets with path
ALL_LIBS     := $(wildcard $(LIB_DIR)/*.a) $(PROJECT_LIB)
ALL_LIBS_DIR := $(LIB_DIR) $(PROJECT_LIB_DIR)
ALL_TARGETS  := $(addprefix $(IMAGE_DIR)/$(PROJECT_NAME).,$(ALL_TARGETS))

###############################################################################

# options for linker
LD_FLAGS += -T $(PROJECT_DIR)/$(CPU_TYPE).ld                                  \
            -Wl,--start-group                                                 \
              $(addprefix -l,$(subst lib,,$(notdir $(basename $(ALL_LIBS))))) \
            -Wl,--end-group                                                   \
            $(addprefix -L,$(ALL_LIBS_DIR))                                   \
            -Wl,-Map=$(IMAGE_DIR)/$(PROJECT_NAME).map                         \
            -Wl,--output=$(IMAGE_DIR)/$(PROJECT_NAME).elf

###############################################################################

.PHONY : all clean build_start build_end

#******************************************************************************

all : build_start
all : $(ALL_TARGETS)
all : build_end

#******************************************************************************

clean :
	-$(RM) $(ALL_TARGETS)

#******************************************************************************

%.map %.elf : $(ALL_LIBS)
	$(CC) $(CFLAGS) $(strip $(LD_FLAGS))

#******************************************************************************

%.bin : %.elf
	$(OBJCOPY) -O binary $< $@

#******************************************************************************

%.hex : %.elf
	$(OBJCOPY) -O ihex $< $@

#******************************************************************************

%.lss : %.elf
	$(OBJDUMP) -h -S $< > $@

#******************************************************************************

%.sym : %.elf
	$(NM) -n -S $< > $@

#******************************************************************************

%.size : %.elf
	$(SIZE) -A -x $< > $@

#******************************************************************************

build_start :

build_end :
	$(CAT) $(IMAGE_DIR)/$(PROJECT_NAME).size

###############################################################################
