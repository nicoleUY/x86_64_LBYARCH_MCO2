#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void asmhello();

extern int summ(int a1, int a2, int a3, int a4, int a5, int a6, int a7);

//ACTUAL PROJECT
extern float get_input();

void c_dot_product();

int main() {

	//asmhello();
	/*
	int a1, a2, a3, a4, a5, a6, a7, x;
	a1 = 1;
	a2 = 2;
	a3 = 3;
	a4 = 4;
	a5 = 5;
	a6 = 6;
	a7 = 100;
	x = summ(a1, a2, a3, a4, a5, a6, a7);
	printf("%d + %d + %d + %d + %d + %d + %d = %d \n", a1, a2, a3, a4, a5, a6, a7, x);*/

	//ACTUAL PROJECT
	//get_input();
	c_dot_product();


	return 0;
}

void c_dot_product() {
	int i, n;
	char dump;
	float A[20]; //i put 10 for now, dont remember how to declare if dk the thing yet
	float B[20];
	float temp, sum=0;

	printf("THIS IS FOR CALCULATING USING C\n");

	//GETTING INPUT
	printf("Enter scalar variable n: ");
	scanf_s("%d", &n);

	printf("Enter values of vector A (single precision): ");
	for (i = 0; i < n; i++) {
		scanf_s("%f", &A[i]);
		scanf_s("%c", &dump, 1);
	}
	printf("Enter values of vector B (single precision): ");
	for (i = 0; i < n; i++) {
		scanf_s("%f", &B[i]);
		scanf_s("%c", &dump, 1);
	}
	printf("These are the values for A: \n");
	for (i = 0; i < n; i++) {
		printf("%.2f \n", A[i]);
	}
	printf("These are the values for B: \n");
	for (i = 0; i < n; i++) {
		printf("%.2f \n", B[i]);
	}

	for (i = 0; i < n; i++) {
		temp = A[i] * B[i];
		sum += temp;
		printf("%d: %.2f  ", i, temp);
	}
	printf("\nDot product: %.2f", sum);
}