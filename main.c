// Gene Cedric D. Alejo and Nicole Kate T. Uy - S12

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Include the C kernel
#include "c_dp.c" 

// Declare the ASM kernel
extern float dot_product_asm(float* a, float* b, size_t n);

int main() {
    size_t n = pow(2, 30); // Change this to test different vector sizes
    float* a, * b;
    float sdot;

    // Allocate memory for vectors a and b
    a = (float*)malloc(n * sizeof(float));
    b = (float*)malloc(n * sizeof(float));
    if (a == NULL || b == NULL) {
        perror("Memory allocation failed");
        return -1;
    }

    // Generate random floats and store in arrays a and b
    srand((unsigned int)time(NULL)); // Seed the random number generator
    for (size_t i = 0; i < n; i++) {
        a[i] = (float)((double)rand() / RAND_MAX * 200.0 - 100.0); // Cast the result to float
        b[i] = (float)((double)rand() / RAND_MAX * 200.0 - 100.0); // Cast the result to float
    }
    
    double ave_time_spent_c=0, ave_time_spent_asm = 0;

    for (int i = 0; i < 30; i++) {
        // Call C kernel
        clock_t start_c = clock();
        sdot = dot_product_c(a, b, n);
        clock_t end_c = clock();
        double time_spent_c = (double)(end_c - start_c) / CLOCKS_PER_SEC;
        ave_time_spent_c += time_spent_c;
    }
    ave_time_spent_c /= 30;
    printf("C Dot product: %f, Average Time: %f seconds\n", sdot, ave_time_spent_c);

    sdot = 0;

    for (int i = 0; i < 30; i++) {
        // Call ASM kernel
        clock_t start_asm = clock();
        sdot = dot_product_asm(a, b, n);
        clock_t end_asm = clock();
        double time_spent_asm = (double)(end_asm - start_asm) / CLOCKS_PER_SEC;
        ave_time_spent_asm += time_spent_asm;
    }
    ave_time_spent_asm /= 30;
    printf("ASM Dot product: %f, Average Time: %f seconds\n", sdot, ave_time_spent_asm);

    // Free allocated memory
    free(a);
    free(b);
    return 0;
}
