##
# SamsCalc
#
# @file
# @version 0.0.1-Alpha

CC = gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = -g -Wall -Wextra -std=c11
LIBS = $(shell $(PKGCONFIG) --libs gtk4)
AUX = $(shell $(PKGCONFIG) --cflags gtk4)

OBJDIR = obj/
OBJS = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

SRCDIR = src/
SRCS = $(wildcard $(SRCDIR)*.c)

TESTDIR = tests/
TESTS = $(wildcard $(TESTDIR)*.c)

all: samscalc

release: CFLAGS = $(shell $(PKGCONFIG) --cflags gtk4) -std=c11 -Wall -Wextra -O2 -pipe -march=native -DNDEBUG
release: clean
release: samscalc

samscalc: $(OBJS)
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@ -lm

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $(AUX) -c $< -o $@

$(TESTEDIR)/bin/%: $(TESTEDIR)%.c
	$(CC) $(CFLAGS) $(AUX) $< -o $@ -lcriterion

clean:
	rm -f $(OBJDIR)* samscalc
# end
