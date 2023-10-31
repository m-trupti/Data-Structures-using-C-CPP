#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int a[20],b[20],c[20];
int n,i,pos,val,temp,m,j,p,k,num;
int choice;
void create(int num,int x[15]);
void display(int num,int x[15]);
void merge();
void sort(int num, int x[15]);

int main()
{
int ch;
do
{
printf("\nMenu\n");
printf("1. Create\n");
printf("2. Display \n");
printf("3. Merge\n");
printf("\n Enter your choice\t");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n\nEnter the number of elements in an array\n");
scanf("%d",&n);
create(n,a);
break;
case 2:
	display(n,a);
	break;
case 3:
merge();
break;
default: 
printf("\nInvalid Choice..\n");
break;
}
printf("\nDo you want to continue??\n\n1=Yes\n\n2=No\n");
scanf("%d",&choice);
}while(choice==1);
return 0;
}

void create(int num,int x[15])
{
printf("\nEnter the elements of the array:\n\n");
for(i=0;i<num;i++)
{
scanf("%d",&x[i]);
}
printf("\nThe elements of the array \n");
display(num,x);
}

void display(int num,int x[15])
{
for(i=0;i<num;i++)
{
printf("%d\t",x[i]);
}
}

void sort(int num, int x[15])
{
for(i=0;i<num;i++)
{
for(j=0;j<num-1-i;j++)
{
if(x[j]>x[j+1])
{
temp=x[j];
x[j]=x[j+1];
x[j+1]=temp;
}
}
}
display(num,x);
}

void merge() 
{
printf("\nEnter the size of the second array:\t");
scanf("%d",&m);
printf("\nEnter the elements for the second array:\n");
create(m,b);
printf("\nThe sorted elements of the array A\n");
sort(n,a);
printf("\nThe sorted elements of the array B\n");
sort(m,b);
i=0,j=0,k=0;
p=n+m;
while((i<n) && (j<m))
	{
	if(a[i]<b[j])
	{
	 c[k++]=a[i++]; 
//	 i++;
//	 k++;
	}
	else if(a[i]>b[j])
	{
	 c[k++]=b[j++];
//	j++;
//	k++;
	}
}
while(i<n)
c[k++]=a[i++];
while(j<m)
c[k++]=b[j++];

printf("\n\nArray elements after merging:\n\n");
display(p,c);
}


