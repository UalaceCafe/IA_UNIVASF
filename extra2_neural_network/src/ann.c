#include <stdio.h>
#include "../include/ann.h"

void initialize_network(Network_s* network, Gate_e gate) {
	network->weights[0] = 0.0;
	network->weights[1] = 0.0;
	network->bias = 0.0;
	network->learning_rate = 0.1;
	network->error = 0.0;
	network->gate = gate;
}

uint16_t train_network(Network_s* network) {
	uint16_t epoch = 0;
	double diff_sum;

	do {
		diff_sum = 0.0;

		puts("#-----------------------#");
		printf("# * Epoch %d\n", epoch);
		puts("#-----------------------#");

		for (int i = 0; i < 4; i++) {
			network->inputs[0] = training_data[network->gate][i][0];
			network->inputs[1] = training_data[network->gate][i][1];
			network->expected_output = training_data[network->gate][i][2];

			double weighted_sum = network->inputs[0] * network->weights[0] +
				network->inputs[1] * network->weights[1] - network->bias;

			network->actual_output = weighted_sum > 0 ? 1 : 0;
			double diff = network->expected_output - network->actual_output;
			diff_sum += diff * diff;

			network->weights[0] += diff * network->inputs[0] * network->learning_rate;
			network->weights[1] += diff * network->inputs[1] * network->learning_rate;
			network->bias -= diff * network->learning_rate;

			printf("Iteration %d:\n", i + 1);
			puts("------------");
			printf("Weighted sum: %.4f\n", weighted_sum);
			printf("Expected output: %u\n", network->expected_output);
			printf("Actual output: %u\n", network->actual_output);
			printf("Error: %.4f\n", diff);
			printf("Weights: [%.4f, %.4f]\n", network->weights[0], network->weights[1]);
			printf("Bias: %.4f\n", network->bias);
			printf("\n");
		}

		network->error = diff_sum / 2.0;
		printf("Network error: %f\n", network->error);
		puts("");

		epoch++;
	} while (diff_sum > 0.0);

	return (epoch - 1);
}

// static void update_weights(Network_s* network) {
// }

void print_training_data(Network_s network) {
	puts(".-------------.");
	puts("| x1 | x2 | y |");
	puts("|----|----|---|");

	for (int i = 0; i < 4; i++) {
		printf(
			"| %d  | %d  | %d |\n",
			training_data[network.gate][i][0],
			training_data[network.gate][i][1],
			training_data[network.gate][i][2]
		);
	}
}

void print_initial_network_state(Network_s network) {
	puts("Initial network state:");
	puts("-------------------------");
	printf("Weights: [%.4f, %.4f]\n", network.weights[0], network.weights[1]);
	printf("Bias: %.4f\n", network.bias);
	printf("Learning rate: %.2f\n", network.learning_rate);
	printf("Gate: %s\n", network.gate == GATE_AND ? "AND" : "OR");
}
