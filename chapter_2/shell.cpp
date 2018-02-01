#include<vector>
#include<iostream>
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
//Ï£¶ûÅÅÐò
void sort(vector<int> & a)
{
	int num=a.size();
	int h=1;
	while(h<num/3)
		h=3*h+1;
	while(h>=1)
	{
		for(int i=h;i<num;i++)
		{
			for(int j=i;j>=h &&a[j]<a[j-h];j-=h)
				exch(a,j,j-h);
		}
		h=h/3;
	}
}
int main()
{
	vector<int> a;
	cout<<"enter length ";
	int n;
	cin>>n;
	srand(time(0));
	for(int i=0;i<n;i++)
		a.push_back(rand()%20);
	show(a);
	sort(a);
	show(a);
	return 0;
}
