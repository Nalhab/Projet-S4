
//choix au hasard entre toutes les attractions et la sortie :0
attraction* dest(parc* parc)
{
    int rdm = rand()%parc->totlikeness;
    size_t tot = 0;
    attraction* fin;
    size_t i = 0;
    int b = 1;
    attraction** atts = parc->att;
    for(; i < parc->nbatt && b; i++)
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
        fin = *(atts+parc->nbatt);
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

//toutes les 5s att->capacity personne sortent de l'att et retourne dans une autre attractions
void loop(parc* parc)
{
    attraction** atts = parc->att;
    attraction* att = *atts;
    //nbr de tour de boucle
    size_t lp = 0;
    while(parc->nbpeople > 0 && lp < 100)
    {
        lp++;
        printf("%ld\n", lp);
        print_parc(parc);
        srand(time(NULL));
        sleep(2);
        for(size_t i = 0; i < parc->nbatt; i++)
        {
            att = *(atts+i);
            for (size_t j = 0; j < att->capacity && att->nbpeople > 0; j++)
            {
                dest(parc);
                att->nbpeople--;
            }
        }
        att = *(atts + parc->nbatt);
        att->likeness += 3;
        parc->totlikeness += 3;
    }
    if (parc->nbpeople > 0)
    {
        parc->nbpeople = 0;

    }
}
//faire au bout d'un certain nb de boucle tout le monde sort pour faire genre la fermeture du parc


//on pourrait faire aussi en sorte que l'utilisateur puissent + ou - accelerer les loops
//en mettant une variable dans le sleep


/*int main(void)
{
    parc* parc = init_parc(5);
    pop_init(200, parc);
    
    print_parc(parc);
    loop(parc);   
}*/

//pour plus tard
/*
time_t t;
time(&t);

//assuming dx is duration of attraction x
if(!(t - time(NULL))%d0) 
    att0->nbpeople--;
    
*/
