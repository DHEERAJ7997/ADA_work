#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int **allocMatrix(int n) {
    int **mat = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        mat[i] = calloc(n, sizeof(int));
    }
    return mat;
}

void freeMatrix(int **mat, int n) {
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}

void addMatrix(int n, int **a, int **b, int **result) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = a[i][j] + b[i][j];
}


void subMatrix(int n, int **a, int **b, int **result) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = a[i][j] - b[i][j];
}




void strassen(int n, int **A, int **B, int **C) {
    if (n <= 2) { // base case
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                C[i][j] = 0;
                for (int k = 0; k < n; k++)
                    C[i][j] += A[i][k] * B[k][j];
            }
        return;
    }


    int k = n / 2;


    // Allocate submatrices
    int **A11 = allocMatrix(k), **A12 = allocMatrix(k),
         **A21 = allocMatrix(k), **A22 = allocMatrix(k);
    int **B11 = allocMatrix(k), **B12 = allocMatrix(k),
         **B21 = allocMatrix(k), **B22 = allocMatrix(k);
    int **C11 = allocMatrix(k), **C12 = allocMatrix(k),
         **C21 = allocMatrix(k), **C22 = allocMatrix(k);


    int **M1 = allocMatrix(k), **M2 = allocMatrix(k), **M3 = allocMatrix(k),
         **M4 = allocMatrix(k), **M5 = allocMatrix(k), **M6 = allocMatrix(k),
         **M7 = allocMatrix(k);
    int **T1 = allocMatrix(k), **T2 = allocMatrix(k);


    // Split A and B into submatrices
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];


            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }


    addMatrix(k, A11, A22, T1);
    addMatrix(k, B11, B22, T2);
    strassen(k, T1, T2, M1);


    addMatrix(k, A21, A22, T1);
    strassen(k, T1, B11, M2);


    subMatrix(k, B12, B22, T1);
    strassen(k, A11, T1, M3);


    subMatrix(k, B21, B11, T1);
    strassen(k, A22, T1, M4);


    addMatrix(k, A11, A12, T1);
    strassen(k, T1, B22, M5);


    subMatrix(k, A21, A11, T1);
    addMatrix(k, B11, B12, T2);
    strassen(k, T1, T2, M6);


    subMatrix(k, A12, A22, T1);
    addMatrix(k, B21, B22, T2);
    strassen(k, T1, T2, M7);


    // Compute C submatrices
    addMatrix(k, M1, M4, T1);
    subMatrix(k, T1, M5, T2);
    addMatrix(k, T2, M7, C11);


    addMatrix(k, M3, M5, C12);
    addMatrix(k, M2, M4, C21);


    subMatrix(k, M1, M2, T1);
    addMatrix(k, T1, M3, T2);
    addMatrix(k, T2, M6, C22);


    // Merge into C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }


    // Free memory
    freeMatrix(A11, k); freeMatrix(A12, k); freeMatrix(A21, k); freeMatrix(A22, k);
    freeMatrix(B11, k); freeMatrix(B12, k); freeMatrix(B21, k); freeMatrix(B22, k);
    freeMatrix(C11, k); freeMatrix(C12, k); freeMatrix(C21, k); freeMatrix(C22, k);
    freeMatrix(M1, k); freeMatrix(M2, k); freeMatrix(M3, k); freeMatrix(M4, k);
    freeMatrix(M5, k); freeMatrix(M6, k); freeMatrix(M7, k);
    freeMatrix(T1, k); freeMatrix(T2, k);
}


// Find next power of 2
int nextPowerOf2(int n) {
    int p = 1;
    while (p < n) p *= 2;
    return p;
}


int main() {


    srand(time(NULL));
    int n;
    printf("Enter matrix size n x n: ");
    scanf("%d", &n);
    int iterations=100;


    int m = nextPowerOf2(n); // pad to power of 2


    int **A = allocMatrix(m);
    int **B = allocMatrix(m);
    int **C = allocMatrix(m);


    // Fill A and B with random values, pad with 0s
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i < n && j < n) {
                A[i][j] = rand() % 100;
                B[i][j] = rand() % 100;
            } else {
                A[i][j] = 0;
                B[i][j] = 0;
            }
        }
    }


    clock_t start = clock();


    for(int i=0;i<iterations;i++){
    strassen(m, A, B, C);
    }


    clock_t end = clock();


    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    double avg_ms = (time_taken / iterations) * 1000.0;


    printf("Average time taken for n=%d over %d iterations is %lf ms\n", m, iterations, avg_ms);


    return 0;


    freeMatrix(A, m);
    freeMatrix(B, m);
    freeMatrix(C, m);
    return 0;
}
