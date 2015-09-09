# CXX = clang
CXX ?= clang
LDLIBS = -lm -lstdc++
CXXFLAGS = -MD -O0 -ggdb -Wall -std=c++11 -I/usr/local/include
CC = $(CXX)
DESTDIR = /usr/local

all: sixpack sixunpack

sixpack: sixpack.o spartan6die.o

sixunpack: sixpack
	ln -sf sixpack sixunpack

install: all
	cp icepack $(DESTDIR)/bin/sixpack
	ln -sf sixpack $(DESTDIR)/bin/sixunpack

uninstall:
	rm -f $(DESTDIR)/bin/sixpack
	rm -f $(DESTDIR)/bin/sixunpack

clean:
	rm -f sixpack
	rm -f sixunpack
	rm -f *.o *.d

-include *.d

.PHONY: all install uninstall clean

