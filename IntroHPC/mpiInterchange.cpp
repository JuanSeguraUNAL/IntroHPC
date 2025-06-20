#include <mpi.h>
#include <iostream>

int main(int argc, char** argv)
{
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int np;
    MPI_Comm_size(MPI_COMM_WORLD, &np);

    // Get the rank of the process
    int pid;
    int a;
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    if(pid == 0){
        a = 123;
        MPI_Send(&a, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        std::cout << "El nodo 0 envio " << a << " al nodo 1.\n";
    }

    if(pid == 1){
        MPI_Recv(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "El nodo 1 recibio " << a << " del nodo 0.\n";
    }

    // Finalize the MPI environment.
    MPI_Finalize();
}