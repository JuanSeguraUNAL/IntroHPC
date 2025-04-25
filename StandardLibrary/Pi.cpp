#include <random>
#include <iostream>
#include <cmath>
#include <cstdlib>

typedef double REAL;

double compute_pi(int seed, long nsamples);

int main(int argc, char **argv) 
{
  const int SEED = std::atoi(argv[1]);
  const long NSAMPLES = std::atol(argv[2]);
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  double mypi = compute_pi(SEED, NSAMPLES);
  std::cout << mypi << "\n"; 
    
  return 0;
}

double compute_pi(int seed, long nsamples) 
{
  std::mt19937 gen(seed);
  std::uniform_real_distribution<double> dis(-0.5, 0.5);
  REAL x;
  REAL y;
  double Nc = 0.0;
  
  for(int n = 0; n < nsamples; ++n){
    x = dis(gen);
    y = dis(gen);
    if(std::pow(x, 2) + std::pow(y, 2) <= 1.0 / 4.0){
        Nc += 1;
    }
  }

  REAL pi = 4 * Nc / nsamples;
  return pi;
}