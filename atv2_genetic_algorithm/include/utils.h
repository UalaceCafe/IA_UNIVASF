#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdint.h>

#define SET_BIT(VALUE, BIT) (VALUE |= (1 << (BIT)))
#define CLEAR_BIT(VALUE, BIT) (VALUE &= ~(1 << (BIT)))
#define TOGGLE_BIT(VALUE, BIT) (VALUE ^= (1 << (BIT)))
#define GET_BIT(VALUE, BIT) ((VALUE >> (BIT)) & 1)

int8_t randi(int8_t min, int8_t max);
double randd(double min, double max);
void shuffle_array(uint8_t * array, uint8_t size);
bool check_probability(double probability);
void int_to_binary(uint8_t * output, int8_t value);
int8_t binary_to_int(uint8_t * binary);

#endif // !UTILS_H
