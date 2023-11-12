#ifndef ANN_H
#define ANN_H

#include <stddef.h>
#include <stdint.h>

typedef enum {
	GATE_AND,
	GATE_OR
} Gate_e;

typedef struct {
	uint8_t inputs[2];
	uint8_t expected_output;
	uint8_t actual_output;
    double weights[2];
    double bias;
    double learning_rate;
	double error;
	Gate_e gate;
} Network_s;

static const uint8_t training_data[2][4][3] = {
	{
		{ 0, 0, 0 },
		{ 0, 1, 0 },
		{ 1, 0, 0 },
		{ 1, 1, 1 }
	},
	{
		{ 0, 0, 0 },
		{ 0, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 1, 1 }
	}
};

void initialize_network(Network_s* network, Gate_e gate);
uint16_t train_network(Network_s* network);
void print_training_data(Network_s network);
void print_initial_network_state(Network_s network);

#endif // ANN_H
