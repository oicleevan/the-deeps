CC := g++

SRCDIR := src
BUILDDIR := build

libeo: compile archive

compile:
	mkdir -p ${BUILDDIR}
	${CC} -c ${SRCDIR}/libeo.cpp -o ${BUILDDIR}/libeo.o

archive:
	ar rvs libeo.a ${BUILDDIR}/libeo.o

clean:
	rm -r ${BUILDDIR}
