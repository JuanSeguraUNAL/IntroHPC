#include <iostream>
#include <eigen3/Eigen/Dense>

// Codigo para generar matriz A y vector b aleatorios y resolver Ax = b
// Toma como entradas el tamaño de la matriz y el numero de la semilla
int main(int argc, char **argv)
{
    const int N = std::atoi(argv[1]);
    const int seed = std::atoi(argv[2]);
    srand(seed);
    Eigen::MatrixXd A = Eigen::MatrixXd::Random(N,N);
    Eigen::VectorXd b = Eigen::VectorXd::Random(N,1);
    std::cout << "Here is the matrix A:\n" << A << std::endl;
    std::cout << "Here is the vector b:\n" << b << std::endl;
    Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);
    std::cout << "The solution is:\n" << x << std::endl;
    std::cout << "Verification:\n" << (A*x - b).norm() << std::endl;
}