#include <iostream>
#include <cstdlib>
#include <cmath>

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);
void print_array(const double data[], const int & size);

int main (int argc, char **argv)
{
  int ii, jj, kk;
  ii =  1;  // El valor de ii era cero, lo que ocasionaba divisiones por cero
  jj = -1;

  std::cout << foo(ii,jj) << "\t" << foo(jj,ii) << "\n";
  std::cout << "La raiz de 25.9 es " << baz(25.9);

  const int NX = 2, NY = 3, NZ = 4; // Se arreglo la indexacion de esta linea
  double *x, y[NY], z[NZ];
  x = new double [NX];

  // Inicializar adecuadamente los arreglos x,y,z:
  for(int i = 0; i < NX; ++i){
    x[i] = 0.0;
  }
  for(int j = 0; j < NY; ++j){
    y[j] = 0.0;
  }
  for(int k = 0; k < NX; ++k){
    x[k] = 0.0;
  }

  // int ii, jj, kk;  Se estan declarando nuevamente ii y jj
  print_array(x, NX);
  print_array(y, NY);
  print_array(z, NZ);
  std::cout << std::endl;

  for (ii = 0; ii < NX; ++ii) {
    x[ii] = ii; // Se estaba accediendo a x[jj] con jj=-1. Acceso fuera del arreglo dinamico x. Cambie jj por ii
  }
  print_array(x, NX); // Se estaba intentando acceder con el numero de elementos de z, no de x
  print_array(y, NY);         
  print_array(z, NZ); // Se cambio NZ + NY por NZ para evitar errores de acceso fuera de rango
  std::cout << std::endl;
  for (jj = 0; jj < NY; ++jj) {
    // x[jj] = ii; Se esta intentando acceder a elementos de x por fuera de su rango
    y[jj] = jj;
  }
  
  /*    Estas lineas provocan errores en lectura de memoria no asignada
  print_array(x-NY, NY);
  print_array(y-NZ, NZ);
  print_array(z + NZ + NY, NX);
  std::cout << std::endl;
  */

  // Se agregan estas lineas para ver los cambios en los arreglos
  print_array(x, NX);
  print_array(y, NY);         
  print_array(z, NZ); 
  std::cout << std::endl;

  delete[] x;  // Se agrega esto para liberar la memoria reservada dinamicamente
  return EXIT_SUCCESS;
}

int foo(int a, int b)
{
  // Usar un condicional para evitar divisiones por cero
  if(a == 0 || b == 0 || bar(a,b) == 0){ 
    std::cerr << "Error: Division por cero en foo(" << a << ", " << b << ")\n";
    return 0;
  } 
  return a/b + b/bar(a, b) + b/a; // Considerar que esto es divisiones enteras, no con precision decimal
}

int bar(int a, int b)
{
  unsigned int c = a;
  return c + a - b;
}

double baz(double x)
{
  if (x == 0) return 0.0;  // Se arreglo el condicional y se retorno un valor 0, no retornaba nada
  // double v = 1-(x+1);   No hay necesidad de declarar x
  return std::sqrt(x);
}

void print_array(const double data[], const int & size)
{
  std::cout << std::endl;
  for (int ii = 0; ii < size; ++ii) {
    std::cout << data[ii] << "  " ;
  }
}