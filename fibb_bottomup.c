#include <stdio.h>
#include <time.h>

long long fibonacci(int n) {
    if (n <= 1) return n;

    long long dp[n+1];  // array to store Fibonacci numbers
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int iterations=100000;
    clock_t start = clock();

    for(int i=0;i<iterations;i++){
    long long result = fibonacci(n);
    }
    clock_t end = clock();
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %lf ms\n", time_taken/iterations*1000);

    return 0;
}
