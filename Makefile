CXX ?= clang

all:
#	$(MAKE) -C sixpack
	$(MAKE) -C sixmodel

clean:
	$(MAKE) -C sixpack clean
	$(MAKE) -C sixmodel clean

install:
	$(MAKE) -C sixpack install
	$(MAKE) -C sixmodel install

uninstall:
	$(MAKE) -C sixpack uninstall
	$(MAKE) -C sixmodel uninstall

.PHONY: all clean install uninstall
