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

int* append_to_dynamic_array(int* &arr, int &logic_size, int &max_size, int new_value) {
    if (logic_size == max_size) {
        int new_max_size = max_size * 2;
        int* new_arr = new int[new_max_size];
        
        for (int i = 0; i < max_size; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max_size = new_max_size;
   
    }
    arr[logic_size] = new_value;
    logic_size++;   
    return arr;
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
    
    int new_value;
    do {
        std::cout << "Введите элемент для добавления (0 для завершения): ";
        std::cin >> new_value;

        if (new_value != 0) {
            arr = append_to_dynamic_array(arr, logic_size, max_size, new_value);
            std::cout << "Динамический массив: ";
            print_dynamic_array(arr, logic_size, max_size);
        }
    } while (new_value != 0);
    
    std::cout << "Спасибо! Ваш массив: ";
    print_dynamic_array(arr, logic_size, max_size);

    delete[] arr;
    
    return 0;

}
