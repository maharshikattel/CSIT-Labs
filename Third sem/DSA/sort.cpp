#include<iostream>
using namespace std;
int main()
{
int a[5]={5,2,6,4,1};
int i,j,n=5;
int temp; 
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
}
	for(i=n-1;i>=0;i--)
	{
	cout<<a[i]<<endl;
	}
}
