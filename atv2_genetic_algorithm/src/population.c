#include <stdio.h>
#include <stdlib.h>
#include "../include/population.h"
#include "../include/utils.h"

#define FUNC(x) (x*x - 3*x + 4)

Individual ** create_initial_population(uint8_t size) {
	Individual ** population = malloc(sizeof(Individual *) * size);

	for(uint8_t i = 0; i < size; i++) {
		population[i] = create_individual(randi(-10, 10));
	}

	return population;
}

Individual * create_individual(int8_t value) {
	Individual * individual = malloc(sizeof(Individual));
	set_value(individual, value);
	return individual;
}

void set_value(Individual * individual, int8_t value) {
	individual->value = value;
	int_to_binary(individual->chromosome, value);
}

void set_chromosome(Individual * individual, uint8_t * chromosome) {
	for(uint8_t i = 0; i < CHROMOSOME_SIZE; i++) {
		individual->chromosome[i] = chromosome[i];
	}

	individual->value = binary_to_int(chromosome);
}

void compute_fitness(Individual ** population, uint8_t size) {
	for(uint8_t i = 0; i < size; i++) {
		population[i]->fitness = 1.0 / FUNC(population[i]->value);
	}
}

void print_individual(Individual * individual) {
	printf("Chromosome: ");
	for(uint8_t j = 0; j < CHROMOSOME_SIZE; j++) {
		printf(j == CHROMOSOME_SIZE - 1 ? "%d" : "%d ", individual->chromosome[j]);
	}
	printf(
		" | x: %3d | f(x): %3d | Fitness: %lf |\n",
		individual->value, FUNC(individual->value), individual->fitness
	);
}


void print_population(Individual ** population, uint8_t size) {
	for(uint8_t i = 0; i < size; i++) {
		printf("%d| ", i + 1);
		print_individual(population[i]);
	}
}

void free_individual(Individual * individual) {
	free(individual->chromosome);
	free(individual);
}

void free_population(Individual ** individual, uint8_t size) {
	for(uint8_t i = 0; i < size; i++) {
		free_individual(individual[i]);
	}
	free(individual);
}
