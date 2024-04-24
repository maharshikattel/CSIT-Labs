//WAP to implement Binary Search & Sequential search

#include<iostream>
using namespace std;
#define MAX 7;

int sequential_search(int a[], int n);
int binary_search(int a[], int n);
int main(){
	int a[6], n, i;
	printf("Enter the elements of the list");
	for(i=0;i<7;i++)
	{
		printf("\nElement %d:",i);
		cin>>a[i];
	}
	cout<<"\nWhat number are you searching for?";
	{
		cin>>n;
	}
//	printf("\nThe number %d is at the position %d in the list.", n, sequential_search(a, n));
	printf("\nThe number %d is at the position %d in the list."), n, binary_search(a,n));
	return 0;
}

int binary_search(int a[], int n)
{
	//To sort
	int temp,j;
	for(i=1; i<n; i++)
	{
		for(j=0;j<n-i; j++)
		{
		if(a[j+1]>a[j])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}	
	}
	
	if(a[7%2]<n)
	{
		if(a[3%2]<n)
		{
			if(a[1%2]==n)
			{
				return 0;	
			}
		}
		else if (a[3%2]n)
			{
				return 1;
			}
		else
			{
				
			}
	}
}


int sequential_search(int a[], int n)
{
	for (int i=0; i<7; i++)
	{
		if(a[i]==n)
		return i;
		
	}
	cout<<"Element doesnt belong to the stack";
}
