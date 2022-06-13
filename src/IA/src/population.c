#include "population.h"
#include "attraction.h"

//choix au hasard entre toutes les attractions et la sortie :0
attraction* dest(parc* parc)
{
    int rdm = rand()%parc->totlikeness;
    size_t tot = 0;
    attraction* fin;
    size_t i = 0;
    int b = 1;
    attraction** atts = parc->att;
    for(; i <= parc->nbatt && b; i++)
    {
        tot += (*(atts+i))->likeness;
        if ((size_t)rdm <= tot)
        {
            fin = *(atts+i);
            fin->nbpeople++;
            b = 0;
        }
    }
    if (b)
    {
    //printf("le i = %ld and nbatt = %ld\n", i, parc->nbatt);
    //if (i > parc->nbatt)
    //{
        fin = *(atts+parc->nbatt+1);
        fin->nbpeople++;
        parc->nbpeople--;
    }

    return fin;
}

//placement de chaque personne dans une attraction
void pop_init(size_t n, parc* parc)
{
    parc->nbpeople = n;

    for(size_t i = 0; i < n; i++)
    {
        dest(parc);
    }
}

//struct pour les threads avec le parc et l'attraction
struct thread_data
{
    parc* parc;
    attraction* att;
};

//toutes les 5s att->capacity personne sortent de l'att et retourne dans une autre attractions
void loop(parc* parc)
{
    attraction** atts = parc->att;
    attraction* att = *atts;
    size_t lp = 0;

    pthread_t *thr = malloc((parc->nbatt+1)*sizeof(pthread_t));
    
    for (size_t i = 0; i <= parc->nbatt; i++)
    {
        
        struct thread_data* td = malloc(sizeof(struct thread_data));
        td->parc = parc;
        td->att = *(atts+i);
        int e = pthread_create(&thr[i], NULL, timer, (void*)td);
        if (e != 0)
            exit(EXIT_FAILURE);

    }


    while(parc->nbpeople > 0 && lp < 100)
    {
        lp++;
        printf("loop %ld\n", lp);
        
        if (parc->pluie)
        {
            if (parc->pluiing)
            {
                parc->pluiing--;
                if (!parc->pluiing)
                {
                    att = *(atts + parc->nbatt);
                    att->likeness -= 40;
                    parc->totlikeness -= 40;
                    parc->pluiing = 0;
                }
            }
            else
            {
                //45%100 de chance d'avoir de la pluie
                if (rand()%100 <= 45)
                {
                    att = *(atts + parc->nbatt);
                    att->likeness += 40;
                    parc->totlikeness += 40;
                    parc->pluiing = rand()%4 + 1;
                }
            }
            
        }
        
        //pause midi
        if(lp == 40)
        {
            att = *(atts + parc->nbatt);
            att->likeness += 40;
            parc->totlikeness += 40;
        }
        if (lp == 60)
        {
            att = *(atts + parc->nbatt);
            att->likeness -= 40;
            parc->totlikeness -= 40;
        }

        print_parc(parc);
        //srand(time(NULL));

        sleep(2);
        
        att = *(atts + parc->nbatt + 1);
        att->likeness += 3;
        parc->totlikeness += 3;
    }

    if (parc->nbpeople > 0)
        parc->nbpeople = 0;
}
//faire au bout d'un certain nb de boucle tout le monde sort pour faire genre la fermeture du parc
//je vais faire des threads je crois

void* timer(void* thrdt)
{
    struct thread_data* td = (struct thread_data*)thrdt;
    parc* parc = td->parc;
    attraction* att = td->att;
    while(1)
    {
        sleep(att->duration);
        for (size_t i = 0; i < att->capacity && att->nbpeople > 0; i++)
        {
            dest(parc);
            att->nbpeople--;
        }
    }
}

//on pourrait faire aussi en sorte que l'utilisateur puissent + ou - accelerer les loops
//en mettant une variable dans le sleep

//pour plus tard
/*
time_t t;
time(&t);

//assuming dx is duration of attraction x
if(!(t - time(NULL))%d0) 
    att0->nbpeople--;
    
*/
