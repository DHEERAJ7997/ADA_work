#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int nextPowerOf2(int n) {
    int power = 1;
    while (power < n) power *= 2;
    return power;
}


void addMatrix(int n, int a[n][n], int b[n][n], int result[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = a[i][j] + b[i][j];
}


void multiplyMatrix(int n, int A[n][n], int B[n][n], int C[n][n]) {
   
   if(n<=2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                C[i][j]=0;
                for(int k=0;k<n;k++){
                    C[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
        return;
    }
   
    else{
    int k = n / 2;
   
    // Submatrices
    int A11[k][k], A12[k][k], A21[k][k], A22[k][k];
    int B11[k][k], B12[k][k], B21[k][k], B22[k][k];
    int C11[k][k], C12[k][k], C21[k][k], C22[k][k];
    int temp1[k][k], temp2[k][k];
                                 
    // Dividing matrices A and B into 4 submatrices
                                           
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
     
    multiplyMatrix(k, A11, B11, temp1);
    multiplyMatrix(k, A12, B21, temp2);
    addMatrix(k, temp1, temp2, C11);
   
    multiplyMatrix(k, A11, B12, temp1);
    multiplyMatrix(k, A12, B22, temp2);
    addMatrix(k, temp1, temp2, C12);


    multiplyMatrix(k, A21, B11, temp1);
    multiplyMatrix(k, A22, B21, temp2);
    addMatrix(k, temp1, temp2, C21);
   
    multiplyMatrix(k, A21, B12, temp1);
    multiplyMatrix(k, A22, B22, temp2);
    addMatrix(k, temp1, temp2, C22);
     
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
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
    int iterations = 100;
   
    int n;
    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);
   
    int m = nextPowerOf2(n);
    int matrix1[m][m], matrix2[m][m], matrix3[m][m];
   
    start = clock();
   
    for (int iter = 0; iter < iterations; iter++) {
       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i < n && j < n) {
                    matrix1[i][j] = rand() % 1000;
                    matrix2[i][j] = rand() % 1000;
                } else {
                    matrix1[i][j] = 0;
                    matrix2[i][j] = 0;
                }


                matrix3[i][j] = 0;  
            }
        }
         
        multiplyMatrix(m, matrix1, matrix2, matrix3);
    }


    end = clock();
 
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    double avg_ms = (time_taken / iterations) * 1000.0;


    printf("Average time taken for n=%d over %d iterations is %lf ms\n", m, iterations, avg_ms);


    return 0;
}


