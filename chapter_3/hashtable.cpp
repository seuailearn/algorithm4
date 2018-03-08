#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

//数据类名称：Employee
//作为散列表的数据项目
class Employee
{
public:
	Employee()
	{ name = "", salary = 0.0, seniority = 0; };
	Employee(const string & n, double sal, int sen)
		:name(n), salary(sal), seniority(sen) {}
	const string & getname() const 
	{
		return name;
	}
	//重载==
	bool operator == (const Employee &rhs) const
	{
		return getname() == rhs.getname();
	}
	//重载！=
	bool operator != (const Employee & rhs ) const
	{
		return !(*this == rhs);
	}
	friend ostream & operator << ( ostream & os, const Employee & rhs)
	{
		os << "name: " << rhs.name <<" ,salary: " << rhs.salary <<
			" ,seniority: " << rhs.seniority ;
		return os;
	}
private:
	string name;
	double salary;
	int seniority;
};

//散列函数
int hash_s (const string & key)
{
	int hashval = 0;
	for(int i = 0; i < key.length(); ++i)
		hashval = 37 * hashval + key[i];
	return hashval;
}
int hash_my( const Employee & item)
{
	return hash_s(item.getname());
}

template<typename Hashedobj >
class HashTable
{
public:
	explicit HashTable(int size = 11):theLists(size),currentSize(0){}
	~HashTable();
	bool containes( const Hashedobj & x) const;
	void makeEmpty();
	bool isEmpty();
	bool insert(const Hashedobj & x);
	bool remove(const Hashedobj & x);
	void print();
	Hashedobj findelement(const Hashedobj & x);
private:
	vector<list<Hashedobj> > theLists; //散列表的结构，theLists大小默认初始化为11
	int currentSize; //散列表当前存放的元素个数
private:
	void rehash();//再散列
	int myhash(const Hashedobj & x) const; //散列函数
	int nextprime(int n); //比N大距离N最近的一个素数
};

/*查找元素x
成功则返回该元素，否则返回一个默认构造的元素值
*/
template<typename Hashedobj>
Hashedobj HashTable<Hashedobj>::findelement( const Hashedobj & x)
{
	list<Hashedobj> & whichlist = theLists[myhash(x)];
	typename list<Hashedobj>::iterator it = find(whichlist.begin(),whichlist.end(), x);
	
	if(it != whichlist.end())
		return *it;
	else
	{
		Hashedobj obj;//返回一个成员值为0的对象
		return obj;
	}
}

template<typename Hashedobj>
void HashTable<Hashedobj>::print()
{
	cout << "输出散列表的内容： " << endl;
	for(int  i = 0; i < theLists.size(); ++i)
	{
		cout << i << ":" <<endl;
		for(typename list<Hashedobj>::iterator it = theLists[i].begin();
			it != theLists[i].end(); )
			cout << *it++;
		/******************************
		for(typename list<Hashedobj>::iterator it = theLists[i].begin();
			it != theLists[i].end(); ++it)
			cout << *it;
		出现error : list iterators incompatible 
		原因是否为当进行cout操作之后it已经失效，无法进行++操作
		******************************/
	}
}


template <typename Hashedobj>
bool HashTable<Hashedobj>::isEmpty()
	{return currentSize ==0;
}

template<typename Hashedobj>
void HashTable<Hashedobj>::makeEmpty()
{
	for( int i = 0; i < theLists.size(); ++i)
		theLists[i].clear();
	currentSize = 0;
}

template<typename Hashedobj>
bool HashTable<Hashedobj>::containes(const Hashedobj & x) const
{
	const list<Hashedobj> & whichlist = theLists[myhash(x)];
	return find(whichlist.begin(),whichlist.end(),x) != whichlist.end();
}

template<typename Hashedobj>
bool HashTable<Hashedobj>::remove(const Hashedobj & x)
{
	list<Hashedobj> & whichlist = theLists[myhash(x)];
	typename list<Hashedobj>::iterator it = 
		find(whichlist.begin(),whichlist.end(),x); 
	if(it == whichlist.end())
		return false;
	whichlist.erase(it); //删除元素x
	--currentSize;
	return true;
}

