#include <cstdlib>
#include <iostream>
#include <list>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

#define bitsPerOctet 8

struct BinaryOctet {
    bool evenParity;
    char bitsAsDigits[bitsPerOctet];

    BinaryOctet(int src) {
        evenParity = true;
        for (unsigned int i = 0; i < bitsPerOctet; i++) {
            if (((src >> (bitsPerOctet - i - 1)) & 0b0000001) == 0b0000001) {
                bitsAsDigits[i] = '1';
                evenParity = !evenParity;
            } else {
                bitsAsDigits[i] = '0';
            }
        }
    }

    operator ::int32_t() {
        int out = 0;
        for (int i = 0; i < bitsPerOctet; i++) {
            if (bitsAsDigits[i] == '1') {
                out += (0b10000000 >> i);
            }
        }
        return out;
    }
};

struct {
    bool operator()(BinaryOctet a, BinaryOctet b) const {
        for (int i = 0; i < bitsPerOctet; ++i) {
            if (a.bitsAsDigits[i] != b.bitsAsDigits[i]) {
                return b.bitsAsDigits[i] == '1';
            }
        }
        return false;
    }
} customLess;


void println(std::string text) {
    std::cout << text << std::endl;
}

void print(int text) {
    println(std::to_string(text));
}

void println() {
    std::cout << std::endl;
}

template<typename T>
void print(T it, T end) {
    end--;
    for (; it != end; it++) {
        std::cout << *it << ", ";
    }

    std::cout << *it << std::endl;
}


template<typename Collection, typename Iterator>
void fillRandom(Collection *collection, int max_number, int amount, Iterator _justHereForTheIteratorTypeInference) {
    int rand;
    Iterator it;
    for (int i = 0; i < amount;) {
        rand = std::rand() % max_number;

        it = std::find(collection->begin(), collection->end(), rand);
        if (it != collection->end()) {
            continue;
        }
        collection->push_back(rand);
        i++;
    }
}

template<typename Collection, typename Iterator>
void sortedInsert(Collection *collection, int max_number, int amount, Iterator _justHereForTheIteratorTypeInference) {
    int rand;

    Iterator it;
    for (int i = 0; i < amount; i++) {
        rand = std::rand() % max_number;
        it = collection->begin();
        while (it != collection->end() && *it < rand) {
            it++;
        }
        collection->insert(it, rand);
    }
}


int main() {
    std::srand(std::time(0)); // use current time as seed for random generator
    int random_variable = std::rand();
    std::cout << "Random value on [0 " << RAND_MAX << "]: "
              << random_variable << '\n';


    println("Vector:");
    std::vector<int> vector;
    fillRandom(&vector, 10, 8, vector.begin());

    print(vector.begin(), vector.end());

    std::sort(vector.begin(), vector.end(), std::less<int>());

    print(vector.begin(), vector.end());

    println();
    println("List:");

    std::list<int> list;
    fillRandom(&list, 10, 8, list.begin());

    print(list.begin(), list.end());

    list.sort();

    print(list.begin(), list.end());

    println();
    println();
    println("SortedInsert:");

    std::vector<int> sortedVector;
    sortedInsert(&sortedVector, 10, 8, sortedVector.begin());

    print(sortedVector.begin(), sortedVector.end());

    std::list<int> sortedList;
    sortedInsert(&sortedList, 10, 8, sortedList.begin());

    print(sortedList.begin(), sortedList.end());

    println();
    println();
    println("BinaryOctet:");

    std::vector<BinaryOctet> octets;
    fillRandom(&octets, 10, 8, octets.begin());

    print(octets.begin(), octets.end());

    std::sort(octets.begin(), octets.end(), customLess);

    print(octets.begin(), octets.end());
}

