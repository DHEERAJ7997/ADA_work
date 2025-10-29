#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (1)
    {

        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(&arr[i], &arr[j]);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
    }
}
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
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
        generateRandomArray(arr, n); // fill with random
        quickSort(arr, 0, n - 1);
    }

    clock_t end = clock();

    double total_time = (double)(end - start) /
                        CLOCKS_PER_SEC;
    double avg_ms = (total_time / iterations) * 1000.0;
    printf("Average time per iteration: %f ms\n", avg_ms);
    free(arr);
    return 0;
}