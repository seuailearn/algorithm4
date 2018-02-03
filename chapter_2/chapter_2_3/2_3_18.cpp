#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;
typedef int T;
void show(const vector<int> & a)
{
	int num=a.size();
	cout<<"length is " <<num <<endl;
	for(int i=0;i<num;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
void exch(vector<T> & a,int i,int j)
{
	T temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
//插入排序
void insertsort(vector<int> & a)
{
	int n=a.size();
	for(int i=1;i<n;i++)
	{
		for(int j=i;j>0 && a[j]<a[j-1];j--)
			exch(a,j,j-1);
	}
}
//选择a[i],a[k],a[j]的中位数的下标
int sampleof3(vector<T> & a,int i,int j)
{
	int k=i+(j-i)/2;
	if(a[i]<a[j])
		return (a[j]<a[k]?j:a[i]<a[k]?k:i);
	else
		return (a[k]<a[j]?k:a[i]<a[k]?i:k);

}

int partition(vector<T> & a,int lo,int hi)
{
	
	int i=lo;
	int j=hi+1;
	T v=a[lo];
	while(true)
	{
		while(a[++i]<v)
			if(i==hi)
				break;
		while(v<a[--j])
			if(j==lo)
				break;
		if(i>=j)
			break;
		exch(a,i,j);
	}
	exch(a,lo,j);
	return j;
}
void sort(vector<T> & a,int lo,int hi)
{
	if(hi<=lo)
		return ;
	if(hi-lo<15)
		insertsort(a);
	else
	{
	int m = sampleof3(a, lo,  hi);
        exch(a, m, lo);
	int j=partition(a,lo,hi);
	sort(a,lo,j-1);
	sort(a,j+1,hi);
	}
}

void quicksort(vector<T> & a)
{
	std::random_shuffle(a.begin(),a.end());
	int n=a.size();
	sort(a,0,n-1);
}

int main()
{
	srand(time(0));
	cout<<"enter array length: ";
	int num;
	cin>>num;
	vector<T> a;
	while(num-->0)
		a.push_back(rand()%100);
	show(a);
	quicksort(a);
	show(a);
	return 0;
}