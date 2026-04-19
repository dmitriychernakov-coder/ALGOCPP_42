#include<iostream>


int calc_level(int index) {
    int value = index + 1;
    int level = -1;

    while (value > 0) {
        value = value / 2;
        level++;
    }
    return level;
}


void print_pyramid(int arr[],int size) {

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Пирамида:" << "\n";

    for (int i = 0; i < size; ++i) {
        int value = arr[i];
        if (i == 0) {
            std::cout << "0 root " << value << '\n';
        } else {
            int parent_index = (i - 1) / 2;
            int parent_value = arr[parent_index];
            int level = calc_level(i);
        
        std::string child_type = (i % 2 == 1) ? "left" : "right";
        std::cout << level << " " << child_type << "(" << parent_value << ") " << value << '\n';
        }
    }           
}


enum class Sides { LEFT, RIGHT };

bool try_get_child(int current_index, int size, Sides side, int &child_index) {

    if (side == Sides::LEFT) {
        child_index = 2 * current_index + 1;
    } else {
        child_index = 2 * current_index + 2;
    }

    if (child_index >= size) {
        return false;
    }
    return true;
}

bool try_get_parent(int current_index, int &parent_index) {
    if (current_index == 0) return false;
    parent_index = (current_index - 1) / 2;
    return true;
}

const int CMD_UP = 1;
const int CMD_LEFT = 2;
const int CMD_RIGHT = 3;
const int CMD_EXIT = 4;
const int CMD_UNKNOWN = 5;

int get_command_code(const std::string& input_command) {
    if (input_command == "up") return CMD_UP;
    if (input_command == "left") return CMD_LEFT;
    if (input_command == "right") return CMD_RIGHT;
    if (input_command == "exit") return CMD_EXIT;
    return CMD_UNKNOWN;
}

void print_location(const int arr[], int size, int current_index) {
    if (current_index == 0) {
        std::cout << "Вы находитесь здесь: 0 root " << arr[0] << "\n";
        return;
    }
    int parent_index = (current_index - 1) / 2;
    int parent_value = arr[parent_index];
    int level = calc_level(current_index);
    std::string child_type = (current_index % 2 == 1) ? "left" : "right";
    std::cout << "Вы находитесь здесь: " << level << " "
              << child_type << "(" << parent_value << ") "
              << arr[current_index] << "\n";
}

int main(int argc, char** argv) {
    // Пример 1
    //int arr[] = {1, 3, 6, 5, 9, 8};
    //int arr[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int arr[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int size = sizeof(arr) / sizeof(int);
    print_pyramid(arr, size);
    std::cout << "\n";

    int current_index = 0;
    std::string command;
    
    do {
        print_location(arr, size, current_index);
        
        std::cout << "Введите команду (доступные команды: up, left, right, exit): ";
        std::cin >> command;

        int command_code = get_command_code(command);
        bool success = false;

        switch (command_code) {
            case CMD_UP:
                int new_parrent_index;
                if (try_get_parent(current_index, new_parrent_index)) {
                    current_index = new_parrent_index;
                    success = true;
                } else {
                    std::cout << "Ошибка! Отсутствует родитель\n";
                }
                break;
                
            case CMD_LEFT:
                int new_child_index;
                if (try_get_child(current_index, size, Sides::LEFT, new_child_index)) {
                    current_index = new_child_index;
                    success = true;
                } else {
                    std::cout << "Ошибка! Отсутствует левый потомок\n";
                }
                break;
                
            case CMD_RIGHT:
                    if (try_get_child(current_index, size, Sides::RIGHT, new_child_index)) {
                    current_index = new_child_index;
                    success = true;
                } else {
                    std::cout << "Ошибка! Отсутствует правый потомок\n";
                }
                break;
                
            case CMD_EXIT:

                return 0; 
                
            case CMD_UNKNOWN:
            default:
                std::cout << "Неизвестная команда. Доступные команды: up, left, right, exit\n";
                break;
        }        

        if (success) {
            std::cout << "Ок\n";
        }
        
    } while (true);


    return 0;
}