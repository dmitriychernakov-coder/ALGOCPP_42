#include <iostream>

int find_pattern_light_rabin_karp(const std::string& source, const std::string& pattern) {
    int s = source.length();
    int p = pattern.length();

    if (p == 0 || s < p) {
        return -1;
    }

    int p_hash = 0;
    for (int i = 0; i < p; ++i) {
        p_hash += static_cast<int>(pattern[i]);
    }

    int h = 0;
    for (int i = 0; i < p; ++i) {
        h += static_cast<int>(source[i]);
    }

    for (int i = 0; i <= s - p; ++i) {

        if (h == p_hash) {
            bool match = true;
            for (int j = 0; j < p; ++j) {
                if (source[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return i;
            }
        }

        if (i + p < s) {
            h -= static_cast<int>(source[i]);
            h += static_cast<int>(source[i + p]);
        }
    }

    return -1;
}

int main() {
    std::string source_string;
    std::string search_pattern;

    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> source_string;

    do {
        std::cout << "Введите подстроку, которую нужно найти или 'exit' для выхода: ";
        std::cin >> search_pattern;

        int index = find_pattern_light_rabin_karp(source_string, search_pattern);

        if (index != -1) {
            std::cout << "Подстрока \"" << search_pattern << "\" найдена по индексу " << index << std::endl;
        } else {
            std::cout << "Подстрока \"" << search_pattern << "\" не найдена" << std::endl;
        }

    } while (search_pattern != "exit");

    return 0;
}