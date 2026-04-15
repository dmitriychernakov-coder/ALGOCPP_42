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


int* remove_dynamic_array_head(int* &arr, int &logic_size, int &max_size) {
    if (logic_size == 0) {
        return arr;
    }
    
    if ((logic_size - 1) <= (max_size / 3)) {
        int new_max_size = max_size / 3;
        if (new_max_size == 0)
        {
            new_max_size = 1;
        }
        
    

    int* new_arr = new int[new_max_size];
    
    for (int i = 1; i < logic_size; ++i) {
            new_arr[i - 1] = arr[i];
        }

    delete[] arr;
    arr = new_arr;
    max_size = new_max_size;

    } else {
        for (int i = 1; i < logic_size; ++i) {
            arr[i - 1] = arr[i];
        }
    }
    logic_size--;
    
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

    std::string user_answer;
    
    do {
        std::cout << "Удалить первый элемент? (да/нет): ";
        std::cin >> user_answer;

        if (user_answer == "да") {
            if (logic_size == 0) {
                std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!" << std::endl;
                break;
            }
            arr = remove_dynamic_array_head(arr, logic_size, max_size);
            if (logic_size != 0) {
                std::cout << "Динамический массив: ";
                print_dynamic_array(arr, logic_size, max_size);
            }
            

            if (logic_size == 0) {
                std::cout << "Динамический массив: ";
                std::cout << "_ ";
                std::cout << std::endl;
            }

        }else if (user_answer == "нет") {
            std::cout << "Спасибо! Ваш динамический массив: ";
            print_dynamic_array(arr, logic_size, max_size);
            break;
            
        } else {
            std::cout << "Пожалуйста, введите 'да' или 'нет'." << std::endl;
        }
        
    } while (true);   

    delete[] arr;
    
    return 0;

}