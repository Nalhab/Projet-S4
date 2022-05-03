#ifndef ATTRACTION_H
#define ATTRACTION_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//soit 1sec = 1m
//durée usuellement = entre 1 et 3 min
//->entre 1 et 3 sec 
//->entre 1000 et 3000 ms

typedef struct attraction
{
    //maybe useful later ??
    size_t number;

    //durée de l'attraction pour calculer temps d'attente en sec
    //pas uilisé
    size_t duration;

    //nombre de gens que l'attracion peut prendre par tour
    size_t capacity;

    //a quel point les gens aime l'attraction pour ensuite repartir la population :)
    size_t likeness;

    //nombre de gens dans la queue
    size_t nbpeople;
} attraction;

typedef struct parc
{
    //nombre attraction
    size_t nbatt;

    //number total of likeness of each attraction
    size_t totlikeness;
    
    //number of people in the parc
    size_t nbpeople;

    //liste des attractions
    attraction** att;
}parc;

attraction* init_att(size_t, parc*);

parc* init_parc(size_t);

void pop_init(size_t, parc*);

attraction* dest(parc*);

void loop(parc*);

void print_parc(parc*);

#endif
