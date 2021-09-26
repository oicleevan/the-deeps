SRCDIR := src

libeo: compile archive

compile:
	g++ -c ${SRCDIR}/libeo.cpp -o ${SRCDIR}/libeo.o

archive:
	ar rvs libeo.a ${SRCDIR}/libeo.o

clean:
	rm ${SRCDIR}/libeo.o
