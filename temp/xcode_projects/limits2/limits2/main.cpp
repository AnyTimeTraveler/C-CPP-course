//  main.cpp
//  limits2



#include "../../../helpers/println.hpp"
#include <limits>


int main()
{
  println("type\t sizeof\t\t lowest\t\t\t\t highest\n");
  println("float \t ",sizeof(float), "\t\t\t",
          std::numeric_limits<float>::lowest(), "\t\t",
          std::numeric_limits<float>::max());
  println("double\t ",sizeof(double), "\t\t\t",
          std::numeric_limits<double>::lowest(), "\t\t",
          std::numeric_limits<double>::max());
  println("int   \t ",sizeof(int), "\t\t\t",
          std::numeric_limits<int>::lowest(), "\t\t\t",
          std::numeric_limits<int>::max());
  println("long  \t ",sizeof(long), " \t\t",
          std::numeric_limits<long>::lowest(), '\t',
          std::numeric_limits<long>::max());
  
  }
