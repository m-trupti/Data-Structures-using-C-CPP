#include<iostream>
using namespace std;

int search(int n,int arr[])
{
	int val;
	int pos;
	cout<<"Enter element to be searched : "<<endl;
	cin>>val;
	for(int j=0;j<=n;j++)
	{
		if(arr[j]==val)
		{
			return j;
		}
		if(j==n)
		{
			return -1;
		}
	}
}

int main()
{
  	int n;
	cout<<"Enter size of array : "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter elements of array : "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int res=search(n,arr);
	if(res==-1)
	{
		cout<<"Element not found.";
	}
	else
	{
		cout<<"Element found at position : "<<res;
	}
	return 0;
}
	
