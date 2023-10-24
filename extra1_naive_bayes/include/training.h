#pragma once

#include <string>
#include <array>

#define OUTLOOK 0
#define TEMPERATURE 1
#define HUMIDITY 2
#define WIND 3
#define CLASS 4

using data_table_t = const std::array<const std::array<std::string, 5>, 14>;

data_table_t training_data = {{
    {{ "Sunny", "Hot", "High", "Weak", "No" }},
    {{ "Sunny", "Hot", "High", "Strong", "No" }},
    {{ "Overcast", "Hot", "High", "Weak", "Yes" }},
    {{ "Rain", "Mild", "High", "Weak", "Yes" }},
    {{ "Rain", "Cool", "Normal", "Weak", "Yes" }},
    {{ "Rain", "Cool", "Normal", "Strong", "No" }},
    {{ "Overcast", "Cool", "Normal", "Strong", "Yes" }},
    {{ "Sunny", "Mild", "High", "Weak", "No" }},
    {{ "Sunny", "Cool", "Normal", "Weak", "Yes" }},
    {{ "Rain", "Mild", "Normal", "Weak", "Yes" }},
    {{ "Sunny", "Mild", "Normal", "Strong", "Yes" }},
    {{ "Overcast", "Mild", "High", "Strong", "Yes" }},
    {{ "Overcast", "Hot", "Normal", "Weak", "Yes" }},
    {{ "Rain", "Mild", "High", "Strong", "No" }}
}};
