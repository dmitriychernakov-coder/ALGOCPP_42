#include <iostream>

int fibonacci(int n) {
    if(1 >= n) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int  main(int argc, char** argv) {
    const int n = 10;
    int fibonacci_num[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        fibonacci_num[i] = fibonacci(i);
        std::cout << fibonacci_num[i] << std::endl;
    }
    return 0;
}