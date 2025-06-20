#include <iostream>
#include <omp.h>

int main(int argc, char *argv[]) {
  std::cout << "BEFORE\n";
#pragma omp parallel
  { 
    int tid = omp_get_thread_num();
    int total = omp_get_num_threads();
    std::cout << "Hola mundo, soy el thread " << tid << " de un total de threads de " << total << "\n";
  }
  std::cout << "AFTER\n";

  return 0;
}