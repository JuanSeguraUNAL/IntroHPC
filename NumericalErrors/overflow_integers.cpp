#include <cstdio>
#include <iostream>

// Esperar un overflow por representacion numerica (Se aproxima numero grande a negativo)
int main(void){
    int a = 1;
    int n = 0;

    while(a >= 1){
        a *= 2;
        n += 1;
        std::printf("%10d\n", a);
        //std::cout << n << ". " << a << std::endl;
    }
}