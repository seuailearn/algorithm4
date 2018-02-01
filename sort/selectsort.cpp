#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;
void exch(vector<int> &a,int i,int j)
{
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
}

void sort(vector<int> & a)
{
	//int n=sizeof(a)/sizeof(int);
	int n=a.size();
	for(int i=0;i<n;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
				if(a[j]<a[min])
					min=j;
		}
		exch(a,i,min);
	}
}
int main()
{
	vector<int> a;
	srand(time(0));
	for(int i=0;i<20;i++)
		a.push_back(rand()%20);
	//int n=sizeof(a)/sizeof(int);
	int n=a.size();
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	sort(a);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
