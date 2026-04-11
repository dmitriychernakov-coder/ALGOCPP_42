#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


int pivoting(int* arr, int low, int high) {
    int pivot = arr[(low + high) / 2]; 
    int left = low;
    int right = high;
    while (true) {
    while (arr[left] < pivot) {
        left++;
    }
    while (arr[right] > pivot) {
        right-=1;
    }
    if (left >= right) {
        return right;
    }
    swap(arr[left], arr[right]);
    left+=1;
    right-=1;
    }
}

void quick_sort_recursive(int* arr, int low, int high) {
    if (low < high) {
        int pi = pivoting(arr, low, high);
        quick_sort_recursive(arr, low, pi);
        quick_sort_recursive(arr, pi + 1, high);
    }
}

void quick_sort(int* arr, int size) {
    quick_sort_recursive(arr, 0, size - 1);
}

void print_array(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "\033[032m" << arr[i] << " \033[0m";
    }
    std::cout << std::endl;
}

int main() {
    //int arr[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    //int arr[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    //int arr[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int arr[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    //int arr[] ={1};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив:        ";
    print_array(arr, size);

    quick_sort(arr, size);

    std::cout << "Отсортированный массив: ";
    print_array(arr, size);

    return 0;
}


