// Gene Cedric D. Alejo and Nicole Kate T. Uy - S12

float dot_product_c(const float* a, const float* b, size_t n) {
	float temp, sum = 0;
	for (int i = 0; i < n; i++) {
		temp = a[i] * b[i];
		sum += temp;
	}
    return sum;
}
