# # # # # # # # # # # # # # # # # # # # # # # #
# Makefile  # # # # # # # # # # # # # # # # # #
# Created by Jordan Bonecutter  # # # # # # # #
# 20 July 2018  # # # # # # # # # # # # # # # #
# # # # # # # # # # # # # # # # # # # # # # # #

# VARIABLES # # # # # # # # # # # # # # # # # #
FLAG = gcc -ansi -std=c99 -Wall -DNDEBUG -O3
DFLAG = gcc -ansi -std=c99 -Wall -g
CFLAG = $(FLAG) -c
CDFLAG = $(DFLAG) -c

# TARGETS # # # # # # # # # # # # # # # # # # #
help:
	@echo ""
	@echo "\tTo make the full executable type \"make all\""
	@echo "\tTo make the test executable type \"make test\""
	@echo "\tTo make the file test executable type \"make filetest\""
	@echo ""

all: Main.o GPSRaw.o GPSRect.o FileIO.o GPSRectArr.o GLPoint.o Vector.o Image.o FileIOIm.o Globals.h
	$(FLAG) Main.o GPSRaw.o GPSRect.o FileIO.o GPSRectArr.o GLPoint.o Vector.o Image.o FileIOIm.o -o MainProg

test: Main_t.o GPSRaw_t.o GPSRect_t.o FileIO_t.o GPSRectArr_t.o GLPoint_t.o Vector_t.o Image_t.o FileIOIm_t.o Globals.h
	$(DFLAG) Main_t.o GPSRaw_t.o GPSRect_t.o FileIO_t.o GPSRectArr_t.o GLPoint_t.o Vector_t.o Image_t.o FileIOIm_t.o -o TestProg

filetest: FileIO_tt.o GPSRect_t.o GPSRaw_t.o GPSRectArr_t.o Globals.h
	$(DFLAG) -DFILEIOTEST FileIO_tt.o GPSRaw_t.o GPSRect_t.o GPSRectArr_t.o -o FileTest

Main.o: Main.c GPSRaw.h GPSRect.h FileIO.h GPSRectArr.h GLPoint.h Globals.h
	$(CFLAG) Main.c -o Main.o

Main_t.o: Main.c GPSRaw.h GPSRect.h FileIO.h GPSRectArr.h GLPoint.h Globals.h
	$(CDFLAG) Main.c -o Main_t.o

FileIO.o: FileIO.c FileIO.h GPSRaw.h GPSRect.h Globals.h
	$(CFLAG) FileIO.c -o FileIO.o

FileIO_t.o: FileIO.c FileIO.h GPSRaw.h GPSRect.h Globals.h
	$(CDFLAG) FileIO.c -o FileIO_t.o

FileIO_tt.o: FileIO.c FileIO.h Globals.h GPSRaw.h GPSRect.h GPSRectArr.h
	$(CDFLAG) -DFILEIOTEST FileIO.c -o FileIO_tt.o

GPSRaw.o: GPSRaw.c GPSRaw.h Globals.h
	$(CFLAG) GPSRaw.c -o GPSRaw.o

GPSRaw_t.o: GPSRaw.c GPSRaw.h Globals.h
	$(CDFLAG) GPSRaw.c -o GPSRaw_t.o

GPSRect.o: GPSRect.c GPSRect.h GPSRaw.h Globals.h
	$(CFLAG) GPSRect.c -o GPSRect.o

GPSRect_t.o: GPSRect.c GPSRect.h GPSRaw.h Globals.h
	$(CDFLAG) GPSRect.c -o GPSRect_t.o

GPSRectArr.o: GPSRectArr.c GPSRectArr.h GPSRect.h GPSRaw.h Globals.h
	$(CFLAG) GPSRectArr.c -o GPSRectArr.o

GPSRectArr_t.o: GPSRectArr.c GPSRectArr.h GPSRect.h GPSRaw.h Globals.h
	$(CDFLAG) GPSRectArr.c -o GPSRectArr_t.o

GLPoint.o: GLPoint.c GLPoint.h GPSRect.h GPSRectArr.h Vector.h Globals.h
	$(CFLAG) GLPoint.c -o GLPoint.o

GLPoint_t.o: GLPoint.c GLPoint.h GPSRect.h GPSRectArr.h Vector.h Globals.h
	$(CDFLAG) GLPoint.c -o GLPoint_t.o

Vector.o: Vector.c Vector.h
	$(CFLAG) Vector.c -o Vector.o

Vector_t.o: Vector.c Vector.h
	$(CDFLAG) Vector.c -o Vector_t.o

Image.o: Image.c Image.h
	$(CFLAG) Image.c -o Image.o

Image_t.o: Image.c Image.h
	$(CDFLAG) Image.c -o Image_t.o

FileIOIm.o: FileIOIm.c FileIOIm.h Image.h
	$(CFLAG) FileIOIm.c -o FileIOIm.o

FileIOIm_t.o: FileIOIm.c FileIOIm.h Image.h
	$(CDFLAG) FileIOIm.c -o FileIOIm_t.o

clean:
	rm -f *.o
	rm -f MainProg
	rm -f TestProg
	rm -f FileTest
