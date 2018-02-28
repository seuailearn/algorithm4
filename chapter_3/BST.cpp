#include<iostream>

using namespace std;

template<typename T>
class BSTree
{
private:
	struct Node
	{
		T key;
		Node * left;
		Node * right;
		int N;
		Node(T v,Node * lt,Node * rt,int N)
			:key(v),left(lt),right(rt) {}
	};
	Node * root;
	int size(Node x)
	{
		if(x=NULL) return 0;
		else return x.N;
	}
	T search(Node * x,T key);
	//T iterativesearch(Node * x,T key);
	void insert(Node * & x,T key);
	//Node * min(Node * x);
	Node * min(Node * x)
	{
	if(x->left==NULL)
		return x;
	return x->left;
	}
	//Node * max(Node * x);
	Node * max(Node * x)
	{
	if(x->right==NULL)
		return x;
	return x->right;
	}
	//Node * floor(Node * x,T key);
	Node * floor(Node * x,T key)
	{
	if(x==NULL) return NULL;
	if(x->key ==key) return x;
	if(key < x->key) return floor(x.left,key);
	Node * t= floor(x->right,key);
	if(t!=NULL) return t;
	else return x;
	}
	//Node * select(Node * x,int k);
	Node * select(Node * x,int k)
	{
	if(x==NULL)
		return NULL;
	int t= size(x->left);
	if(t>k) return select(x->left,k);
	else if( t< k) return select(x.right,k-t-1);
	else return x;
	}
	int rank(Node * x,T key);
	
	Node * deletemin(Node * x)
	{
		if(x->left ==NULL) return x->right;
		x->left=deletemin(x->left);
		x->N=size(x->left) + size(x->right) +1;
		return x;
	}
	Node del(Node * x,T key)
	{
		if(x==NULL) return NULL;
		if(key < x->key ) x->left =del(x->left, key);
		else if (key > x->key ) x.right=del(x->right, key);
		else
		{
			if(x->right ==NULL) return x->left;
			if(x->left ==NULL) return x->right;
			Node t = x;
			x=min(x->right);
			x->right=deletemin(t->right);
			x->left= t->left;
			return x;
		}
	}
public:
	BSTree();
	//BSTree(const BSTres & rhs);
	~BSTree();
	int size()
	{ return size(root);}

	//µÝ¹é²éÕÒ
	T search(T key);
	//·ÇµÝ¹é²éÕÒ
	//T iterativesearch(T key);

	void insert(T key);
	const T  & min() const
	{
		return min(root)->key;
	}
	 T  max() 
	{
		return max(root)->key;
	}
	 T  floor(T key) ;
	//const T ceiling() const;
	T select(int k)
	{
		return select(root,k)->key;
	}
	int rank(T key)
	{ return rank(root,key);}
	void deletemin()
	{
		root=deletemin(root);
	}
	void del(T key)
	{
		root = del(root, key);
	}
};

template<typename T>
BSTree<T>::BSTree():root(NULL)
{
}

template<typename T>
T BSTree<T>::search(T key)
{
	return search(root,key);
}
template<typename T>
T BSTree<T>::search(Node * x,T key)
{
	if(x==NULL ) return NULL;
	if(key<x->key) return search(x->left,key);
	else if(key > x->key ) return search(x->right,key);
	else return x->key;
}
template <typename T>
void BSTree<T>::insert(T key)
{
	insert(root,key);
}
template < typename T>
void BSTree<T>::insert(Node *  & x,T key)
{
	if(x==NULL) 
		return new Node(key,NULL,NULL,1);
	if(key< x->key) insert( x->left,key);
	else if(key > x->key)
		insert(x->right,key);
	else
		;
	x->N=size(x->left) + size(x->right) +1 ;
}
//template<typename T>

//template<typename T>

template<typename T>
T BSTree<T>::floor(T key) 
{
	Node * x=floor(root,key);
	if(x==NULL)
		return NULL;
	return x->key;
}
//template<typename T>

//template< typename T>

template < typename T>
int BSTree<T>::rank(Node * x,T key)
{
	if(x==NULL) return 0;
	if(key < x->key )
		return rank(x->left , key);
	else if( key > x->key)
		return 1+size(x->left) + rank(x->right,key);
	else
		return size(x->left);
}

int main()
{

}