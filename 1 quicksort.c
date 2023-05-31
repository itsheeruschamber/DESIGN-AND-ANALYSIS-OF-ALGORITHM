#include <stdio.h>
void swap(int* a,int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int x[],int l,int r)
{
	int pivot=x[r];
	int i=l-1;
	int j;
	for ( j=l;j<r;j++)
	{
		if (x[j]<pivot)
		{
			i++;
			swap(&x[i],&x[j]);
		}
	}
	swap(&x[i+1],&x[r]);
	return(i+1);
}
void quickSort(int x[],int l,int r)
{
	if(l<r)
	{
		int pivotindex=partition(x,l,r);
		quickSort(x,l,pivotindex-1);
		quickSort(x,pivotindex+1,r);
	}
}
void printarray(int x[],int size_t)
{
	int i;
	for(i=0;i<size_t;i++)
	{
		printf("%d\t",x[i]);
	}
}
int main()
{
	int x[]={23,45,12,78,3};
	int n=sizeof(x)/sizeof(x[0]);
	quickSort(x,0,n-1);
	printarray(x,n);
	return 0;
}


