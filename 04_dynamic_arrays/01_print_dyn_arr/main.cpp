#include <iostream>

void print_dynamic_array(int arr[], int logic_size, int max_size) {
        
    for (int i = 0; i < max_size; ++i) {
        if (i < logic_size) {
            std::cout << arr[i] << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    int max_size{0};
    std::cout << "Введите фактический размер массива: ";
    std::cin >> max_size;
    int logic_size{0};
    do {
        std::cout << "Введите логический размер массива: ";
        std::cin >> logic_size;
        if (logic_size > max_size) {
            std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        }
    } while (logic_size > max_size);
    
    int* arr = new int[max_size];
    
    for (int i = 0; i < logic_size; ++i) {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logic_size, max_size);
    delete[] arr;
    return 0;
}