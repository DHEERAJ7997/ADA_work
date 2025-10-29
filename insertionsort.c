#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;
        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000; // random numbers up to 9999
    }
}
int main()
{
    int iterations = 1000;
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    clock_t start = clock();
    for (int i = 0; i < iterations; i++)
    {
        generateRandomArray(arr, n); // fill with random numbers each
        insertionSort(arr, n);
    }
    clock_t end = clock();
    double total_time = (double)(end - start) / CLOCKS_PER_SEC;
    double avg_ms = (total_time / iterations) * 1000.0;

    printf("Average time per iteration: %f ms\n", avg_ms);
    free(arr);
    return 0;
}