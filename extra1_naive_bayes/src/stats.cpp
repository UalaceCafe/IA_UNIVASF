#include <cstdint>
#include "../include/training.h"
#include "../include/stats.h"

namespace Stats {
    static size_t count_occurrences(size_t var_type, const char* x) {
        size_t occur = 0;

        for(auto& row : training_data) {
            if(row[var_type] == x) {
                occur++;
            }
        }

        return occur;
    }

    static size_t count_occurrences_intersection(size_t var1_type, const char* x1, size_t var2_type, const char* x2) {
        size_t occur = 0;

        for(auto& row : training_data) {
            if(row[var1_type] == x1 && row[var2_type] == x2) {
                occur++;
            }
        }

        return occur;
    }

    double probability_class(const char* test_class) {
        return static_cast<double>(count_occurrences(CLASS, test_class)) / training_data.size();
    }

    double probability_var_given_class(size_t var_type, const std::string var, const char* test_class) {
        size_t qty_class = count_occurrences(CLASS, test_class);
        size_t qty_var_class = count_occurrences_intersection(var_type, var.c_str(), CLASS, test_class);

        return static_cast<double>(qty_var_class) / qty_class;
    }
}
