#include"merge.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
vector<T> aux(100);
//浪费内存，没想到合适的动态分配方法
void mergebusort(vector<T> & a)
{
	int n=a.size();
	for(int sz=1;sz<n;sz=2*sz)
		for(int lo=0;lo<n-sz;lo+=2*sz)
			merge(a,lo,lo+sz-1,min(lo+sz+sz-1,n-1));
}
int main()
{
	vector<T> a;
	cout<<"enter length:";
	int num;
	cin>>num;
	srand(time(0));
	while(num-->0)
	{
		a.push_back(rand()%100);
	}
	show(a);
	mergebusort(a);
	show(a);
	return 0;
}
