#include <stdio.h>

// Define a structure for complex numbers
struct Complex {
    double real;
    double imag;
};

// Function to add two complex numbers
struct Complex add(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

// Function to subtract two complex numbers
struct Complex subtract(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real - num2.real;
    result.imag = num1.imag - num2.imag;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiply(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    result.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
    return result;
}

int main() {
    struct Complex num1, num2, sum, diff, product;

    // Input first complex number
    printf("Enter real and imaginary part of first complex number: ");
    scanf("%lf %lf", &num1.real, &num1.imag);

    // Input second complex number
    printf("Enter real and imaginary part of second complex number: ");
    scanf("%lf %lf", &num2.real, &num2.imag);

    // Perform operations
    sum = add(num1, num2);
    diff = subtract(num1, num2);
    product = multiply(num1, num2);

    // Display results
    printf("Sum: %.2lf + %.2lfi\n", sum.real, sum.imag);
    printf("Difference: %.2lf + %.2lfi\n", diff.real, diff.imag);
    printf("Product: %.2lf + %.2lfi\n", product.real, product.imag);

    return 0;
}
