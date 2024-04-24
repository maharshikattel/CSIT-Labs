#include <stdio.h>

// Function to find the greatest common divisor (GCD) of two numbers recursively
int gcd(int a, int b) {
    // Base case: If one of the numbers is 0, return the other number
    if (b == 0)
        return a;
    // Recursive case: GCD(a, b) = GCD(b, a % b)
    else
        return gcd(b, a % b);
}

int main() {
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Calculate and print the GCD of the two numbers
    printf("GCD(%d, %d) = %d\n", num1, num2, gcd(num1, num2));

    return 0;
}