/*
在散列表中插入元素，如果插入项存在，则什么都不做
否则将其放在表的前端
*/
template<typename Hashedobj>
bool HashTable<Hashedobj>::insert(const Hashedobj & x)
{
	list<Hashedobj> & whichlist = theLists[myhash(x)];
	if(find(whichlist.begin(),whichlist.end(),x) != whichlist.end())
		return false;
	whichlist.push_back(x);

	//rehash
	if(++currentSize > theLists.size())
		rehash();
	return true;
}

template<typename Hashedobj>
HashTable<Hashedobj>::~HashTable()
{
}

template<typename Hashedobj>
int HashTable<Hashedobj>::nextprime(int n)
{
	int i;
	if( n % 2 == 0)
		n++;
	for( ; ; n+=2)
	{
		for(i = 3; i*i <= n; i +=2)
			if(n % i == 0)
				goto ContOuter;
		return n;
		ContOuter: ;
	}
}

template<typename Hashedobj>
void HashTable<Hashedobj>::rehash()
{
	vector<list<Hashedobj> > oldlists = theLists;
	//创建一个新的大小为原来两倍大小的散列表
	theLists.resize(nextprime(2*theLists.size()));
	for(int i = 0; i < theLists.size(); ++i)
		theLists[i].clear();
	for(int i = 0; i < oldlists.size(); ++i)
	{
		typename list<Hashedobj>::iterator it = oldlists[i].begin();
		while(it != oldlists[i].end())
			insert(*it++);
	}
}

template<typename Hashedobj>
int HashTable<Hashedobj>::myhash(const Hashedobj & key) const
{
	int hashval = hash_my(key);
	hashval %= theLists.size();
	if(hashval < 0)
		hashval += theLists.size();
	return hashval;
}

int main()
{
	Employee e1("linux", 101.00, 1);  
    Employee e2("ever", 102.00, 2);  
    Employee e3("peter", 103.00, 3);  
    Employee e4("may", 104.00, 4);  
    Employee e5("usa", 105.00, 5);  
    Employee e6("sal", 106.00, 6);  
    Employee e7("usa", 107.00, 7);//和上面的值重复，所以这个值会被忽略  
    Employee e8("jan", 108.00, 8);  
    Employee e9("kro", 109.00, 9);  
    Employee e10("bei", 110.00, 10);  
      
    Employee e12("bbb", 110.00, 10);  
  
    vector<Employee> v;  
    v.push_back(e1);  
    v.push_back(e2);  
    v.push_back(e3);  
    v.push_back(e4);  
    v.push_back(e5);  
    v.push_back(e6);  
    v.push_back(e7);  
    v.push_back(e8);  
    v.push_back(e9);  
    v.push_back(e10);  

	cout << "v: " << endl;  
    for(unsigned i = 0; i < v.size(); ++i)  
        cout << v[i];  
    cout << endl; 

	HashTable<Employee> hashTable;
	for(unsigned i = 0; i < v.size(); ++i)
		hashTable.insert(v[i]);
	hashTable.print();

	cout << endl;  
    //测试查找函数findElement  
    cout << "测试查找函数findElement: " << endl;  
    Employee e11 = hashTable.findelement(e12);  
    cout << "e11 = " << e11;  
    Employee e13 = hashTable.findelement(e10);  
    cout << "e13 = " << e13;  
    cout << endl;

	cout << "测试包含函数containes: " << endl;   
    if(hashTable.containes(e10))  
        cout << "containe e10" << endl;  
    else   
        cout << "not containe e10" << endl;  
  
    if(hashTable.containes(e11))  
        cout << "containe e11" << endl;  
    else   
        cout << "not containe e11" << endl;

	cout << "测试remove()：" << endl;  
    hashTable.remove(e10);  
    if(hashTable.containes(e10))  
        cout << "containe e10" << endl;  
    else   
        cout << "not containe e10" << endl;  
    cout << endl;

	cout << "测试isEmpty(): " << endl;  
    if(hashTable.isEmpty())  
        cout << "hashTable is Empty " << endl;  
    else  
        cout << "hashTable is not Empty " << endl;  
    cout << endl;  
  
    cout << "测试makeEmpty(): " << endl;  
    hashTable.makeEmpty();  
    if(hashTable.isEmpty())  
        cout << "hashTable is Empty " << endl << endl;  
    else  
        cout << "hashTable is not Empty " << endl;  
    cout << endl;  
	return 0;  
}
