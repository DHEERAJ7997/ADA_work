#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minpos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minpos])
            {
                minpos = j;
            }
        }
        swap(&arr[minpos], &arr[i]);
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
        // refill array with random values each iteration
        for (int j = 0; j < n; j++)
        {
            arr[j] = rand() % 100000;
        }
        SelectionSort(arr, n);
    }

    clock_t end = clock();
    double total_time = (double)(end - start) / CLOCKS_PER_SEC;
    double avg_ms = (total_time / iterations) * 1000.0;
    printf("Average time per iteration: %f ms\n", avg_ms);
    free(arr);
    return 0;
}
