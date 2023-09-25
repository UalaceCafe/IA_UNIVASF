#ifndef GENETIC_H
#define GENETIC_H

#include <stdint.h>
#include "utils.h"
#include "population.h"

#define PARENTS_SIZE 2
#define CROSSOVER_PROBABILITY 0.6
#define MUTATION_PROBABILITY 0.01

Individual ** select_parents(Individual ** population, uint8_t population_size);
void crossover(Individual ** parents, Individual ** population, uint8_t population_size);
void mutate(Individual ** population, uint8_t population_size);

#endif // GENETIC_H
