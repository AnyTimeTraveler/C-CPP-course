#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc32-c"
#pragma ide diagnostic ignored "cert-msc30-c"
// based on example from http://en.cppreference.com/w/cpp/numeric/random/rand
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>
#include <locale>

void fillRandom(int *array, int size, int max_value) {
    for (int i = 0; i < size; ++i) {
        array[i] = std::rand() % max_value;
    }
}

std::vector<int> toVector(int *array, int size) {
    std::vector<int> vector;

    for (int i = 0; i < size; ++i) {
        vector.push_back(array[i]);
    }

    return vector;
}

std::list<int> toList(const std::vector<int> &vector) {
    std::list<int> list;
    std::list<int, std::allocator<int>>::iterator finder;

    for (int it : vector) {
        finder = std::find(list.begin(), list.end(), it);
        if (finder != list.end()) {
            continue;
        }
        list.push_back(it);
    }
    return list;
}

int stringSimilarity(std::string a, std::string b) {
    int points = 0;

    std::locale loc;
    // get smaller size
    int size = a.size() < b.size() ? a.size() : b.size();

    // same char
    int same = 0;
    // same char, diff case
    int sameDk = 0;

    for (int i = 0; i < size; ++i) {
        if (a[i] == b[i]) {
            same++;
        } else if (std::tolower(a[i], loc) == std::tolower(b[i], loc)) {
            sameDk++;
        }
    }

    // intersect
    std::string intersect;
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(intersect));

    points = (same * 1000) + (sameDk * 500) + (intersect.size() * 200);

//    std::cout << std::endl << same << ' '<< sameDk << ' '<< intersect << std::endl;

    return points / (size * 12);

}

void sim(const std::string &a, std::string &b) {
    std::cout << "Similarity of \"" << a << "\" and \"" << b << "\": " << stringSimilarity(a, b) << std::endl;

}

int main() {
    std::srand(std::time(nullptr)); // use current time as seed for random generator

    std::string a = "hallo";
    std::string b = "welt";
    std::string c = "HALLO";

    sim(a, a);
    sim(a, b);
    sim(a, c);

    std::cout << std::endl << std::endl;

    // array[20]
    int arrsize = 20;

    int array[arrsize];

    // fill with rand
    fillRandom(array, arrsize, 10);

    std::cout << "Array : ";
    for (int i = 0; i < arrsize; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;

    // to vector
    std::vector<int> vector = toVector(array, arrsize);

    std::cout << "Vector: ";
    for (int &iterator : vector) {
        std::cout << iterator << ' ';
    }
    std::cout << std::endl;

    // to deduplicated list
    std::list<int> list = toList(vector);

    std::cout << "List  : ";
    for (int item : list) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    // sorted
    list.sort();

    std::cout << "Sorted: ";
    for (int &it : list) {
        std::cout << it << ' ';
    }
    std::cout << std::endl;

    std::sort(vector.begin(), vector.end());

    std::cout << "Vector: ";
    for (int &iterator : vector) {
        std::cout << iterator << ' ';
    }
    std::cout << std::endl;

}

#pragma clang diagnostic pop