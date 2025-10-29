#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    clock_t start, end;
    double time_taken;
    int iterations = 1000000;
    int n;
    printf("Enter number of elements (n): ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    // we have to fill the array with random values
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    start = clock();
    for (int i = 0; i < iterations; i++)
    {
        int x = binarySearch(arr, 0, n - 1, n); // worst case
    }
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    double avg_ms = (double)(time_taken / iterations) * 1000;

    printf("Time taken for 1000000 iterations is %lf ms (average per search)\n", avg_ms);

    free(arr);
    return 0;
}