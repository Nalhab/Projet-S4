CC = gcc
CFLAGS = -Wall -Wextra

all: Dijkstra 
Dijkstra : Dijkstra.o Graph.o 
Graph: Graph.o List.o
List: List.o

.PHONY: clean

clean:
	${RM} Dijkstra Dijkstra.o
	${RM} Graph Graph.o
	${RM} List List.o
