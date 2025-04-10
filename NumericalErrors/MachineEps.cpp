#include <iostream>
#include <cstdlib>

// Determinar el epsilon a partir del cual 1.0 + eps = 1.0 en la representacion del computador

typedef double REAL;

int main(int argc, char **argv)
{   
  std::cout.precision(20);
  std::cout.setf(std::ios::scientific);
  int N = std::atoi(argv[1]);
  REAL eps = 1.0;
  REAL one;

  for(int ii = 0; ii < N; ++ii){
        eps /= 2;
        one = 1.0 + eps;
        std::cout << ii + 1 << ". \t" << one << "\t eps: " << eps <<std::endl;
    }

}