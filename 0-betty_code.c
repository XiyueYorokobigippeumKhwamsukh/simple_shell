#include <stdio.h>

/**
  * calculateSum - calculates the sum of two numbers
  * @num1: First number input
  * @num2: Second number input
  * Return: sum
  */

int calculateSum(int num1, int num2)
{
	int sum;

	sum = num1 + num2;
	return (sum);
}

/**
  * main - Entry point
  * Return: Always 0
  */

int main(void)
{
	int num1, num2, result;

	printf("Enter two numbers: ");
	scanf("%d %d", &num1, &num2);

	result = calculateSum(num1, num2);

	printf("The sum of num1 + num2 is %d\n", result);

	return (0);
}
