#include <stdio.h>
#include <time.h>

// Recursive Fibonacci function
int fib_recursive(int n) {
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}
        
int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;
    
    printf("Enter value of n: ");
    scanf("%d", &n);
      
    // Record start time
    start = clock();
     
    fib_recursive(n);

    // Record end time
    end = clock();
    
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}


