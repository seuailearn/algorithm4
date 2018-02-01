#ifndef MERGE_H_
#define MERGE_H_
#include<vector>
#include<iostream>
using namespace std;
typedef int T;
void exch(vector<T> & a,int i,int j)
{
	T temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
bool Less(T m,T n)
{
	if(m<n)
		return true;
	else
		return false;
}

extern vector<T> aux;
void merge(vector<T> & a,int lo,int mid,int hi)
{
	int i=lo;
	int j=mid+1;
	for(int k=lo;k<=hi;k++)
		aux[k]=a[k];
	for(int k=lo;k<=hi;k++)
	{
		if(i>mid) 
			a[k]=aux[j++];
		else if(j>hi)
			a[k]=aux[i++];
		else if(Less(aux[j],aux[i]))
			a[k]=aux[j++];
		else 
			a[k]=aux[i++];
	}
}


void show(const vector<int> & a)
{
	int num=a.size();
	cout<<"length is " <<num <<endl;
	for(int i=0;i<num;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
#endif