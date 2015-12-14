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

# add current directory to source and header file search path
USR_INC  += $(CURRENT_DIR)
SRC_DIR  += $(CURRENT_DIR)

# if no ASM object file assigned,
# it will auto scan .S source files, to get the corresponding object files.
ifeq (0,$(words $(A_OBJS)))
  ALL_A_SRCS := $(foreach dir,$(SRC_DIR),$(notdir $(wildcard $(dir)/*.S)))
  A_SRCS     := $(filter-out $(EXCLUDES),$(ALL_A_SRCS))
  A_OBJS     := $(patsubst %.S,%.o,$(filter %.S,$(A_SRCS)))
endif

# if no c/cpp/C object file assigned,
# it will auto scan .c source files, to get the corresponding object files.
ifeq (0,$(words $(C_OBJS)))
  ALL_C_SRCS := $(foreach dir,$(SRC_DIR),$(notdir $(wildcard $(dir)/*.c)))
  C_SRCS     := $(filter-out $(EXCLUDES),$(ALL_C_SRCS))
  C_OBJS     := $(patsubst %.c,%.o,$(filter %.c,$(C_SRCS)))
endif

ALL_OBJS     := $(addprefix $(OBJ_DIR)/,$(A_OBJS) $(C_OBJS))
ALL_LIBS     := $(addprefix $(LIB_DIR)/,$(LIB))

###############################################################################

# file searching path
vpath %.S   $(SRC_DIR)
vpath %.c   $(SRC_DIR)
vpath %.h   $(ALL_INC)

###############################################################################

# include dependencies
sinclude $(patsubst %.o,%.d,$(ALL_OBJS))

#==============================================================================

.PHONY : all clean build_start build_end $(SUB_DIR)

#==============================================================================

all : build_start
all : $(SUB_DIR) $(ALL_OBJS) $(ALL_LIBS)
all : build_end

#==============================================================================

clean :
ifneq (0,$(words $(SUB_DIR)))
	@for i in $(SUB_DIR);                                                     \
	do                                                                        \
		$(MAKE) -f $(MAKEFILE_NAME) -C $$i $@;                                \
	done
endif
ifneq (0,$(words $(ALL_OBJS)))
	-$(RM) $(ALL_OBJS)
endif
ifneq (0,$(words $(ALL_LIBS)))
	-$(RM) $(ALL_LIBS)
endif
ifeq ($(CURRENT_DIR),$(TOP_DIR))
	-$(RM) -r $(BUILD_DIR)
endif

###############################################################################

$(SUB_DIR) :
	@$(MAKE) -f $(MAKEFILE_NAME) -C $@ all

#==============================================================================

$(OBJ_DIR)/%.o : %.S
	$(CC) -MM $(AFLAGS) $< -MP -MT $@ -MF $(@:.o=.d)
	$(CC) -E $(AFLAGS) $< -o $(@:.o=.i)
	$(CC) -c $(AFLAGS) $< -o $@

$(OBJ_DIR)/%.o : %.c
	$(CC) -MM $(CFLAGS) $< -MP -MT $@ -MF $(@:.o=.d)
	$(CC) -E $(CFLAGS) $< -o $(@:.o=.i)
	$(CC) -c $(CFLAGS) $< -o $@

$(LIB_DIR)/%.a : $(ALL_OBJS)
	$(AR) $(ARFLAG) $@ $^

#******************************************************************************

build_start :
ifeq ($(CURRENT_DIR),$(TOP_DIR))
	-$(MKDIR) $(OBJ_DIR)
	-$(MKDIR) $(LIB_DIR)
	-$(MKDIR) $(IMAGE_DIR)
endif

build_end :

###############################################################################
