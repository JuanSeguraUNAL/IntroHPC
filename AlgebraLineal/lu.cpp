#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <eigen3/Eigen/Dense>

void stats(const int size, const int reps, // input parameters
               double & mean_wtime, double & sigma_wtime, // output
               double & mean_ctime, double & sigma_ctime); // output

int main(int argc, char ** argv)
{
    const int M = atoi(argv[1]); // Matrix size
    const int R = atoi(argv[2]); // Repetitions

    double mean_wtime, sigma_wtime;
    double mean_ctime, sigma_ctime;
    stats(M, R, mean_wtime, sigma_wtime, mean_ctime, sigma_ctime);
    std::cout << M
                << "\t" << mean_wtime << "\t" << sigma_wtime
                << "\t" << mean_ctime << "\t" << sigma_ctime
                << std::endl;
        
    return 0;
}

void stats(const int size, const int reps, // input parameters
               double & mean_wtime, double & sigma_wtime, // output
               double & mean_ctime, double & sigma_ctime) // output
{
    // definir variables para sumar los tiempos
    double suma_wtime = 0.0; 
    double suma_wtime2 = 0.0;
    double suma_ctime = 0.0; 
    double suma_ctime2 = 0.0;

    std::chrono::steady_clock::time_point startw, endw;
    std::chrono::duration<double> difw;
    std::clock_t startc = std::clock();
    std::clock_t endc = std::clock();

    // llamar/copiar codigo reps veces a solvesystem y medir su tiempo
    for (int ii = 0; ii < reps; ++ii) {
        Eigen::MatrixXd A = Eigen::MatrixXd::Random(size, size);
        Eigen::MatrixXd b = Eigen::MatrixXd::Random(size, 1);
        // cronometro para wtime y para cpu time
        startc = std::clock();
        startw = std::chrono::steady_clock::now();
        Eigen::MatrixXd x = A.partialPivLu().solve(b);
        endc = std::clock();
        endw = std::chrono::steady_clock::now();
        difw = endw - startw;
        auto difc = endc - startc;

        suma_wtime += difw.count();
        suma_ctime += difc;

        suma_wtime2 += difw.count()*difw.count();
        suma_ctime2 += difc*difc;
        // anhadir a suma_wtime, suma_wtime2...
        std::cerr << x(0, 0) << "\n";
    }


    // calcular las estadisticas y retornar/guardar sus valores 
    mean_wtime = suma_wtime/reps;
    sigma_wtime = std::sqrt(reps*(suma_wtime2/reps - mean_wtime*mean_wtime)/(reps-1));
    mean_ctime = suma_ctime/reps; 
    sigma_ctime = std::sqrt(reps*(suma_ctime2/reps - mean_ctime*mean_ctime)/(reps-1));
}