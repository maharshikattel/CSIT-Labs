#include<stdio.h>
#include<stdlib.h>

//Queue as an ADT

int enqueue(int *tail)
{
	int new_element;
	printf("Enter the element to enqueue: ");
	scanf("%d", &new_element);
	(*tail)++;
	*tail = new_element;
}

int dequeue(int *head)
{
		printf("The element %d has been dequeued.", *head);
		(*head)++;
}

int peek(int *head)
{
	printf("%d lies in the queue.\n", *head);
}

int main()
{
	int *p, *head, *tail, i, n;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);
	p = (int*)malloc(n*sizeof(int));
	head = p;
	tail = p;
	printf("Enter the elements of the array: ");
	for(i=0;i<n;i++)
	{
		printf("\nElement %d: ", i);
		scanf("%d", p+i);
		*tail = *(p+i);
	}
	char choice;
	printf("Select 'a' to enqueue, 'b' to dequeue and 'c' to peek: ");
	scanf(" %c", &choice);
	switch(choice)
	{
		case 'a':
			enqueue(tail);
		case 'b':
			dequeue(head);
		case 'c':	
			peek(head);
		default:
			printf("Invalid input");
	}
	free(p);
	return 0;
}
