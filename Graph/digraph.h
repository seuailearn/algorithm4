#ifndef _GRAPH_H_
#define _GRAPH_H_
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;



//API

class DiGraph
{
public:
	int _v;
	int _e;
	vector<vector<int> > adj; //邻接表
public:
	DiGraph()
	{
		 vector<vector<int> > temp;
		 adj = temp;
		_e = 0;
		_v = 0;
	}
	DiGraph(int v):_v(v),_e(0)
	{
		
		vector<int> temp;
		adj.resize(v);
		for(int i = 0; i < v; ++i)
			adj[i]=temp;
			
	}
	/*
	DiGraph(const DiGraph & other)
	{
		this->_v = other._v;
		this->_e = other._e;
		this->adj = other.adj;
	}
	
	DiGraph & operator = (const DiGraph & other)
	{
		this->_v = other._v;
		this->_e = other._e;
		this->adj = other.adj;
		return *this;
	}*/

	int V() { return _v;}
	int E() { return _e;}
	
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		
		_e++;
	}
	
	
	/*
	int degree(int v);
    int maxDegree();
    double avgDegree();
    int numberOfselfLoops();
	*/
	DiGraph reverse()
	{
		DiGraph R(_v);
		for(int i = 0; i < _v; i++)
		{
			vector<int>::iterator ite = adj[i].begin();
			for( ; ite!=adj[i].end(); ite++)
				R.addEdge(*ite,i);
		}
		return R;
	}

    void prin() 
	{
		cout <<"GRAPH : " <<endl;
		for(int i = 0; i < _v; ++i)
		{
			cout << i << " ";
			for(int j = 0; j < adj[i].size(); ++j)
				cout << adj[i][j] <<" ";
			cout <<endl;
		}
		cout <<endl;
	}
	
};
class DirectedDFS:public DiGraph
{
private:
	bool * marked;
public:
	DirectedDFS(DiGraph G,int s)
	{
		marked = new bool[G.V()];
		for(int i = 0; i < G.V(); i++)
			marked[i] = false;
		dfs(G,s);
	}
public:DirectedDFS(DiGraph G, vector<int> s )
	   {
		   marked = new bool[G.V()];
		   vector<int > ::iterator ite = s.begin();
		   for( ; ite != s.end(); ite++)
			   dfs(G,*ite);
	   }
private:
	void dfs(DiGraph G, int v)
	{
		marked[v] = true;
		vector<int>::iterator temp = G.adj[v].begin();
		for( ; temp != G.adj[v].end(); temp++)
			if(!marked[*temp])
				dfs(G,*temp);
	}
public:
	void arrive(DiGraph G,int v)
	{
		cout << v << " can arrive : " ;
		for(int i = 0; i < G.V(); i++)
			if(marked[i])
				cout << i <<" ";
		cout << endl;
	}
};

class Directedcycle: public DiGraph
{
private:
	bool * marked;
	int * edgeto;
	
	bool * onstack;
	stack<int> cycle;
public:
	Directedcycle(DiGraph G)
	{
		onstack = new bool[G.V()];
		edgeto = new int[G.V()];
		marked = new bool[G.V()];
		for( int i = 0; i < G.V(); i++)
		{
			marked[i] = false;
			onstack[i] = false;
		}
		for(int i = 0; i < G.V(); i++)
		{
			if(!marked[i])
				dfs(G,i);
		}
	}
private:
	void dfs(DiGraph G,int v)
	{
		onstack[v] = true;
		marked[v] = true;
		vector<int>::iterator ite = G.adj[v].begin();
		for( ; ite != G.adj[v].end(); ite++)
		{
			if(this->hascycle())
				return ;
			else if(!marked[*ite])
			{
				edgeto[*ite] = v;
				dfs(G,*ite);
			}
			else if(onstack[*ite])
			{
				for( int x = v; x != *ite; x = edgeto[x])
					cycle.push(x);
				cycle.push(*ite);
				cycle.push(v);
			}
			}
			onstack[v] = false;
	}
public:
		bool hascycle()
		{
			return !cycle.empty();
		}

public:
		void print_cycle()
		{
		cout << " cycle : ";
		while(!cycle.empty())
		{
			cout << cycle.top()<< " ";
			cycle.pop();
		}
		}
	
};

//有向图中基于深度优先搜索的顶点排序
class Depthfirstorder
{
private:
	bool * marked;
	queue<int> pre; //前序排列
	queue<int> post; //后序排序
	stack<int> reversepost; //逆后序
	
public:
	Depthfirstorder(DiGraph G)
	{
		marked = new bool[G.V()];
		
		for(int i = 0; i < G.V(); i++)
			marked[i] = false;
		for(int v = 0; v < G.V(); v++)
			if(!marked[v])
				dfs(G,v);
	}
private:
	void dfs(DiGraph G,int v)
	{
		pre.push(v);
		marked[v] = true;
		vector<int>::iterator ite = G.adj[v].begin();
		for( ; ite < G.adj[v].end(); ite++)
			if(!marked[*ite])
				dfs(G,*ite);
		post.push(v);
		reversepost.push(v);
	}
public:
	stack<int> _reversepost()
	{
		return reversepost;
	}
	void Topological()
	{
			while(!reversepost.empty())
			{
				cout << reversepost.top() <<" ";
				reversepost.pop();
		}
	}
};
class Kosarajuscc
{
private:
	bool * marked;
	int * id;
	int count;
public:
	Kosarajuscc(DiGraph G)
	{
		marked = new bool[G.V()];
		id = new int[G.V()];
		count = -1;
		for(int i = 0; i < G.V(); i++)
		{
			marked[i] = false;
			id[i] = 0;
		}
		
		Depthfirstorder order(G.reverse());
		stack<int> temp = order._reversepost();
		while(!temp.empty())
		{
			if(!marked[temp.top()])
				{
					count++;
					dfs(G,temp.top());
					
			}
			temp.pop();
	}
	}
private:
	void dfs(DiGraph G,int v)
	{
		marked[v] = true;
		id[v] = count;
		vector<int>::iterator temp = G.adj[v].begin();
		for( ; temp != G.adj[v].end(); temp++)
			if(!marked[*temp])
				dfs(G,*temp);
	}
	
public:
	void print_connect(DiGraph G)
	{
		cout <<" graph has " << count <<" connected " << endl;
		for(int j = 0; j <= count; j++)
		{
			cout << j <<" : ";
			for(int i = 0; i < G.V(); i++)
				if(id[i] == j)
					cout << i <<" ";
			cout << endl;
			
		}
	}
};
#endif