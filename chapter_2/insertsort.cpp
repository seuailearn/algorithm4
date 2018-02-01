#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;

void exch(vector<int> & a,int i,int j)
{
	int t=a[i];
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
void sort(vector<int> & a)
{
	int n=a.size();
	for(int i=1;i<n;i++)
	{
		for(int j=i;j>0 && a[j]<a[j-1];j--)
			exch(a,j,j-1);
	}
}
int main()
{
	vector<int> a;
	srand(time(0));
	int i=0;
	while(i<10)
	{
		a.push_back(rand()%20);
		i++;
	}
	show(a);
	sort(a);
	show(a);
	return 0;
}

