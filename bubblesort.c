#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void BubbleSort(int arr[], int n)
{
    bool flag;

    for (int i = 0; i < n - 1; i++)
    {
        flag = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = false;
            }
        }
        if (flag)
        {

            break;
        }
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
        generateRandomArray(arr, n); // fill with random numbers each time

        BubbleSort(arr, n);
    }

    clock_t end = clock();
    double total_time = (double)(end - start) / CLOCKS_PER_SEC;
    double avg_ms = (total_time / iterations) * 1000.0;
    printf("Average time per iteration: %f ms\n", avg_ms);
    free(arr);
    return 0;
}