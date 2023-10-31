#include<iostream>
using namespace std;
void merge(int a[],int beg,int mid,int end)
{
	int i=beg,j=mid,index=beg,temp[10],k;
	while((i<=mid) && (j<=end))
	{
		if(a[i]<a[j])
		{
			temp[index]=a[i];
			i++;
			index++;
		}
		
		else
		{
			temp[index]=a[j];
			j++;
			index++;
		}
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index]=a[j];
			j++;
			index++;
		}
	}
	else
	{
		while(k>mid)
		{
		 temp[index]=a[i];
		 i++;	
		 index++;
		}
	}	
for(k=beg;k<index;k++)
{
	a[k]=temp[k];
}
}
mergeSort(int a[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		mergeSort(a,beg,mid);
		mergeSort(a,mid+1,end);
		merge(a,beg,mid,end);
	}
}
void display(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << a[i] << " ";
    cout << endl; 
}  
int main()  
{  
    int n;
	cout<<"Enter size of array : "<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter elements of array : "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Array before sort : "<<endl;
	display(a, n);
	cout<<"Array after sort : "<<endl;
	mergeSort(a,0,n-1); 
    display(a, n);  
    return 0;  
}  
