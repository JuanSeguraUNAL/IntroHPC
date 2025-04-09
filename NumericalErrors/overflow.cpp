#include <iostream>

int main(){
    double x = -1.5e38;
    double y = -1.5e38;
    double z = 1;
    std::cout << x + (y + z) << std::endl;
    std::cout << (x + y) + z << std::endl;
}