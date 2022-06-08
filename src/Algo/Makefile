CC = gcc
CFLAGS = -Wall -Wextra

all: Floyd
Floyd : Floyd.o Graph.o List.o
Graph: Graph.o List.o
List: List.o

.PHONY: clean

clean:
	${RM} Floyd Floyd.o
	${RM} List List.o
