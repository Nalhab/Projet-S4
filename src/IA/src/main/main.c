#include "../population.h"

int main(void)
{
    parc* parc = init_parc(5, 1);
    pop_init(200, parc);
    print_parc(parc);
    loop(parc);   
}
