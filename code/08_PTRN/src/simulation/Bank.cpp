#include "headers.h"


void Bank::depositMoney(Human &depositer, std::unique_ptr<MoneyUnit> moneyUnit) {
    accounts.at(&depositer) += moneyUnit->getValue();
}

bool Bank::withdrawMoney(Human &withdrawer, int value) {
    if (accounts.find(&withdrawer) == accounts.end()) {
        return false;
    }
    int *balance = &accounts.at(&withdrawer);
    if (*balance < value) {
        return false;
    }

    *balance -= value;
    withdrawer.receiveMoney(generateMoney(value));
    return true;
}

namespace {

    template<typename MoneyArray>
    void generatePayout(int &value, std::vector<std::unique_ptr<MoneyUnit>> &payout, MoneyArray &values) {
        for (size_t i = 0; i < values.size() && value > 0;) {
            if (values.at(i) <= value) {
                auto x = std::make_unique<Bill>(values.at(i));
                payout.push_back(std::move(x));
                value -= values.at(i);
            } else {
                ++i;
            }
        }
    }
}

std::vector<std::unique_ptr<MoneyUnit>> Bank::generateMoney(int value) {
    std::vector<std::unique_ptr<MoneyUnit>> payout;

    generatePayout(value, payout, simulation::bill_values);
    generatePayout(value, payout, simulation::coin_values);
    return payout;
}

void Bank::createAccount(Human &human) {
    accounts.insert(std::pair<Human *, int>(&human, 0));
}
