CC = gcc

EXEC = attraction population

CFLAGS = -Wall -Wextra

SRCDIR = src/
OBJDIR = obj/

SRCS=$(shell ls $(SRCDIR)*.c)
OBJS=$(subst .c,.o,$(subst $(SRCDIR),$(OBJDIR),$(SRCS)))


all: $(EXEC)
 
$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS)


clean:
	rm -fr $(EXEC)
	rm -fr $(OBJDIR)
