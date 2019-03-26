// file main_ISR.cpp
#include <iostream>
#include <signal.h>
#include <unistd.h>

volatile int j;

//extern "C" {
void ISR(int iarg){
  std::cout << "ISR j=" << j << "\n";
}
//}

void install_ISR(void){
  signal(SIGUSR1, ISR);
}

int main(int argc, const char * argv[]) {
  std::cout << "process ID = " << getpid() << "\n";
  install_ISR();
  for(int i=0; i<300*1000*1000; i++){
    i= i +10; i-=10; j=i;
  }
  std::cout << "done.\n";
  return 0;
}

