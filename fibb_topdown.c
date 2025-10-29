#include <stdio.h>
#include <time.h>

#define MAX 1000000   
long long memo[MAX];  

long long fibonacci(int n) {
    if (n <= 1) return n;

    if (memo[n] != -1) return memo[n];

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}


int main() {
    int n;
    printf("Enter n : ");
    scanf("%d", &n);

    // Initialize memo array with -1
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    
    clock_t start = clock();
    
    long long result;

    int iterations=100000;

     for(int i=0;i<iterations;i++){
        result = fibonacci(n);
     }
    
    clock_t end = clock();

    double total_time = ((double)(end - start)) / CLOCKS_PER_SEC; 
    printf("Avg time per run = %f ms\n", (total_time/iterations) * 1000);

    return 0;
}
