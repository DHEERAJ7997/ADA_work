#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
        MergeSort(arr, 0, n - 1);
    }
    clock_t end = clock();
    double total_time = (double)(end - start) / CLOCKS_PER_SEC;
    double avg_ms = (total_time / iterations) * 1000.0;
    printf("Average time per iteration: %f ms\n", avg_ms);
    free(arr);
    return 0;
}