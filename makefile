all: player enemy map gui main build
	
.PHONY: player enemy map gui main build

player:
	$(MAKE) -C player all
enemy:
	$(MAKE) -C enemy all
map:
	$(MAKE) -C map all
gui:
	$(MAKE) -C gui all
main:
	$(MAKE) -C main all
build:
	$(MAKE) -C build all