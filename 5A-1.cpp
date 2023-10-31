#include<iostream>
using namespace std;
int main()
{
	int n,i,j,temp;
	cout<<"Enter number of elements in array : ";
	cin>>n;
	int a[n];
	cout<<"Enter elements : \n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"\n Elements of unsorted array are : ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" \t";
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	cout<<"\n Elements of sorted array are : ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	return 0;
}

