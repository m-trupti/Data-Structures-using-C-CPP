#include<iostream>
using namespace std; 

void inSort(int a[], int n)
{  
    int i,j,temp;  
    for (i=1;i<n;i++) 
    {  
        temp = a[i];  
        j = i-1;  
        while (j>=0 && a[j]>temp) 
        {  
            a[j+1] = a[j];  
            j--;  
        }  
        a[j+1] = temp;  
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
	cout<<"Array before insertion sort : "<<endl;
	display(a, n);
    inSort(a, n);
	cout<<"Array after insertion sort : "<<endl; 
    display(a, n);  
    return 0;  
}  
