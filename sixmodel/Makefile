# CXX = clang
CXX ?= clang
LDLIBS = -lm -lstdc++
CXXFLAGS = -MD -O0 -ggdb -Wall -std=c++11 -I/usr/local/include
CC = $(CXX)
DESTDIR = /usr/local

all: sixmodel

sixmodel: sixmodel.o spartan6die.o

install: all
	cp icepack $(DESTDIR)/bin/sixmodel

uninstall:
	rm -f $(DESTDIR)/bin/sixmodel

clean:
	rm -f sixmodel
	rm -f *.o *.d

-include *.d

.PHONY: all install uninstall clean

