#include <iostream>
#include "../include/training.h"
#include "../include/stats.h"

int main(void) {
    const std::array<const std::string, 4> input = { "Sunny", "Cool", "High", "Strong" };

    double yes_prob = Stats::probability_class("Yes");
    double no_prob = Stats::probability_class("No");

    std::cout << "\n\"Should I play tennis?\"" << '\n';
    std::cout << "----" << '\n';
    std::cout << "P(Yes) = " << yes_prob << '\n';
    std::cout << "P(No) = " << no_prob << '\n';
    std::cout << "----" << '\n';

    double yes_prob_outlook = Stats::probability_var_given_class(OUTLOOK, input[OUTLOOK], "Yes");
    double yes_prob_temperature = Stats::probability_var_given_class(TEMPERATURE, input[TEMPERATURE], "Yes");
    double yes_prob_humidity = Stats::probability_var_given_class(HUMIDITY, input[HUMIDITY], "Yes");
    double yes_prob_wind = Stats::probability_var_given_class(WIND, input[WIND], "Yes");

    double no_prob_outlook = Stats::probability_var_given_class(OUTLOOK, input[OUTLOOK], "No");
    double no_prob_temperature = Stats::probability_var_given_class(TEMPERATURE, input[TEMPERATURE], "No");
    double no_prob_humidity = Stats::probability_var_given_class(HUMIDITY, input[HUMIDITY], "No");
    double no_prob_wind = Stats::probability_var_given_class(WIND, input[WIND], "No");

    double yes_prob_input = yes_prob_outlook * yes_prob_temperature * yes_prob_humidity * yes_prob_wind * yes_prob;
    double no_prob_input = no_prob_outlook * no_prob_temperature * no_prob_humidity * no_prob_wind * no_prob;

    std::cout << "P(Outlook = " << input[OUTLOOK] << " | Yes) = " << yes_prob_outlook << '\n';
    std::cout << "P(Temperature = " << input[TEMPERATURE] << " | Yes) = " << yes_prob_temperature << '\n';
    std::cout << "P(Humidity = " << input[HUMIDITY] << " | Yes) = " << yes_prob_humidity << '\n';
    std::cout << "P(Wind = " << input[WIND] << " | Yes) = " << yes_prob_wind << '\n';
    std::cout << "----" << '\n';

    std::cout << "P(Outlook = " << input[OUTLOOK] << " | No) = " << no_prob_outlook << '\n';
    std::cout << "P(Temperature = " << input[TEMPERATURE] << " | No) = " << no_prob_temperature << '\n';
    std::cout << "P(Humidity = " << input[HUMIDITY] << " | No) = " << no_prob_humidity << '\n';
    std::cout << "P(Wind = " << input[WIND] << " | No) = " << no_prob_wind << '\n';
    std::cout << "----" << '\n';

    std::cout << "P(Yes | X) = " << yes_prob_input << '\n';
    std::cout << "P(No | X) = " << no_prob_input << '\n';
    std::cout << "----" << '\n';

    std::cout << "Pick: ";
    if(yes_prob_input >= no_prob_input) {
        std::cout << "Yes, with " << yes_prob_input * 100.0 << "%% probability";
    } else {
        std::cout << "No, with " << no_prob_input * 100.0 << "%% probability";
    }
    std::cout << std::endl;

    return 0;
}
