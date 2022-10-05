CC := clang++

SRCDIR := src
BUILDDIR := build

TARGET := libeo.a

make: compile archive

compile:
	mkdir -p ${BUILDDIR}
	${CC} -c ${SRCDIR}/libeo.cpp -o ${BUILDDIR}/libeo.o

archive:
	ar rvs ${TARGET} ${BUILDDIR}/libeo.o

clean:
	rm -r ${BUILDDIR}
