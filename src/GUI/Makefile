CC = gcc

EXEC = gui

CFLAGS = -Wall -Wextra -Wno-deprecated-declarations -rdynamic `pkg-config --cflags gtk+-3.0`
LDLIBS = `pkg-config --libs gtk+-3.0`

SRCDIR = src/
OBJDIR = obj/

SRCS := $(shell ls $(SRCDIR)*.c)
SRCS := $(filter-out $(SRCDIR).c, $(SRCS))

OBJS := $(subst .c,.o,$(subst $(SRCDIR),$(OBJDIR),$(SRCS)))

COLOR_CYAN = \e[1;36m
COLOR_GREEN = \e[1;32m
COLOR_GRAY = \e[0;37m
COLOR_WHITE = \e[1;37m

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS) obj/population.o obj/attraction.o $(CFLAGS) $(LDLIBS)
	@echo "\n$(COLOR_GREEN)>>> GUI : $(COLOR_WHITE)Program has been successfully compiled!\n"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo "\n$(COLOR_CYAN)>>> GUI : $(COLOR_WHITE)Compilation of the program will begin.$(COLOR_GRAY)\n"
	mkdir -p $(OBJDIR)
	$(CC) -c -o obj/attraction.o ../IA/src/attraction.c $(CFLAGS)
	$(CC) -c -o obj/population.o ../IA/src/population.c $(CFLAGS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LDLIBS)

clean:
	@echo "$(COLOR_GRAY)"
	rm -fr $(EXEC)
	rm -fr $(OBJDIR)
	@echo "\n$(COLOR_GREEN)>>> GUI : $(COLOR_WHITE)All has been successfully cleaned!\n"