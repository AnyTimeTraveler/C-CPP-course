#include "headers.h"

namespace simulation {
    // elements
    Bank *bank = new Bank();
    std::vector<Human *> humans = std::vector<Human *>();

    // constants
    const std::array<int, 7> bill_values = {50000, 20000, 10000, 5000, 2000, 1000, 500};
    const std::array<int, 8> coin_values = {200, 100, 50, 20, 10, 5, 2, 1};
}