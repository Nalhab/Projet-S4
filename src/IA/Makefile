CC = gcc

EXEC = main

CFLAGS = -Wall -Wextra

SRCDIR = src/main/
IADIR = src/
OBJDIR = obj/

SRCS :=$(shell ls $(SRCDIR)*.c)
OBJS =$(subst .c,.o,$(subst $(SRCDIR),$(OBJDIR),$(SRCS)))

all: $(EXEC)
 
$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS) obj/population.o obj/attraction.o $(CFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) -c -o obj/attraction.o src/attraction.c $(CFLAGS)
	$(CC) -c -o obj/population.o src/population.c $(CFLAGS)
	$(CC) -c -o $@ $< $(CFLAGS)


clean:
	rm -fr $(EXEC)
	rm -fr $(OBJDIR)
