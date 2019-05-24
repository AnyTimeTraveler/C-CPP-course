#include <vector>
#include <list>
#include <map>
#include <string>
#include <iostream>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>
#include "headers.h"
#include "Utils.h"

#define AMOUNT_OF_HUMANS         10000
#define SUPER_RICH_THRESHOLD   1000000
#define RICH_THRESHOLD           10000
#define POOR_THRESHOLD            2000

using namespace simulation;

/////////////
// filters //
/////////////
bool super_rich(Human *human) {
    return human->getAmountOfMoneyOnThem() > SUPER_RICH_THRESHOLD;
}

bool rich(Human *human) {
    return human->getAmountOfMoneyOnThem() > RICH_THRESHOLD;
}

bool poor(Human *human) {
    return human->getAmountOfMoneyOnThem() < POOR_THRESHOLD;
}


////////////
// actors //
////////////
void getting_paid(Human *human) {
    human->receiveMoney(bank->generateMoney(std::rand() % 10000));
}

void depositing_money(Human *human) {
    human->depositMoney();
}

void withdrawing_money(Human *human) {
    bank->withdrawMoney(*human, std::rand() % 10000);
}

void buying_stuff(Human *human) {
    human->spendMoney();
}

void donating_some_of_their_money(Human *human) {
    human->donate();
}

int main() {
    for (int i = 0; i < AMOUNT_OF_HUMANS; ++i) {
        humans.push_back(new Human());
    }

    int pastCycles = 0, cycles = 0;
    // simulate one tick
    do {
        // simulate some humans
        Some(&humans, 50 /* percent */).are(getting_paid);
        Some(rich, &humans).are(depositing_money);
        Some(rich ,&humans).are(buying_stuff);
        Some(poor, &humans).are(withdrawing_money);
        Some(1, super_rich, &humans).are(donating_some_of_their_money);
        // ask user what to do
        cycles--;
        if (cycles <= 0) {
            std::cout << "========================" << std::endl
                      << "==  " << std::setw(6) << (pastCycles + 1) << " Cycles     ==" << std::endl
                      << "========================" << std::endl
                      << std::endl;
            printHumans(&humans);
            std::cout << std::endl
            << "How many cycles to continue? (0 => quit)" << std::endl;
            std::cin >> cycles;
            pastCycles += cycles;
        }
    } while (cycles);
}

