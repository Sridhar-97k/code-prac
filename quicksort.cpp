/*
 * quicksort.cpp
 *
 *  Created on: 14-Jul-2019
 *      Author: Sridhar
 */
#include<iostream>
using namespace std;

void quickSort(int*,int,int);
int paritiion(int*,int,int);
void swap_add(int*,int*);
void showArray(int*,int);

void showArray(int a[],int size)
{
		int i=0;
			cout<<"The array is "<<endl;
		for(i=0;i<size;i++)
		{
			cout<<i<<")"<<a[i]<<" "<<endl;
		}
return;
}
void swap_add(int *a ,int *b)
{
int temp=(*a);
(*a)=(*b);
(*b)=temp;
}
int partition(int a[],int l ,int r )
{
int pivot=a[r],i,j;

i=l;
j=r-1;
while(1){
while(a[i]<pivot)
	{
			
		i++;
	}
	while(a[j]>pivot)
	{
		j--;
	}
	swap_add(a+i,a+j);

	if(i>=j)
	{
		swap_add(a+i,a+l);
		return i;
		
	}
	}
}
void quickSort(int arr[],int l,int r)
{
	if(l<r){
int index=partition(arr,l,r);
cout<<"Partition found as "<<*(arr+index)<<endl;
quickSort(arr,l,index-1);
quickSort(arr,index+1,r);
	}
	return ;
}


int main()
{
int array[]={2,8,4,1,0,9,2,3};
int size=sizeof(array)/sizeof(array[0]);
showArray(array,size);
quickSort(array,0,size-1);
showArray(array,size);

}
