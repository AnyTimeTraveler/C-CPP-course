// file main_04_UDEF_e.cpp
#include "../../helpers/println.hpp"
#include <iostream>

struct BinaryOctet {
    bool evenParity;     // set to true if number of '1' in bitsAsDigits is even, false otherwise
    unsigned char value; // bit values as chars (no, bits as bits)
    BinaryOctet(int x = 0) {
        value = (unsigned char) x;
        regenerateParityBit();
    }

    BinaryOctet(const BinaryOctet &) = default;

    bool operator!=(BinaryOctet other) {
        return value != other.value;
    }

    bool operator==(BinaryOctet other) {
        return value == other.value;
    }

    BinaryOctet operator--(int) {
        value--;
        regenerateParityBit();
        return BinaryOctet(value + 1);
    }

    BinaryOctet operator++(int) {
        value++;
        regenerateParityBit();
        return BinaryOctet(value - 1);
    }

    void regenerateParityBit() {
        evenParity = true;
        for (int i = 0; i < 8; i++) {
            if (((value >> i) & 0b00000001) == 0b00000001) {
                evenParity = !evenParity;
            }
        }
    }
};

BinaryOctet operator+(BinaryOctet left, BinaryOctet right) {
    return left.value + right.value;
}

BinaryOctet operator-(BinaryOctet left, BinaryOctet right) {
    return left.value - right.value;
}

BinaryOctet operator/(BinaryOctet left, BinaryOctet right) {
    return left.value / right.value;
}

BinaryOctet operator*(BinaryOctet left, BinaryOctet right) {
    return left.value * right.value;
}


BinaryOctet doCalculation(BinaryOctet a, BinaryOctet b) {
    BinaryOctet result;

    println(a);
    println(b);
    for (; a != b; b--) {
        a = a + 1;
        a = a / b;

        println(a);
        println(b);
    }
    result = a + b;

    return result;
}

// for println();
std::string as_string(BinaryOctet a) {
    std::string result = "(";
    for (int i = 7; i >= 0; i--) {
        result += ((a.value >> i) & 0b00000001) & 0b00000001 ? '1' : '0';
    }
    result += ") : ";
    result += std::to_string(a.value);
    return result;
}

// for std::cout
std::ostream &operator<<(std::ostream &os, const BinaryOctet &toBePrinted) {
    os << "(" << as_string(toBePrinted) << ")";
    return os;
}

int main(int argc, char **argv) {
    BinaryOctet a = 0b00001111;
    BinaryOctet b = 0b00000110;
    println("result = ", doCalculation(a, b));
    std::cout << "result = " << doCalculation(a, b) << std::endl;
//    std::cout << as_string(a) << std::endl;
//    std::cout << as_string(b) << std::endl;
    return 0;
}
