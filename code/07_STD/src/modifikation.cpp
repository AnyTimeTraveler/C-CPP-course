#include <cstdlib>
#include <iostream>
#include <list>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>

#define bitsPerOctet 8


struct BinaryOctet {
    bool evenParity;
    char bitsAsDigits[bitsPerOctet];
};


void print(std::string text) {
    std::cout << text << std::endl;
}

void fillRandom(std::vector<int> *vector, int max_number) {
    int rand;
    for (int i = 0; i < vector->size();) {
        cont:
        rand = std::rand() % max_number; // NOLINT(cert-msc30-c)
        for (int j = 0; j < i; ++j) {
            if (rand == vector->at(j)) {
                goto cont;
            }
        }
        vector->at(i) = rand;
        i++;
    }
}

void fillRandom(std::list<int> *list, int max_number) {
    int rand;
    std::list<int, std::allocator<int>>::iterator it;
    for (std::list<int>::iterator i = list->begin();i != list->end();i++) {
        rand = std::rand() % max_number;

        it = find(list->begin(), list->end(), rand);
        if (it != list->end()) {
            continue;
        }
        *it = rand;
        i++;
    }
}


void print(std::vector<int> *vector) {
    for (int i = 0; i < vector->size() - 1; i++) {
        std::cout << vector->at(i) << ", ";
    }
    std::cout << vector->at(vector->size() - 1) << std::endl;
}

void print(std::list<int> *list) {
    auto it = list->begin();

    auto end = list->end();
    end--;

    for (; it != end; it++) {
        std::cout << *it << ", ";
    }

    std::cout << *it << std::endl;
}

int main() {
    std::srand(std::time(0)); // use current time as seed for random generator
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: "
              << random_variable << '\n';

    std::vector<int> vector(8);
    print(&vector);

    fillRandom(&vector, 10);

    print(&vector);

    std::sort(vector.begin(), vector.end(), std::greater<int>());

    print(&vector);

    std::cout << std::endl;

    std::list<int> list(8);
    print(&list);

    fillRandom(&list, 10);

    print(&list);

    list.sort();

    print(&list);


}

