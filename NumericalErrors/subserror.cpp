#include <iostream>
#include <cmath>

typedef float REAL;

REAL sum1(int N);
REAL sum2(int N);
REAL sum3(int N);


int main(void){
    int N = 100;
    // std::cout << "n \t Suma 1 \t Suma 2 \t Suma 3 \t Dif 1-3 \t Dif 2-3 \n";
    std::cout.precision(7);
    std::cout.setf(std::ios::scientific);
    

    for(int n = 1; n <= N; n++){
        std::cout << n << "\t" << sum1(n) << "\t" << sum2(n) << "\t" << sum3(n) << "\t" << std::fabs(sum1(n) - sum3(n)) / sum3(n) << "\t" << std::fabs(sum2(n) - sum3(n)) / sum3(n) << "\n";
    }

    return 0;
    
}

REAL sum1(int N){
    REAL suma = 0.0;

    for(int n = 1; n <= 2 * N; n++){
        REAL i = n * 1.0;
        suma += std::pow(-1, i) * i / (i + 1);
    }

    return suma;
}

REAL sum2(int N){
    REAL suma1 = 0.0;
    REAL suma2 = 0.0;

    for(int n = 1; n <= N; n++){
        REAL i = n / 1.0;
        suma1 += (2 * i - 1) / (2 * i);
        suma2 += (2 * i) / (2 * i + 1);
    }

    return -suma1 + suma2;
}

REAL sum3(int N){
    REAL suma = 0.0;

    for(int n = 1; n <= N; n++){
        REAL i = n / 1.0;
        suma += 1 / (2 * i * (2 * i + 1));
    }

    return suma;
}

// u columnaX:columnaY

// plot 'subserror.txt' u 1:5, '' u 1:6 w lp
// plot 'subserror.txt' u 1:5 w lp title "Error 1", '' u 1:6 w lp title "Error 2"