#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Matrixmultiplication(int n, int matrix1[n][n], int matrix2[n][n]) {
    int matrix3[n][n];
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix3[i][j] = 0;
            for (int k = 0; k < n; k++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void generateRandomArray(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 1000; // random numbers up to 999
        }
    }
}
         
int main() {
    srand(time(NULL));
   
    clock_t start, end;
    int iterations = 1000;
     
    int n;
    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);
 
    int matrix1[n][n], matrix2[n][n];


    start = clock();
                     
    for (int i = 0; i < iterations; i++) {
        generateRandomArray(n, matrix1);
        generateRandomArray(n, matrix2);
        Matrixmultiplication(n, matrix1, matrix2);
    }
   
    end = clock();
   
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    double avg_ms = (time_taken / iterations) * 1000.0;
   
    printf("Average time taken for n=%d over %d iterations is %lf ms\n", n, iterations, avg_ms);
               
    return 0;
}
