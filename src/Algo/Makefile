CC = gcc
CFLAGS = -Wall -Wextra

all: Dijkstra 
Floyd : Floyd.o Graph.o
Dijkstra : Dijkstra.o Graph.o 
Graph: Graph.o List.o
List: List.o

.PHONY: clean

clean:
	${RM} Floyd Floyd.o
	${RM} Dijkstra Dijkstra.o
	${RM} Graph Graph.o
	${RM} List List.o
