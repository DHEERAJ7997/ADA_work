#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

// Function to sort items by value/weight ratio in descending order
void sortItems(Item items[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(items[j].ratio > items[i].ratio) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

double fractionalKnapsack(int W, Item items[], int n) {
     
    sortItems(items, n);
    double totalValue = 0.0;
    
    for(int i = 0; i < n; i++) {
        if(items[i].weight <= W) {
            W -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];
    srand(time(0)); 
    
    for(int i = 0; i < n; i++) {
        items[i].value = rand() % 1000 + 1;   // avoid 0
        items[i].weight = rand() % 1000 + 1;  // avoid divide by 0
        items[i].ratio = (double) items[i].value / items[i].weight;
    }
     
    W=60;

    clock_t start, end;
    start = clock();
    double maxValue = fractionalKnapsack(W, items, n);
    end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Maximum value in knapsack = %.2lf\n", maxValue);
    printf("Time taken = %lf seconds\n", elapsed_time);
    
    return 0;
}
