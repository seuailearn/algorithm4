#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;

typedef int T;
void exch(vector<T> & a,int i,int j)
{
	T t=a[i];
	a[i]=a[j];
	a[j]=t;
}
void show(const vector<int> & a)
{
	int num=a.size();
	cout<<"length is " <<num <<endl;
	for(int i=0;i<num;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
//½«a[]°´ÉýÐòÅÅÁÐ
void sort(vector<T> & a)
{
	int n=a.size();
	for(int i=1;i<n;i++)
	{
		T temp=a[i];
		int j=i;
		for(;j>0 && temp<a[j-1];j--)
			a[j]=a[j-1];
		a[j]=temp;
	}
}
int main()
{
	vector<T> a;
	srand(time(0));
	int i=0;
	cout<<"enter length: ";
	int num;
	cin>>num;
	while(i<num)
	{
		a.push_back(rand()%20);
		i++;
	}
	show(a);
	sort(a);
	show(a);
	
	return 0;
}