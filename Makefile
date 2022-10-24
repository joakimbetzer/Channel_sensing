CONTIKI_PROJECT = main
all: $(CONTIKI_PROJECT)
TARGET_LIBFILES += -lm

MAKE_NET = MAKE_NET_NULLNET

CONTIKI = /home/vagrant/contiki-ng
include $(CONTIKI)/Makefile.include