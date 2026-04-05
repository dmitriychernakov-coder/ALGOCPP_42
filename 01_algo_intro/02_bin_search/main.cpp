#include<iostream>

int countside(int arr[],int size,int point){
    int left{0};
    int right = size;
    while (left < right){
        int mid = left + ((right - left) / 2);
        if (arr[mid] > point){
            right = mid;
        } else {
            left = mid + 1;
        }              
    }
    return size - left;

}

int  main(int argc, char** argv)
{
    int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
    int size = sizeof(arr)/sizeof(arr[0]);
    int point;
    std::cout << "Введите точку отсчета: " ;
    std::cin >> point;
    int result = countside(arr, size, point);
    std::cout << "Количество элементов в массиве больших, чем  " << point <<  ": " << result << std::endl;
    return 0;
}