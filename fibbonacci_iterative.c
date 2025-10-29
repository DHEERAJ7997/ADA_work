#include <stdio.h>
#include <time.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n, result;
    clock_t start, end;
    double cpu_time_used;
    int iterations = 100000;  

    printf("Enter the n: ");
    scanf("%d", &n);

    // Start measuring time
    start = clock();

    for (int i = 0; i < iterations; i++) {
        result = fibonacci(n);
    }

    // End measuring time
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Average time per iteration: %f milli seconds\n", cpu_time_used / iterations*1000);

    return 0;
}
