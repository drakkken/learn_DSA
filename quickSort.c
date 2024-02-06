#include<stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int n,int l,int h)
{
 int pivot = a[l];
 int i = l;
 int j = h;
 do
	{
		do{i++;}while(a[i]<=pivot);
		do{j--;}while(a[j]>pivot);
		if(i<j)
		swap(&a[i],&a[j]);
	
	}while(i<j);
		
 swap(&a[l],&a[j]);
 return j;
	
}

void QuickSort(int a[],int n,int l,int h)
{
  if(l<h)
	{
		int p = partition(a,n,l,h);
		QuickSort(a,n,l,p);
		QuickSort(a,n,p+1,h);

	}

}


void main()
{
	int a[] = {7,8,5,4,1,2,3,6,9,10};
	QuickSort(a,10,0,9);
	for(int i =0;i<10;i++)
	{
		printf("%d",a[i]);
	}





}
