// Gene Cedric D. Alejo and Nicole Kate T. Uy - S12

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Include the C kernel
#include "c_dp.c" 

// Declare the ASM kernel
extern float dot_product_asm(float* a, float* b, size_t n);

int main() {
    FILE* file;
    size_t n;
    float* a, * b;
    float sdot;

    // Open the file for reading
    if (fopen_s(&file, "input.txt", "r") != 0) {
        perror("Error opening file");
        return -1;
    }

    // Read vector size from file
    if (fscanf_s(file, "%zu", &n) != 1) {
        perror("Error reading vector size");
        fclose(file);
        return -1;
    }

    // Allocate memory for vectors a and b
    a = (float*)malloc(n * sizeof(float));
    b = (float*)malloc(n * sizeof(float));
    if (a == NULL || b == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return -1;
    }

    // Read floating-point numbers from file
    for (size_t i = 0; i < n; i++) {
        if (fscanf_s(file, "%f", &a[i]) != 1) {
            perror("Error reading floating-point number for array a");
            fclose(file);
            free(a);
            free(b);
            return -1;
        }
    }
    for (size_t i = 0; i < n; i++) {
        if (fscanf_s(file, "%f", &b[i]) != 1) {
            perror("Error reading floating-point number for array b");
            fclose(file);
            free(a);
            free(b);
            return -1;
        }
    }

    // Close the file
    fclose(file);

    // Call C kernel
    clock_t start_c = clock();
    sdot = dot_product_c(a, b, n);
    clock_t end_c = clock();
    double time_spent_c = (double)(end_c - start_c) / CLOCKS_PER_SEC;
    printf("C Dot product: %f, Time: %f seconds\n", sdot, time_spent_c);

    sdot = 0;

    // Call ASM kernel
    clock_t start_asm = clock();
    sdot = dot_product_asm(a, b, n);
    clock_t end_asm = clock();
    double time_spent_asm = (double)(end_asm - start_asm) / CLOCKS_PER_SEC;
    printf("ASM Dot product: %f, Time: %f seconds\n", sdot, time_spent_asm);

    // Free allocated memory
    free(a);
    free(b);
    return 0;
}
