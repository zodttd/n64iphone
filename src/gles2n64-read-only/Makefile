#/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
# *   Mupen64plus - Makefile                                                *
# *   Mupen64Plus homepage: http://code.google.com/p/mupen64plus/           *
# *   Copyright (C) 2007-2008 DarkJeztr Tillin9 Richard42                   *
# *                                                                         *
# *   This program is free software; you can redistribute it and/or modify  *
# *   it under the terms of the GNU General Public License as published by  *
# *   the Free Software Foundation; either version 2 of the License, or     *
# *   (at your option) any later version.                                   *
# *                                                                         *
# *   This program is distributed in the hope that it will be useful,       *
# *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
# *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
# *   GNU General Public License for more details.                          *
# *                                                                         *
# *   You should have received a copy of the GNU General Public License     *
# *   along with this program; if not, write to the                         *
# *   Free Software Foundation, Inc.,                                       *
# *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
# Makefile for glN64 in Mupen64plus.

ARCH = ARM
OS = LINUX

#SO_EXTENSION = dll
#CXX = 	C:/MinGW/bin/g++
#LD = 	C:/MinGW/bin/g++
#STRIP = C:/MinGW/bin/strip

SO_EXTENSION = dylib
CXX = 	/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/arm-apple-darwin9-g++-4.2.1
LD = 	/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/arm-apple-darwin9-g++-4.2.1
STRIP = /Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/strip

CFLAGS  = -Wall -pipe -O3
LDFLAGS =

ifeq ($(ARCH), X86)
CFLAGS += -IC:/MinGW/include
CFLAGS += -IC:/MinGW/include/SDL
CFLAGS += -IC:/MinGW/include/PVR
CFLAGS += -IC:/MinGW/include/libpng12

else
DRIVE 	= 
# -march=armv7-a -mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -ftree-vectorize
CFLAGS  += -march=armv7-a -mcpu=cortex-a8 -mfpu=neon -ffast-math \
		  -fsingle-precision-constant  -funroll-loops \
		  -fexpensive-optimizations -fomit-frame-pointer

#CFLAGS  += -findirect-inlining
#CFLAGS  += -ftree-switch-conversion
#CFLAGS  += -floop-interchange -floop-strip-mine -floop-block
VERSION=3.0
CFLAGS += -F/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS${VERSION}.sdk/System/Library/Frameworks -F/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS${VERSION}.sdk/System/Library/PrivateFrameworks -I../../ -I../../include/ -I../../include/SDL -I../../Classes/ -I/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS3.0.sdk/usr/lib/gcc/arm-apple-darwin9/4.2.1/include -isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS${VERSION}.sdk  -L/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS${VERSION}.sdk/usr/lib -L../../lib/
CFLAGS += -miphoneos-version-min=${VERSION} -I. -O3 -DPIC 
CFLAGS += -ffast-math -fexpensive-optimizations -ftemplate-depth-36 -mstructure-size-boundary=32 -falign-functions=32 -falign-loops -falign-labels -falign-jumps -fno-builtin -fno-common -fomit-frame-pointer -fno-strength-reduce -fno-strict-aliasing
CFLAGS  += -D__NEON_OPT -D__VEC4_OPT -D__PACKVERTEX_OPT
endif

ifeq ($(OS), LINUX)
CFLAGS += -Wall -D__LINUX__ -fPIC
LDFLAGS = -lobjc \
    	        -lpthread \
              -framework CoreFoundation \
              -framework Foundation \
              -framework UIKit \
              -framework QuartzCore \
              -framework CoreGraphics \
              -framework CoreSurface \
              -framework CoreLocation \
              -framework AudioToolbox \
              -framework GraphicsServices \
              -framework OpenGLES \
              -lSDLiPhoneOS -lpng -lz
else
CFLAGS += -Wall
LDFLAGS +=  -LC:/MinGW/lib/PVR -lSDLmain -lSDL -lpng -lGLESv2
endif

#CFLAGS += -save-temps
#CFLAGS += -DPROFILE_GBI

OBJECTS =

# list of object files to generate
OBJECTS += Config.o \
  gles2N64.o \
  OpenGL.o \
  N64.o \
  RSP.o \
  VI.o \
  Textures.o \
  ShaderCombiner.o \
  gDP.o \
  gSP.o \
  GBI.o \
  DepthBuffer.o \
  CRC.o \
  2xSAI.o \
  RDP.o \
  F3D.o \
  F3DEX.o \
  F3DEX2.o \
  L3D.o \
  L3DEX.o \
  L3DEX2.o \
  S2DEX.o \
  S2DEX2.o \
  F3DPD.o \
  F3DDKR.o \
  F3DWRUS.o

# build targets
all: gles2n64.$(SO_EXTENSION)

clean:
	rm -f *.o ./wes/*.o *.$(SO_EXTENSION) ui_gln64config.*

# build rules
.cpp.o:
	$(CXX) -o $@ $(CFLAGS) -c $<

.c.o:
	$(CXX) -o $@ $(CFLAGS) -c $<

ui_gln64config.h: gln64config.ui
	$(UIC) $< -o $@

gles2n64.$(SO_EXTENSION): $(OBJECTS)
	$(CXX) $^ $(CFLAGS) $(LDFLAGS) $(ASM_LDFLAGS) $(PLUGIN_LDFLAGS) $(SDL_LIBS) $(LIBGL_LIBS) -Wl,-flat_namespace -Wl,-undefined -Wl,suppress -dynamiclib -install_name /Applications/n64iphone.app/plugins/$@ -o $@

gles2N64.o: gles2N64.cpp
	$(CXX) $(CFLAGS) $(SDL_FLAGS) -DMAINDEF -c -o $@ $<

Config_qt4.o: Config_qt4.cpp ui_gln64config.h
	$(CXX) $(CFLAGS) $(SDL_FLAGS) -c -o $@ $<

Config_gtk2.o: Config_gtk2.cpp
	$(CXX) $(CFLAGS) $(SDL_FLAGS) -c -o $@ $<

GBI.o: GBI.cpp
	$(CXX) $(CFLAGS) $(SDL_FLAGS) -c -o $@ $<

