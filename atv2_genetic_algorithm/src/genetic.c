#include <stdio.h>
#include <stdlib.h>
#include "../include/genetic.h"

Individual ** select_parents(Individual ** population, uint8_t population_size) {
	Individual ** parents = malloc(sizeof(Individual *) * PARENTS_SIZE);

	uint8_t * indices = malloc(sizeof(uint8_t) * population_size);
	for(uint8_t i = 0; i < population_size; i++) {
		indices[i] = i;
	}
	shuffle_array(indices, population_size);

	for(uint8_t i = 0; i < population_size / 2; i++) {
		printf("Match %d parents: %d vs %d\n", i + 1, indices[i * 2] + 1, indices[i * 2 + 1] + 1);
		printf("Match %d winner: ", i + 1);

		if(population[indices[i * 2]]->fitness > population[indices[i * 2 + 1]]->fitness) {
			printf("%d\n", indices[i * 2] + 1);
			parents[i] = population[indices[i * 2]];
		} else {
			printf("%d\n", indices[i * 2 + 1] + 1);
			parents[i] = population[indices[i * 2 + 1]];
		}
	}
	free(indices);

	return parents;
}

void crossover(Individual ** parents, Individual ** population, uint8_t population_size) {
	uint8_t * chromosome1 = parents[0]->chromosome, * chromosome2 = parents[1]->chromosome;
	uint8_t * new_chromosome1 = malloc(sizeof(chromosome1));
	uint8_t * new_chromosome2 = malloc(sizeof(chromosome2));
	uint8_t crossover_index;
	uint8_t crossover_num = 2;

	for(uint8_t i = 0; i < population_size / 2; i++) {
		if(!check_probability(CROSSOVER_PROBABILITY)) {
			printf("No crossover\n");
			crossover_num--;
			continue;
		}

		crossover_index = randi(1, CHROMOSOME_SIZE - 1);

		printf("%s crossover at index: %d\n", i == 0 ? "1st" : "2nd", crossover_index);

		for(uint8_t j = 0; j < CHROMOSOME_SIZE; j++) {
			if(i < crossover_index) {
				new_chromosome1[j] = chromosome1[j];
				new_chromosome2[j] = chromosome2[j];
			} else {
				new_chromosome1[j] = chromosome2[j];
				new_chromosome2[j] = chromosome1[j];
			}
		}

		set_chromosome(population[i * 2], new_chromosome1);
		set_chromosome(population[i * 2 + 1], new_chromosome2);
	}

	if(crossover_num == 0) {
		free(new_chromosome1);
		free(new_chromosome2);
	}
}

void mutate(Individual ** population, uint8_t population_size) {
	for(uint8_t i = 0; i < population_size; i++) {
		for(uint8_t j = 0; j < CHROMOSOME_SIZE; j++) {
			if(check_probability(MUTATION_PROBABILITY)) {
				printf("\nMutation in individual %d at gene %d (bit %d)\n", i + 1, j + 1, j);
				population[i]->chromosome[j] = population[i]->chromosome[j] == 0 ? 1 : 0;
			}
		}

		population[i]->value = binary_to_int(population[i]->chromosome);
	}
}
