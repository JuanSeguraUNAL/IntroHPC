#include <random>
#include <iostream>
#include <cstdlib>
#include <vector>

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins);

int main(int argc, char **argv)
{
  const int SEED = std::atoi(argv[1]);
  const int NSAMPLES = std::atoi(argv[2]);
  const double MU = std::atof(argv[3]);
  const double SIGMA = std::atof(argv[4]);
  const double XMIN = std::atof(argv[5]);
  const double XMAX = std::atof(argv[6]);
  const int NBINS = std::atoi(argv[7]);

  compute_pdf(SEED, NSAMPLES, MU, SIGMA, XMIN, XMAX, NBINS);
}

void compute_pdf(int seed, int nsamples, double mu, double sigma, double xmin, double xmax, int nbins)
{
  // random stuff
  std::mt19937 gen(seed);
  std::normal_distribution<double> dis{mu, sigma};

  // Declaracion de variables
  std::vector<int> histogram(nbins, 0);
  int bin;
  double r;
  double dx = (xmax - xmin) / nbins;
  double xbin;
  double pdf;
  
  // Generacion de numeros de la distribucion normal y su ubicacion en los bins para el conteo del histograma
  for(int n = 0; n < nsamples; ++n) {
    r = dis(gen);

    if(r >= xmin && r<= xmax){
        bin = (int)((r - xmin) / dx);
        histogram[bin] += 1; 
    }
  }

  // Calcular el x como el punto medio de cada bin y su pdf acorde al histograma e imprimir
  for(int i = 0; i < nbins; ++i){
    xbin = xmin + (i + 0.5) * dx;
    pdf = histogram[i] / (nsamples * dx);
    std::cout << xbin << "\t" << pdf << "\n";
  }

}
