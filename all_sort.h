#include <iostream>

using namespace std;

class Allsort{
	public:
	void quicksort(int a[],int low, int high);//Æ½¾ùÊ±¼ä¸´ÔÓ¶ÈO(NlogN)
	int partion(int a[], int low, int high);
	void mergesort(int a[],int low, int high, int b[]);//Æ½¾ùÊ±¼ä¸´ÔÓ¶ÈO(NlogN)
	void Merge(int a[],int low,int high, int b[]);
	void insertsort(int a[],int n);
	void shellsort(int a[],int n);
	void bublesort(int a[], int n);//Ã°ÅÝÅÅÐòÐ§ÂÊ½ÏµÍO(N^2),ÎÈ¶¨ÅÅÐò
	void selectsort(int a[],int n);//Ö±½ÓÑ¡ÔñÐ§ÂÊ½ÏµÍO(N^2),²»ÎÈ¶¨ÅÅÐò
};

void Allsort::selectsort(int a[], int n)
{
	for (int i=0;i<n;++i)
	{
		int mindex=i;
		for (int j=i+1;j<n;++j)
		{
			if (a[j]<a[mindex])  mindex=j; 
		}
		swap(a[i],a[mindex]);
	}
}

void Allsort::bublesort(int a[], int n)
{
	for (int i=0;i<n-1;++i)//ÍâÑ­»·±íÊ¾´ÎÊý£¬×î´óÊý³Áµ×µÄ´ÎÊýÎªN
	{
		for (int j=1;j<n-i;++j)
		{
			if (a[j-1]>a[j])
			{
				swap(a[j-1],a[j]);
			}
		}
	}
}

void Allsort::shellsort(int a[],int n)
{
	for (int gap=n/2;gap>0;gap /= 2)
	{
		for (int i=gap;i<n;i += gap)
		{
			if (a[i]<a[i-gap])
			{
				int j=i-gap;
				int key=a[i];
				while(j>=0 && a[j]>key)
				{
					a[j+gap]=a[j];
					j -= gap;
				}
				a[j+gap]=key;
			}
		}
	}
}

void Allsort::insertsort(int a[],int n)
{
	for (int i=1;i<n;++i)
	{
		if (a[i]<a[i-1])
		{
			int j=i-1;
			int key=a[i];
			while(j>=0 && a[j]>key)
			{
				a[j+1]=a[j];
				--j;
			}
			a[j+1]=key;
		}

	}
}

void Allsort::mergesort(int a[],int low, int high, int b[])
{
	if (low < high)
	{
		int mid=(low+high)/2;
		mergesort(a,low,mid,b);
		mergesort(a,mid+1,high,b);
		Merge(a,low,high,b);
	}
}

void Allsort::Merge(int a[],int low,int high, int b[])
{
	int mid=(low+high)/2;
	int i=low,j=mid+1;
	int m=mid,n=high;
	int k=0;

	while(i<=m && j<=n)
	{
		if (a[i]<=a[j])  b[k++]=a[i++];
		else b[k++]=a[j++];
	}
	while(i<=m)  b[k++]=a[i++];
	while(j<=n)  b[k++]=a[j++];
	for (i=0;i<k;++i)
	{
		a[low+i]=b[i];
		//a[low++]=b[i];
	}

}

int Allsort::partion(int a[], int low, int high)
{
	int pivot = a[low];
	while(low < high)
	{
		while(low<high && a[high]>=pivot)  --high;
		swap(a[low],a[high]);

		while(low<high && a[low]<=pivot)  ++low;
		swap(a[low],a[high]);
	}
	return low;
}

void Allsort::quicksort(int a[],int low, int high)
{
	if (low < high)
	{
		int key=partion(a,low,high);
		quicksort(a,low,key-1);
		quicksort(a,key+1,high);
	}
}





