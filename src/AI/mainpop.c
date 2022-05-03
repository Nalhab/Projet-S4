#include "attraction.h"

int main(void)
{
    parc* parc = init_parc(5);
    pop_init(200, parc);

    loop(parc);

    return 0;
}


