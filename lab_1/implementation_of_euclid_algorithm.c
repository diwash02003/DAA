#include <stdio.h>

// Function to find GCD using recursive Euclid's algorithm
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int num1, num2;

    // Input two integers
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Calculate GCD
    int result = gcd(num1, num2);

    // Display the result
    printf("GCD of %d and %d is: %d\n", num1, num2, result);

    return 0;
}
