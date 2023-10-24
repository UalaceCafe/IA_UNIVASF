#include <array>
#include <string>

namespace Stats {
    // FIXME: Is this the best way to pass an std::array (or its iterators) to a function?
    double probability_class(const std::string);
    double probability_var_given_class(size_t, const std::string, const std::string);
}
