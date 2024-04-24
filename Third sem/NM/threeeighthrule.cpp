#include <stdio.h>
#include <math.h>

// Function to integrate
double function(double x) {
    return cos(x); // Replace with your desired function
}

// Simpson's 3/8 rule for numerical integration
double simpsonsThreeEighthRule(double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double sum = function(a) + function(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0)
            sum += 2 * function(x);
        else
            sum += 3 * function(x);
    }

    return (3 * h / 8.0) * sum;
}

int main() {
    double a = 1.0; // Lower limit of integration
    double b = 3.0; // Upper limit of integration
    int n = 6; // Number of subintervals (must be multiple of 3)
    double result = simpsonsThreeEighthRule(a, b, n);

    printf("Numerical integration result using Simpson's 3/8 rule: %lf\n", result);
    return 0;
}
