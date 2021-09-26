CC=g++
CCFLAGS= -I${LIBSRCDIR} -no-pie

SRCDIR := src
LIBDIR := ${SRCDIR}/libeo
LIBSRCDIR := ${LIBDIR}/src

make:
	${CC} ${SRCDIR}/adventure.cpp ${LIBDIR}/libeo.a -o adventure ${CCFLAGS}
