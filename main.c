#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void asmhello();

extern int summ(int a1, int a2, int a3, int a4, int a5, int a6, int a7);

int main() {
	asmhello();
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
	return 0;
}