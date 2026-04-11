#include <iostream>

void count_sort(int* arr, int size) {
    const int MIN_VAL = 10;
    const int MAX_VAL = 24;
    int counts[MAX_VAL + 1] = {0};

    for (int i = 0; i < size; ++i) {
        if (arr[i] < MIN_VAL || arr[1] > MAX_VAL) {
            std::cout  << "\033[033mЗначение массива " << arr[i] << " вне диапазона " 
                << MIN_VAL << " - " << MAX_VAL << "!\033[0m" << std::endl;
            return;
        }        
        counts[arr[i]]+=1;
    }

    int c = MIN_VAL;
    for (int i = 0; i < size; ++i) {
        while (counts[c] == 0) {
            c++;
        }
        arr[i] = c;
        counts[c]-=1;
    }
}

void print_array(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "\033[032m" << arr[i] << " \033[0m";
    }
    std::cout << std::endl;

}

int main() {
    //int arr[] = {19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13,
    //  10, 22, 18, 14, 16, 24, 19, 17};
    //int arr[] = {16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11,
    //  19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16};
    //int arr[] = {21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14,
    //  17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10};
    //int arr[] = {1};
    int arr[] = {19, 14, 22, 22, 17, 22, 13, 21, 20, 24};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив:        ";
    print_array(arr, size);

    count_sort(arr, size);

    std::cout << "Отсортированный массив: ";
    print_array(arr, size);

    return 0;
}