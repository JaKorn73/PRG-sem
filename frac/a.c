#include <stdio.h>
#include <complex.h>

int main() {
    double real_part, imag_part;

    printf("Enter the real part of the complex number: ");
    scanf("%lf", &real_part);

    printf("Enter the imaginary part of the complex number: ");
    scanf("%lf", &imag_part);

    // Create a complex number
    double complex num = real_part + imag_part * I;

    // Compute the absolute value
    double abs_value = cabs(num);

    // Print the absolute value
    printf("Absolute value of the complex number: %lf\n", abs_value);

    return 0;
}