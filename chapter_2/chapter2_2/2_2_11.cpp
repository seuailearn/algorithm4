#include"merge.h"
#include<time.h>
#include<stdlib.h>

vector<T> aux(100);

void sort(vector<T> & a,int lo,int hi)
{
	if(hi<=lo)
		return ;
	if(hi-lo<15)
		insert(a,lo,hi);
	else
	{
			int mid=lo+(hi-lo)/2;
			sort(a,lo,mid);
			sort(a,mid+1,hi);
			if(a[mid]<=a[mid+1])
				return ;
			merge(a,lo,mid,hi);
	}
}
void Merge(vector<T> & a)
{
	int n=a.size();
	sort(a,0,n-1);
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
	Merge(a);
	show(a);
	return 0;
}