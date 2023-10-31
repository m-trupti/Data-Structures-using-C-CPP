#include <iostream> 
using namespace std;

void Merge(int a[], int beg, int end, int mid)
{
    int i, j, k,temp[end-beg+1];
    i = beg;
    k = 0;
    j = mid + 1;
 
    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        temp[k]=a[j];
        k++;
        j++;
    }
 
    for (i=beg;i<=end;i++)
    {
        a[i]=temp[i-beg];
    }
}
 
void MergeSort(int a[], int beg, int end)
{
    int mid;
    if (beg < end)
    {
        mid=(beg+end)/2;
        MergeSort(a,beg,mid);
        MergeSort(a,mid+1,end);
 
        Merge(a,beg,end,mid);
    }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}
 
int main()
{
    int n,i;
    cout<<"Enter size of array : "<<endl;
    cin>>n;
    int arr[n];
 	cout<<"Enter elements of array : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
 	
 	cout << "Unsorted array: \n";
	printArray(arr,n);
	
    MergeSort(arr,0,n-1);
    cout << "Sorted array: \n";
    printArray(arr,n);
 	
    return 0;
}
