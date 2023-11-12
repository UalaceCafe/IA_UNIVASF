#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ann.h"


int main(int argc, char** argv) {
	if (argc < 2) {
		printf("Usage: %s GATE=[and|or]\n", argv[0]);
		return 1;
	}

	Network_s network;
	Gate_e gate;

	if (strcmp(argv[1], "and") == 0) {
		gate = GATE_AND;
	} else if (strcmp(argv[1], "or") == 0) {
		gate = GATE_OR;
	} else {
		printf("Usage: %s GATE=[and|or]\n", argv[0]);
		return 1;
	}

	puts("Training data:");
	print_training_data(network);

	initialize_network(&network, gate);
	puts("\n");
	print_initial_network_state(network);
	puts("");

	uint16_t epoch = train_network(&network);

	printf("Finished training after %d epochs.\n\n", epoch);
	puts("Final network state:");
	puts("-------------------------");
	printf("Weights: [%.4f, %.4f]\n", network.weights[0], network.weights[1]);
	printf("Bias: %.4f\n", network.bias);

	return 0;
}
