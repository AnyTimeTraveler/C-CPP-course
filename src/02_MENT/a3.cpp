#include "int_to_hex.hpp"
#include "print_pascal_string.hpp"

int main(int argc, char *argv[]) {
	int a = 11259375; // 00abcdef
	//int a = 2427178479; // 90abcdef
	printPascalString(intToHex(a));
	return 0;
}
