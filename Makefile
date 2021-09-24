CC=g++
CCFLAGS= -I${LIBSRCDIR} -no-pie

BINDIR := bin
SRCDIR := src
LIBDIR := ${SRCDIR}/libeo
LIBSRCDIR := ${LIBDIR}/lib

make:
	${CC} ${SRCDIR}/adventure.cpp ${LIBSRCDIR}/libeo.a -o ${BINDIR}/adventure ${CCFLAGS}
