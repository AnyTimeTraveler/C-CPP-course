#include "functions.hpp"

int main() {
	int a = 11259375; // 00abcdef
	//int a = 2427178479; // 90abcdef
	printPascalString(intToHex(a));
	return 0;
}
