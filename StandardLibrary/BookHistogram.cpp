#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>

void analyze_document(const std::string & fname);

int main(int argc, char **argv)
{
    const std::string FNAME = argv[1];

    analyze_document(FNAME);

    return 0;
}

void analyze_document(const std::string & fname)
{
    std::ifstream file(fname);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fname << std::endl;
        return;
    }

    std::map<std::string, int> word_count;
    std::string word;
    std::string especiales = "!@#$%^&*(),.?";

    while (file >> word) {
        // Minusculas
        for(char& x : word){
            x = (char)std::tolower(x);
        }

        // Eliminar el ultimo caracter de una palabra en caso de ser especial o de puntuacion
        if(!word.empty() && especiales.find(word.back()) != std::string::npos){
            word.pop_back();
        }

        // En caso de que la palabra no este en el diccionario, agregarla con valor 1
        if(word_count.find(word) == word_count.end()){
            word_count[word] = 1;
        }
        // En caso de estar en el diccionario, aumentar su valor en 1
        else{
            word_count[word] += 1;
        }

        // Convertimos el map a un vector de pares
        std::vector<std::pair<std::string, int>> vec(word_count.begin(), word_count.end());

        // Ordenamos por valor, de mayor a menor
        std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second; // Cambiar a < si querés de menor a mayor
        });

        // Imprimir el resultado
        for (const auto& par : vec) {
            std::cout << par.first << " => " << par.second << std::endl;
        }
    }
    
    std::cout << word_count[word];
}