#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <stdint.h>

#define CHROMOSOME_SIZE 5

typedef struct {
    int8_t value;
    uint8_t chromosome[CHROMOSOME_SIZE];
    double fitness;
} Individual;

Individual ** create_initial_population(uint8_t size);
Individual * create_individual(int8_t value);
void set_value(Individual * individual, int8_t value);
void set_chromosome(Individual * individual, uint8_t * chromosome);
void compute_fitness(Individual ** population, uint8_t size);
void print_individual(Individual * individual);
void print_population(Individual ** population, uint8_t size);
void free_individual(Individual * individual);
void free_population(Individual ** individual, uint8_t size);

#endif // INDIVIDUAL_H
