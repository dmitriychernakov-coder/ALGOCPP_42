#include<iostream>

int simple_string_hash(const std::string& stroke) {
    int hash{0};

    for (int i = 0; i < stroke.length(); ++i) {
        char chare = stroke[i];
        hash += static_cast<int>(chare);
    }

    return hash;
    
}

int main(int argc, char** argv) {
    std::string word;
    
    do {
        std::cout << "Введите строку или 'exit'  для завершения: ";
        std::cin >> word;     
        int hash = simple_string_hash(word);
        std::cout << "Наивный хэш строки " << word << " = " << hash << std::endl;

    } while (word != "exit");

    return 0;
}