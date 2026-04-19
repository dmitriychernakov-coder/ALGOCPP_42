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

int main(int argc, char** argv) {
    // Пример 1
    //int arr[] = {1, 3, 6, 5, 9, 8};
    //int arr[] = {94, 67, 18, 44, 55, 12, 6, 42};
    int arr[] = {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    int size = sizeof(arr) / sizeof(int);
    print_pyramid(arr, size);
    std::cout << "\n";
    return 0;
}