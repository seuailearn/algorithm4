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
void  insert(vector<T> & a,int lo,int hi)
{
	for(int k=lo+1;k<=hi;k++)
		for(int j=k;j>lo && a[j]<a[j-1];j--)
			exch(a,j,j-1);
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
void fastmerge(vector<T> &a,int lo,int mid,int hi)
{
	for(int k=lo;k<=mid;k++)
		aux[k]=a[k];
	for(int k=mid+1;k<=hi;k++)
		aux[k]=a[hi+mid+1-k];
	int i=lo;
	int j=hi;
	for(int k=lo;k<=hi;k++)
	{
		if(Less(aux[i],aux[j]))
			a[k]=aux[i++];
		else
			a[k]=aux[j--];
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