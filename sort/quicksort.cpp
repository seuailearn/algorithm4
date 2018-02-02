#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
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
	int j=partition(a,lo,hi);
	sort(a,lo,j-1);
	sort(a,j+1,hi);
}

void quicksort(vector<T> & a)
{
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