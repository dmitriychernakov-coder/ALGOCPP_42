#include <iostream>



int fibonacci(int n, int mem[]) {
    if(mem[n] != (-1)) {
        return mem[n];
    }
    mem[n] = fibonacci(n-1, mem) + fibonacci(n-2, mem);
    return mem[n];
}

int  main(int argc, char** argv) {
    const int n = 10;

    int fibonacci_num[n + 1];
    fibonacci_num[0] = 0;
    fibonacci_num[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        fibonacci_num[i] = (-1);
    }
    
    fibonacci(n,fibonacci_num);


    for (int i = 0; i < n + 1; i++) {
        std::cout << fibonacci_num[i] << std::endl; 
    }

    return 0;
}