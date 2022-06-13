#include "attraction.h"

//initialisation de l'attraction i
attraction* init_att(size_t i, parc* parc)
{
    attraction* att = malloc(sizeof(attraction));
    att->number = i;
    att->duration = rand()%3 + 1;
    att->capacity = rand()%9 + 1;
    size_t likeness = (size_t)rand()%90 + 10;
    parc->totlikeness += likeness;
    att->likeness = likeness;
    att->nbpeople = 0;
    return att;
}

//initialisation du parc avec n attraction
parc* init_parc(size_t n, int pluie)
{
    time_t t;
    srand((unsigned) time(&t));
    parc* prc = malloc(sizeof(parc));
    attraction** atts = malloc(sizeof(attraction)*(n+1));
    
    prc->nbatt = n;
    prc->totlikeness = 0;
    prc->nbpeople = 0;
    prc->att = atts;
    prc->pluie = pluie;
    prc->pluiing = 0;

    for (size_t i = 0; i < n; i++)
    {
        *(atts+i) = init_att(i, prc);
    }
    //adding the no attraction place
    attraction* att = malloc(sizeof(attraction));
    att->number = n;
    att->capacity = 100;
    att->duration = 3;
    att->likeness = 10;
    att->nbpeople = 0;

    prc->totlikeness += 10;

    *(atts+n) = att;
    
    //adding the exit
    attraction* att2 = malloc(sizeof(attraction));
    att2->number = n+1;
    att2->duration = 0;
    att2->likeness = 5;
    att2->nbpeople = 0;

    prc->totlikeness += 5;

    *(atts+n+1) = att2;
    
    return prc;
}

void print_parc(parc* parc)
{
    printf("##########################################\n");
    printf("PARC\n");
    printf("------------------------------------------\n");
    attraction* att = *(parc->att);
    for(size_t i = 0; i < parc->nbatt; i++)
    {
        att = *(parc->att+i);
        printf("number %ld\n", att->number);
        printf("duration = %ld\n", att->duration);
        printf("capacity = %ld\n", att->capacity);
        printf("likeness = %ld\n", att->likeness);
        printf("nb people = %ld\n", att->nbpeople);
        printf("------------------------------------------\n");
    }
    att = *(parc->att+(parc->nbatt));
    printf("person waiting = %ld\n", att->nbpeople);
    printf("pluiing ? %s\n", parc->pluiing ? "yes" : "no");
    printf("il devrait y avoir de la pluie, %i\n", parc->pluie);
    printf("waiting likeness = %ld\n", att->likeness);

    att = *(parc->att+(parc->nbatt)+1);
    printf("exited person = %ld\n", att->nbpeople);
    printf("person in parc : %ld\n", parc->nbpeople);
    printf("parc total likeness = %ld\n", parc->totlikeness);
}
