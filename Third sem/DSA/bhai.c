#include<stdio.h>
#include<conio.h>

int main()
{
	float l;
	int b; 
	float Division;
	printf("Enter the length: ");
	scanf("%d", &l);
	printf("Enter the breadth: ",&b);
	scanf("%d", &b);
	Division = l/b;
	printf("The area is: %f",Division);
	return 0;
}
