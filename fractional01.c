#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    int weight;
} Item;

// Function to return maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 0/1 Knapsack using dynamic 2D allocation
int zeroOneKnapsack(int n, int W, Item items[]) {
    // allocate memory for 2D dp array
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((W + 1) * sizeof(int));
    }
     
    // build dp table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (items[i - 1].weight <= w)
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
      
    int result = dp[n][W];

    // free allocated memory
    for (int i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);

    return result;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item));

    srand(time(0));
    // Generate random values and weights
    for (int i = 0; i < n; i++) {
        items[i].value = rand() % 100 + 1;
        items[i].weight = rand() % 50 + 1;
    }
          
    W=60;

    clock_t start = clock();

    int totalValue = zeroOneKnapsack(n, W, items);
    
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nMaximum value: %d\n", totalValue);
    printf("Execution time: %.6f seconds\n", time_taken);

    free(items);
    return 0;
}
