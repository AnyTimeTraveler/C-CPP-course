// file: main_04_UDEF_a.cpp
#include "../../helpers/println.hpp"
#include "RationalNumber.hpp"
#include <iostream>

// location 1

// this declares an alias for type <see below>, which is called calctype
//typedef unsigned int calctype;
//typedef int calctype;
//typedef double calctype;
typedef RationalNumber calctype;

// location 2


void doCalculation(calctype a, calctype b){

	calctype c = a + b;

// here is some advanced computation on arguments a and b
// for(){ ...
//   if(){ ...
//     for(){ ...

  println("a = ", a);
  println("b = ", b);
  println("c = ", c);
}


int main(int argc, char** argv, char** envp){

	calctype a;
	calctype b;

	doCalculation(a,b);

	return 0;
}
