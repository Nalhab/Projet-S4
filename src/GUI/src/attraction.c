#include "attraction.h"

//initialisation de l'attraction i
attraction* init_att(size_t i, parc* parc)
{
    attraction* att = malloc(sizeof(attraction));
    att->number = i;
    att->duration = 2;
    //att->duration = rand()%2001 + 1000;
    att->capacity = rand()%9 + 1;
    size_t likeness = (size_t)rand()%90 + 10;
    parc->totlikeness += likeness;
    att->likeness = likeness;
    att->nbpeople = 0;
    return att;
}

//initialisation du parc avec n attraction
parc* init_parc(size_t n)
{
    time_t t;
    srand((unsigned) time(&t));
    parc* prc = malloc(sizeof(parc));
    attraction** atts = malloc(sizeof(attraction)*(n+1));
    
    prc->nbatt = n;
    prc->totlikeness = 0;
    prc->nbpeople = 0;
    prc->att = atts;

    for (size_t i = 0; i < n; i++)
    {
        *(atts+i) = init_att(i, prc);
    }

    //adding the exit
    attraction* att = malloc(sizeof(attraction));
    att->number = n;
    att->duration = 0;
    att->likeness = 5;
    att->nbpeople = 0;

    prc->totlikeness += 5;

    *(atts+n) = att;
    
    return prc;
}

void print_parc(parc* parc)
{
    printf("##########################################\n");
    printf("PARC\n");
    printf("------------------------------------------\n");
    for(size_t i = 0; i < parc->nbatt; i++)
    {
        attraction* att = *(parc->att+i);
        printf("number %ld\n", att->number);
        //printf("duration = %ld\n", att->duration);
        printf("capacity = %ld\n", att->capacity);
        printf("likeness = %ld\n", att->likeness);
        printf("nb people = %ld\n", att->nbpeople);
        printf("------------------------------------------\n");
    }
    attraction* att = *(parc->att+(parc->nbatt));
    printf("exited person = %ld\n", att->nbpeople);
    printf("person in parc : %ld\n", parc->nbpeople);
    printf("parc total likeness = %ld\n", parc->totlikeness);
}
