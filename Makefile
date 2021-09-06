SOURCEDIR := $(CURDIR)/src
BINDDIR := $(CURDIR)/bin
BUILDDIR := $(CURDIR)/build

TARGET = $(BUILDDIR)/adventure

adventure:
	c++ -c $(SOURCEDIR)/adventure.cpp -o ${BUILDDIR}/adventure.o

battle:
	c++ -c ${SOURCEDIR}/battle.cpp -o ${BUILDDIR}/battle.o

exe:
	c++ ${BUILDDIR}/* -o bin/adventure

all: adventure battle exe