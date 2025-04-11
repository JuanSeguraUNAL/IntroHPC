#include <iostream>
#include <cmath>

typedef float REAL;

// Declaracion de una funcion (que recibe y que retorna)
REAL sumk(int k);

int main(void){
    // Imprimir en precision de 7 decimales y en notacion cientifica
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);

    for(int k = 1; k <= 1000; k++){
        std::cout << k << "\t" << sumk(k) << "\n";
    }
    
    return 0;
}

// Implementacion de la funcion
REAL sumk(int k){
    REAL suma = 0.0;
    for(int ii = 1; ii <= k; ii++){
        suma += 0.1;
    }

    // Se define esta variable auxiliar para no truncar por division de enteros 
    REAL aux = k / 10.0;
    // Funcion de valor absoluto incluida en cmath
    return std::fabs(aux - suma);
}

// Se puede guardar la salida en un txt en la terminal "./sumk > data.txt"
// Se puede graficar en la terminal con "gnuplot", luego, "plot 'data.txt' w lp"

// "splot f(x,y) w pm3d" ----> Graficar en tres dimensiones desde la terminal
// "set out "example.pdf" " 