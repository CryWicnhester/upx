UDIR := $($(U)DIR)

ifneq ($(strip $(wildcard $(UDIR)/include)),) # { include
DEFS += -DWITH_$(U)
INCLUDES += -I$(UDIR)/include

ifeq ($(DEBUG),1)
ifneq ($(strip $(wildcard $(UDIR)/build/debug/src/.libs)),)
LIBDIRS += $(UDIR)/build/debug/src/.libs
endif
endif

ifneq ($(strip $(wildcard $(UDIR)/build/$(release)/src/.libs)),)
LIBDIRS += $(UDIR)/build/$(release)/src/.libs
else
ifneq ($(strip $(wildcard $(UDIR)/build/$(target)/src/.libs)),)
LIBDIRS += $(UDIR)/build/$(target)/src/.libs
else
ifneq ($(strip $(wildcard $(UDIR)/src/.libs)),)
LIBDIRS += $(UDIR)/src/.libs
else
ifneq ($(strip $(wildcard $(UDIR)/build/release/src/.libs)),)
LIBDIRS += $(UDIR)/build/release/src/.libs
else
ifneq ($(strip $(wildcard $(UDIR)/build/src/.libs)),)
LIBDIRS += $(UDIR)/build/src/.libs
else
ifneq ($(strip $(wildcard $(UDIR))),)
LIBDIRS += $(UDIR)
DOS_LIBDIRS := $(DOS_LIBDIRS);$(UDIR)
endif
endif
endif
endif
endif
endif

LDLIBS += -l$(u)
DOS_LDLIBS += $(u).lib


DEFS := $(DEFS)
INCLUDES := $(INCLUDES)
LIBDIRS := $(LIBDIRS)
LDLIBS := $(LDLIBS)
DOS_LDLIBS := $(DOS_LDLIBS)

endif # } include