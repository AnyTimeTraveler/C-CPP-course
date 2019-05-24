#ifndef INC_08_SIMULATION_HEADERS_H
#define INC_08_SIMULATION_HEADERS_H

#include <vector>
#include <array>
#include <map>
#include <list>
#include <memory>
#include <iostream>

#define DEBUG false

class Bank;

class Human;

class MoneyUnit;

namespace simulation {
    // elements
    extern Bank *bank;
    extern std::vector<Human *> humans;


    // constants
    extern const std::array<int, 7> bill_values;
    extern const std::array<int, 8> coin_values;
}

class MoneyUnit {
private:
    int value;
public:
    MoneyUnit(int value) : value(value) {
        if (DEBUG) { std::cout << "MoneyUnit()" << std::endl; }
    }

    inline int getValue() const {
        return value;
    }

    virtual ~MoneyUnit() {
        if (DEBUG) { std::cout << "~MoneyUnit()" << std::endl; }
    }
};

class Coin : public MoneyUnit {

public:
    Coin(int value) : MoneyUnit(value) {
        if (DEBUG) { std::cout << "Coin()" << std::endl; }
    }

    ~Coin() {
        if (DEBUG) { std::cout << "~Coin()" << std::endl; }
    }
};

class Bill : public MoneyUnit {
private:
    int serial;
public:
    Bill(int value) : MoneyUnit(value) {
        serial = std::rand() % 100000;
        if (DEBUG) { std::cout << "Bill()" << std::endl; }
    }

    ~Bill() {
        if (DEBUG) { std::cout << "~Bill()" << std::endl; }
    }
};

class Human {
private:
    std::vector<std::unique_ptr<MoneyUnit>> money;
public:

    Human();

    int getAmountOfMoneyOnThem() const;


    void receiveMoney(std::vector<std::unique_ptr<MoneyUnit>> moneyUnit);

    void depositMoney();

    void spendMoney();
    void donate();

    bool operator>(Human &other) const {
        return getAmountOfMoneyOnThem() > other.getAmountOfMoneyOnThem();
    }

    bool operator<(Human &other) const {
        return getAmountOfMoneyOnThem() < other.getAmountOfMoneyOnThem();
    }

    ~Human() {
        if (DEBUG) { std::cout << "~Human()" << std::endl; }
    }
};

class Bank {
private:
    std::map<Human *, int> accounts;
public:
    Bank() {
        if (DEBUG) { std::cout << "Bank()" << std::endl; }
    }

    void createAccount(Human &human);

    void depositMoney(Human &depositer, std::unique_ptr<MoneyUnit> moneyUnit);

    std::vector<std::unique_ptr<MoneyUnit>> generateMoney(int value);

    bool withdrawMoney(Human &withdrawer, int value);

    ~Bank() {
        if (DEBUG) { std::cout << "~Bank()" << std::endl; }
    }
};

#endif //INC_08_SIMULATION_HEADERS_H
