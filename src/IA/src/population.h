#ifndef POPULATION_H
#define POPULATION_H

#include "attraction.h"
#include <stddef.h>

attraction* dest(parc* parc);

void pop_init(size_t n, parc* parc);

void loop(parc* parc);


#endif
