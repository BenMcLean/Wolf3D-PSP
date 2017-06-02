TARGET = wolf3d
OBJS = 	Src/automap.o \
		Src/ff_psp.o \
		Src/id_ca.o \
		Src/id_us.o \
		Src/id_vh.o \
		Src/misc.o \
		Src/objs.o \
		Src/fmopl.o \
		Src/vi_comm.o \
		Src/vi_sdl.o \
		Src/wl_act1.o \
		Src/wl_act2.o \
		Src/wl_act3.o \
		Src/wl_agent.o \
		Src/wl_debug.o \
		Src/sd_comm.o \
		Src/sd_sdl.o \
		Src/wl_draw.o \
		Src/wl_game.o \
		Src/wl_inter.o \
		Src/wl_main.o \
		Src/wl_menu.o \
		Src/wl_play.o \
		Src/wl_state.o \
		Src/wl_text.o \
		Src/pspDveManager.o \

CFLAGS = -O1 -G0 -Wall -g -DHAVE_FFBLK -DDOSISM
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LIBS = -L/usr/local/pspsdk/lib
LDFLAGS =

BUILD_PRX = 1
PSP_FW_VERSION = 401
PSP_LARGE_MEMORY = 1

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Wolfenstein 3D
#PSP_EBOOT_TITLE = Wolfenstein 3D Shareware
#PSP_EBOOT_TITLE = Spear of Destiny
#PSP_EBOOT_TITLE = Spear of Destiny Episode 2
#PSP_EBOOT_TITLE = Spear of Destiny Episode 3
#PSP_EBOOT_TITLE = Spear of Destiny Shareware

PSPSDK=$(shell psp-config --pspsdk-path)
PSPBIN = $(PSPSDK)/../bin
CFLAGS += $(shell $(PSPBIN)/sdl-config --cflags)
LIBS += $(shell $(PSPBIN)/sdl-config --libs)
include $(PSPSDK)/lib/build.mak
