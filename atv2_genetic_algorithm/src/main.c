#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "../include/utils.h"
#include "../include/population.h"
#include "../include/genetic.h"

#define POPULATION_SIZE 4
#define GENERATIONS 5

int main(void) {
	srand(time(NULL));

	Individual ** population = create_initial_population(POPULATION_SIZE);
	Individual ** parents;

	for(uint8_t i = 0; i <= GENERATIONS; i++) {
		compute_fitness(population, POPULATION_SIZE);

		printf("\nGeneration %d\n", i);
		print_population(population, POPULATION_SIZE);
		printf("\n");

		if(i == GENERATIONS) {
			break;
		}

		parents = select_parents(population, POPULATION_SIZE);

		printf("\nParents (Generation %d)\n", i);
		print_population(parents, 2);
		printf("\n");

		crossover(parents, population, POPULATION_SIZE);

		printf("\nChildren before mutation (Generation %d)\n", i + 1);
		print_population(population, POPULATION_SIZE);

		mutate(population, POPULATION_SIZE);

		printf("#=================================================================#\n");
	}

	free_population(parents, PARENTS_SIZE);
	free_population(population, POPULATION_SIZE);

	printf("\n");
	return 0;
}


