#include <stdio.h>
#include <stdlib.h>

int** matMult(int **a, int **b, int size) {
    // (4) Implement your matrix multiplication here. 
    // Create a new matrix to store the product.
    int **res = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        *(res + i) = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Initialize the element to 0
            *(*(res + i) + j) = 0;
            for (int k = 0; k < size; k++) {
                // res[i][j] += a[i][k] * b[k][j]
                *(*(res + i) + j) += (*(*(a + i) + k)) * (*(*(b + k) + j));
            }
        }
    }
    return res;
}

void printArray(int **arr, int n) {
    // (2) Implement your printArray function here
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Using n to match the function parameter
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n = 3; // Example size, you can change this or add a scanf
    int **matA, **matB, **matC;

    // (1) Define 2 (n x n) arrays (matrices) using malloc. 
    matA = (int **)malloc(n * sizeof(int *));
    matB = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        *(matA + i) = (int *)malloc(n * sizeof(int));
        *(matB + i) = (int *)malloc(n * sizeof(int));
        
        // Filling with dummy data for demonstration
        for (int j = 0; j < n; j++) {
            *(*(matA + i) + j) = i + j;
            *(*(matB + i) + j) = i * j;
        }
    }

    // (3) Call printArray to print out the 2 arrays here.
    printf("Matrix A:\n");
    printArray(matA, n);
    printf("Matrix B:\n");
    printArray(matB, n);
    
    // (5) Call matMult to multiply the 2 arrays here.
    matC = matMult(matA, matB, n);
    
    // (6) Call printArray to print out resulting array here.
    printf("Resulting Matrix C:\n");
    printArray(matC, n);
    return 0;
}