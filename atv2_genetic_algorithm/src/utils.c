#include <stdlib.h>
#include "../include/utils.h"

int8_t randi(int8_t min, int8_t max) {
	return rand() % (max - min + 1) + min;
}

double randd(double min, double max) {
	return min + (max - min + 1) * (double)rand() / (double)RAND_MAX;
}

void shuffle_array(uint8_t *array, uint8_t size)
{
    if(size > 1)
    {
        for(uint8_t i = 0; i < size - 1; i++)
        {
          uint8_t j = i + rand() / (RAND_MAX / (size - i) + 1);
          uint8_t t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

bool check_probability(double probability) {
	return randd(0.0, 1.0) <= probability;
}

void int_to_binary(uint8_t * output, int8_t value) {
	int8_t mult = value < 0 ? -1 : 1;

	output[0] = value < 0 ? 1 : 0;
	value *= mult;

	for(uint8_t i = 0; i < 4; i++) {
		output[i + 1] = GET_BIT(value, 3 - i);
	}
}

int8_t binary_to_int(uint8_t * binary) {
	int8_t out = 0;
	int8_t mult = binary[0] == 1 ? -1 : 1;

	for(uint8_t i = 0; i < 4; i++) {
		out |= (binary[i + 1] << (3 - i));
	}

	return out * mult;
}
