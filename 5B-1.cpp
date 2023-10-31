#include<iostream>
using namespace std;
int main()
{
	int n,i,j,temp,min;
	cout<<"Enter number of elements in array : \n";
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
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	cout<<"\n Elements of sorted array are : ";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	return 0;
}

