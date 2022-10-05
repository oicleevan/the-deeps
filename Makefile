CC=clang++
CCFLAGS= -I${LIBSRCDIR} -std=c++11

SRCDIR := src
LIBDIR := ${SRCDIR}/libeo
LIBSRCDIR := ${LIBDIR}/src
BUILDDIR := build
BINDIR := bin

TARGET := ${BINDIR}/the-deeps

make: compile link

install: make
	cp ${TARGET} /usr/bin
	@echo Installed.

compile:
	@mkdir -p ${BUILDDIR}
	${CC} -c ${SRCDIR}/adventure.cpp -o ${BUILDDIR}/adventure.o ${CCFLAGS}
	${CC} -c ${SRCDIR}/startmenu.cpp -o ${BUILDDIR}/startmenu.o ${CCFLAGS}

link:
	@mkdir -p ${BINDIR}
	${CC} ${BUILDDIR}/adventure.o ${BUILDDIR}/startmenu.o ${LIBDIR}/libeo.a -o ${TARGET}

clean:
	rm -rf ${BUILDDIR} ${BINDIR}
