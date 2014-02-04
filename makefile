#----------------------------------------------------------------------------
#
#                       Makefile for ARM
#
#----------------------------------------------------------------------------

# Compiler (c++11 support required)
GCC=g++-mp-4.7

# LIBS
LIBS=-lstdc++

# Performance Flags
GCC_CFLAGS= -std=c++11 -O3 -falign-labels -falign-loops -funroll-all-loops -fexpensive-optimizations -funroll-loops -I./hdr
GCC_LDFLAGS= -std=c++11 -lstdc++ -I./hdr

# Objects
OBJECTS= \
obj/create/create.o \
obj/main/main.o

EXECUTABLE=arm

all: $(OBJECTS) serial

# Serial Targets
serial: $(OBJECTS)
	$(GCC) $(GCC_LDFLAGS) $(LIBS) $(OBJECTS) -o $(EXECUTABLE)

$(OBJECTS): obj/%.o: src/%.cpp
	$(GCC) -c -o $@ $(GCC_CFLAGS) $<

clean:
	@rm -f obj/*.o
	@rm -f obj/*/*.o

purge:
	@rm -f obj/*.o
	@rm -f obj/*/*.o
	@rm -f arm

tidy:
	@rm -f *~
	@rm -f hdr/*~
	@rm -f src/*~
	@rm -f src/*/*~
