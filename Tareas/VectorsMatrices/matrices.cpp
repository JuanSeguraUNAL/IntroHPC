#include <iostream>
#include <vector>

int main(int argc, char **argv){
    const int M = 4;
    const int N = 3;

    std::vector<double> array2d(M*N, 0.0);
    for(int ii= 0; ii < M; ++ii){
        for(int jj = 0; jj < N; ++jj){
            array2d[ii*N + jj] = 1.0 / (ii + jj + 1);
        }
    }

    // Imprimir la matriz
    for(int ii= 0; ii < M; ++ii){
        for(int jj = 0; jj < N; ++jj){
            std::cout << array2d[ii*N + jj] << " ";
        }
        std::cout << "\n";
    }

    // Imprimir la matriz transpuesta
    std::vector<double> array2d_T(M*N, 0.0);
    for(int ii= 0; ii < M; ++ii){
        for(int jj = 0; jj < N; ++jj){
            array2d_T[jj*M + ii] = 1.0 / (ii + jj + 1);
        }
        std::cout << "\n";
    }
}