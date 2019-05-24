#include "headers.h"
#include <cassert>

int Human::getAmountOfMoneyOnThem() const {
    int amount = 0;
    for (auto it = money.begin(); it < money.end(); ++it) {
        amount += (*it)->getValue();
    }
    return amount;
}

void Human::spendMoney() {
    for (unsigned long i = 0; i < std::rand() % money.size(); ++i) {
        money.pop_back();
    }
}

void Human::depositMoney() {
    for (unsigned long i = 0; i < std::rand() % money.size(); ++i) {
        auto moneyUnit = std::move(money.back());
        money.pop_back();
        simulation::bank->depositMoney(*this, std::move(moneyUnit));
    }
}

void Human::receiveMoney(std::vector<std::unique_ptr<MoneyUnit>> moneyUnit) {
    for (auto it = moneyUnit.begin(); it != moneyUnit.end(); ++it) {
        money.push_back(std::move(*it));
    }
}

Human::Human() {
    simulation::bank->createAccount(*this);
    if (DEBUG) { std::cout << "Human()" << std::endl; }
}

void Human::donate() {
    for (unsigned long i = 0; i < money.size() / (1 + (std::rand() % 5)); ++i) {
        money.pop_back();
    }
}
