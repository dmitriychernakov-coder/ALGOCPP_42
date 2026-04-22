#include<iostream>
#include<stdint.h>

uint64_t t{0};
uint64_t real_string_hash(const std::string& stroke, uint64_t p, uint64_t n) {
    uint64_t hash_sum{0};
    uint64_t power{1};
    for (size_t i = 0; i < stroke.length(); ++i) {
        hash_sum += static_cast<uint64_t>(stroke[i]) * power;
        power *= p;
    }
    return hash_sum % n;
}

int main(int argc, char** argv) {

    uint64_t p, n;
    std::cout << "Введите простое число p: ";
    std::cin >> p;

    std::cout << "Введите модуль n: ";
    std::cin >> n;
 
    std::string word;
    do {
        std::cout << "Введите строку или 'exit' для завершения: ";

        std::cin >> word;    
        uint64_t hash = real_string_hash(word, p, n);
        std::cout << "Хэш строки " << word << " = " << hash << std::endl;

    } while (word != "exit");

    return 0;
}