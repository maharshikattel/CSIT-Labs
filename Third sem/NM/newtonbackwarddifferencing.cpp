#include <stdio.h>

// Tabulated data points
double x[] = {1.0, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6}; // x values
double y[] = {7.989, 8.403, 8.781, 9.129, 9.451, 9.750, 10.031}; // y values

// Numerical differentiation using backward difference
double backwardDifference(int index) {
    double h = x[index] - x[index - 1];
    return (y[index - 2] - 4 * y[index - 1] + 3 * y[index]) / (2 * h);
}

int main() {
    int index = 2; // Index corresponding to the value at 1.2
    double result = backwardDifference(index);

    printf("Numerical differentiation result using backward difference: %.4lf\n", result);
    return 0;
}
