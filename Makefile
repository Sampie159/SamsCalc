##
# SamsCalc
#
# @file
# @version 0.0.1-Alpha

CC = gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = 	-g -Wall -Wextra
LIBS =		$(shell $(PKGCONFIG) --libs gtk4)
AUX	=		$(shell $(PKGCONFIG) --cflags gtk4)

OBJDIR = obj/
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

SRCDIR = src/
SRCS = $(wildcard $(SRCDIR)*.c)

all: samscalc

release: CFLAGS = $(shell $(PKGCONFIG) --cflags gtk4) -Wall -Wextra -O2 -pipe -march=native -DNDEBUG
release: clean
release: samscalc

samscalc: $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(AUX) -c $< -o $@

clean:
	rm -f $(OBJDIR)* samscalc
# end
