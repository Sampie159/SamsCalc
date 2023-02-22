##
# SamsCalc
#
# @file
# @version 0.0.1-Alpha

PKGCONFIG=$(shell which pkg-config)
CFLAGS=-g -Wall -Wextra -std=c11
LIBS=$(shell $(PKGCONFIG) --libs gtk4)
AUX=$(shell $(PKGCONFIG) --cflags gtk4)

OBJDIR=obj/
OBJS=$(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))

SRCDIR=src/
SRCS=$(wildcard $(SRCDIR)*.c)

TESTDIR=tests/
TESTS=$(wildcard $(TESTDIR)*.c)
TESTBINS=$(patsubst $(TESTDIR)%.c, $(TESTDIR)bin/%, $(TESTS))

all: samscalc

release: CFLAGS = -std=c11 -Wall -Wextra -O2 -pipe -march=native -DNDEBUG
release: clean
release: samscalc

samscalc: $(OBJS)
	cc $(CFLAGS) $(LIBS) $^ -o $@ -lm

$(OBJDIR)%.o: $(SRCDIR)%.c
	cc $(CFLAGS) $(AUX) -c $< -o $@

clean:
	rm -f $(OBJDIR)* samscalc

# end
