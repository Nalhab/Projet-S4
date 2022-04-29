#Makefile

CC = gcc
CFLAGS = -Wall -Wextra -g

EXE = attraction population

all: ${EXE}

attraction: attraction.o 
population: attraction.o population.o
#attraction.o: attraction.c attraction.h
#population.o: population.c attraction.h


.PHONY: clean

clean:
	${RM} ${EXE} attraction.o population.o

#END
