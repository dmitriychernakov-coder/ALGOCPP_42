#include <iostream>

void merge(int* base_array, int* a_block, int a_size, int* b_block, int b_size) {
    int* c_block = new int[a_size + b_size];
    int a{0};
    int b{0};
    int c{0};

    while (a < a_size && b < b_size) {
        if (a_block[a] <= b_block[b]) {
            c_block[c] = a_block[a];
            a++;
        } else {
            c_block[c] = b_block[b];
            b++;
        }
        c++;
    }

    while (a < a_size) {
        c_block[c] = a_block[a];
        a++; c++;
    }
    while (b < b_size) {
        c_block[c] = b_block[b];
        b++; c++;
    }

    for (int i = 0; i < a_size + b_size; ++i) {
        base_array[a_block - base_array + i] = c_block[i];
    }

    delete[] c_block;
}

void merge_sort(int* base_array, int* current_block, int block_size) {
    if (block_size <= 1) {
        return;
    }

    int middle = block_size / 2;

    int* a_block = current_block;
    int* b_block = current_block + middle;

    merge_sort(base_array, a_block, middle);
    merge_sort(base_array, b_block, block_size - middle);

    merge(base_array, a_block, middle, b_block, block_size - middle);
}

void merge_sort(int* arr, int size) {
    if (size <= 1) return;
    merge_sort(arr, arr, size);
}


void print_array(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "\033[032m" << arr[i] << " \033[0m";
    }
    std::cout << std::endl;

}
int main(int argc, char** argv) {

    int arr[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    //int arr[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    //int arr[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    //int arr[] ={1};
     
    int size = sizeof(arr) / sizeof(int);
    std::cout << "Исходный массив:        ";
    print_array(arr,size);

    merge_sort(arr, size);

    std::cout << "Отсотированный  массив: ";
    print_array(arr,size);

    return 0;
}