#ifndef INC_08_SIMULATION_UTILS_H
#define INC_08_SIMULATION_UTILS_H

#include <algorithm>
#include <random>
#include <math.h>
#include <iomanip>
#include "headers.h"

class Some : public std::vector<Human *> {
public:
    Some(std::vector<Human *> *all, int percent) {
        int amount = (all->size() * percent) / 100;
        std::sample(all->begin(), all->end(), std::back_inserter(*this), amount, std::mt19937{std::random_device{}()});
    }

    template<typename Func>
    Some(Func filter, std::vector<Human *> *all) {
        for (auto it = all->begin(); it < all->end(); ++it) {
            if (filter(*it)) {
                push_back(*it);
            }
        }
    }

    template<typename Func>
    Some(int percent, Func filter, std::vector<Human *> *all) {
        for (auto it = all->begin(); it < all->end(); ++it) {
            if (filter(*it)) {
                push_back(*it);
            }
        }
        int amount = (size() * percent) / 100;
        for (int i = 0; i < amount; ++i) {
            pop_back();
        }
    }

    template<typename F>
    void are(F function) {
        for (auto human : *this) {
            function(human);
        }
    }
};

struct {
    bool operator()(Human *a, Human *b) const {
        return a->getAmountOfMoneyOnThem() < b->getAmountOfMoneyOnThem();
    }
} customLess;

void printChartLine(int &exp, int &counter);

void printHumans(std::vector<Human *> *humans) {
    int money = 100;
    int counter = 0;
    std::sort(humans->begin(), humans->end(), customLess);
    for (auto it = humans->begin(); it < humans->end(); ++it) {
//        std::cout << (*it)->getAmountOfMoneyOnThem() << std::endl;
        if ((*it)->getAmountOfMoneyOnThem() < money) {
            counter++;
        } else if (counter != 0) {
            printChartLine(money, counter);
            std::cout << std::endl;
            money += money;
        } else{
            money += money;
        }
    }
    printChartLine(money, counter);
}

void printChartLine(int &value, int &counter) {
    std::cout << std::setw(5) << value / 2 << " - " << std::setw(5) << value << "  : ";
    for (; counter > 0; counter -= 100) {
        std::cout << '#';
    }
    counter = 0;
}

#endif //INC_08_SIMULATION_UTILS_H
