//可能有bug
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
void sort(vector<T> & a,int lo,int hi)
{
	if(hi<lo)
		return ;
	
	int i=lo;
	int j=hi+1;
	int p=lo;
	int q=hi+1;
	T v=a[lo];
	while(true)
	{
		while(a[++i]<v)
			if (i==hi) break;
		while(v<a[--j])
			if(j==lo) break;
		if(i==j && a[i]==v)
			exch(a,i,++p);
		if(i>=j)
			break;
		exch(a,i,j);
		if(a[i]==v)
			exch(a,i,++p);
		if(a[j]==v)
			exch(a,j,--q);
	}
		i=j+1;
		for(int k=lo;k<=p;k++)
			exch(a,k,j--);
		for(int k=hi;k>=q;k--)
			exch(a,k,i++);
		sort(a,lo,j);
		sort(a,i,hi);
	}

void quick3way(vector<T> & a)
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
	quick3way(a);
	show(a);
	return 0;
}