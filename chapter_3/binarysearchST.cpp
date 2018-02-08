#include<iostream>
#include<string>
#include<fstream>
using namespace std;
template<typename Key,typename Value>
class BinarysearchST
{
private:
	Key *keys;
	Value *vals;
	int N;
public:
	BinarysearchST(int capacity)
	{
		keys=new Key[capacity];
		vals= new Value[capacity];
		N=0;    //ÎóÐ´×öint N=0; µ¼ÖÂ³ö´í
	}
	int size()
		{ return N;}
	Value get(Key key);
	int rank(Key key);
	void put(Key key,Value val);
	void del(Key key);
	Key floor(Key key);
	Key ceiling(Key key);
	bool contains(Key key) { return get(key)!=NULL; }
	bool isempty() {return N==0;}
	Value min()
		{if (isempty()) return NULL; 
		 return vals[0]; }
	Value max() 
		{ if (isempty()) return NULL; 
		  return vals[N-1]; }
	Key select(int k){ if(k<0 || k>=N) return NULL; return keys[k];}
};
template<typename Key,typename Value>
Value BinarysearchST<Key,Value>::get(Key key)
{
	if(isempty())
		return NULL;
	int i=rank(key);
	if(i<N && keys[i]==key)
		return vals[i];
	else
		return NULL;
}
template<typename Key,typename Value>
int BinarysearchST<Key,Value>::rank(Key key)
{
	int lo=0,hi=N-1;
	while(lo<=hi)
	{
		int mid=lo+(hi-lo)/2;
		if(key>keys[mid])
			lo=mid+1;
		else if(key<keys[mid])
			hi=mid-1;
		else
			return mid;
	}
	return lo;
}
template<typename Key,typename Value>
void BinarysearchST<Key,Value>::put(Key key,Value val)
{
	if(val==NULL)
		{ del(key); return ;}
	int i= rank(key);
	if(i<N && keys[i]==key)
	{
		vals[i]=val;
		return;
	}
	for(int j=N;j>i;j--)
	{
		keys[j]=keys[j-1];
		vals[j]=vals[j-1];
	}
	keys[i]=key;
	vals[i]=val;
	N++;
}
template<typename Key,typename Value>
void BinarysearchST<Key,Value>::del(Key key)
{
	if(isempty())
		return ;
	int i=rank(key);
	if(i==N || keys[i]!=key)
		return ;
	for(int j=i;j<N-1;j++)
	{
		keys[j]=keys[j+1];
		vals[j]=vals[j+1];
	}
	N--;
	
}
template<typename Key,typename Value>
Key BinarysearchST<Key,Value>::floor(Key key)
{
	int i=rank(key);
	if(i==0) return NULL;
	if(i< N && keys[i]==key)
		return keys[i];
	else
		return keys[i-1];
}
template<typename Key,typename Value>
Key BinarysearchST<Key,Value>::ceiling(Key key)
{
	int i=rank(key);
	if(i==N) return NULL;
	else 
		return keys[i];
}

int main()
{
	BinarysearchST<string , int> bs(100);
	string ch;

	ifstream fin;
	fin.open("data.txt");
	int i=1;
	if(!fin.is_open())
		cout<<"can't open file!"<<endl;
	while(fin>>ch)
	{
		cout<<ch<<endl;
		bs.put(ch,i);
		i++;
	}
	cout<<i<<endl;
	
	int n=bs.size();
	cout<<n<<endl;
	for(int i=0;i<n;i++)
		cout<<bs.select(i)<<" "<<bs.get(bs.select(i))<<endl;
	bs.del("best");
	for(int i=0;i<bs.size();i++)
		cout<<bs.select(i)<<" "<<bs.get(bs.select(i))<<endl;
}