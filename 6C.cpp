#include<iostream>
using namespace std;

int binary(int n,int arr[],int val)
{
	int beg,mid,end,found=0;
	beg=0;end=n-1;
	
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(val==arr[mid])
		{
			found=1;
			return mid;
		}
		else if(val<arr[mid])
		{
			end=mid-1;
		}
		else if(val>arr[mid])
		{
			beg=mid+1;
		}
		if(found==0 && beg>end)
		{
			return -1;
		}
	}
}
void sort(int arr[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int main()
{
  	int i,n,val;
	cout<<"Enter size of array : "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter elements of array : "<<endl;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,n);
	cout<<"\n Elements of sorted array are : ";
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<"\n Enter element to be searched : "<<endl;
	cin>>val;
	int res=binary(n,arr,val);
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
