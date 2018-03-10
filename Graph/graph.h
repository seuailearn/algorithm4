#ifndef _GRAPH_H_
#define _GRAPH_H_
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;



//API

class Graph
{
public:
	int _v;
	int _e;
	vector<vector<int> > adj; //邻接表
public:
	Graph()
	{
		 vector<vector<int> > temp;
		 adj = temp;
		_e = 0;
		_v = 0;
	}
	Graph(int v):_v(v),_e(0)
	{
		
		vector<int> temp;
		adj.resize(v);
		for(int i = 0; i < v; ++i)
			adj[i]=temp;
			
	}
	/*
	Graph(const Graph & other)
	{
		this->_v = other._v;
		this->_e = other._e;
		this->adj = other.adj;
	}
	
	Graph & operator = (const Graph & other)
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
		adj[w].push_back(v);
		_e++;
	}
	
	
	/*
	int degree(int v);
    int maxDegree();
    double avgDegree();
    int numberOfselfLoops();
	*/
	
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

class depthfirstsearch : public Graph
{
private:
	bool *marked;
	int count;
public:
	depthfirstsearch(Graph x,int s)
	{
		adj = x.adj;
		count = 0;
		marked = new bool [x.V()];
		for(int i = 0; i < x.V(); i++)
			marked[i] = false;
			
		dfs(x,s);
	}
	
public:
	void dfs(Graph G, int v)
	{
		marked[v] = true;
		count++;
		/*
		for(int i = 0; i < adj[v].size(); i++)
			if(!marked[adj[v][i]])
				dfs(G,adj[v][i]);
		两者均可 */
		vector<int>::iterator temp = G.adj[v].begin();
		for( ; temp != G.adj[v].end();++temp )
			if(!marked[*temp])
				dfs(G,*temp);

	}	
};	

class Depthfirstpaths:public Graph
{
private:
	bool * marked;
	int * edgeto;
	int s;
public:
	Depthfirstpaths(Graph g,int n)
	{
		marked = new bool [g.V()];
		edgeto = new int [g.V()];
		s = n;
		edgeto[0] = 0;    //以0为起点            
		for(int i = 0; i < g.V();i++)
			marked[i] = false;       
		dfs(g,s);
	}
private:
	void dfs(Graph G,int v)
	{
		marked[v] = true;		
		
		vector<int>::iterator temp = G.adj[v].begin();
		for( ; temp != G.adj[v].end(); ++temp)
			if(!marked[*temp])
			{
				edgeto[*temp] = v;
				dfs(G,*temp); 
			}
	}
public:
	bool haspathto(int v)
	{
		return marked[v];
	}
public:
	void pathto(int v)
	{
		if(!haspathto(v)) 
		{
			cout << s <<" to " << v <<" no path "<<endl;
			return ;
		}
		cout << s << " to " << v << " " << "0";
		stack<int> sta;
		
		for(int x = v; x != s;  x = edgeto[x])
		{sta.push(x);}
		for( ; !sta.empty(); )
		{
			cout << "-" << sta.top();
			sta.pop();
		}
		cout <<endl;
	}
};

class BreadthFirstpaths: public Graph
{
private:
	bool * marked;
	int *  edgeto;
	int s;
public:
	BreadthFirstpaths(Graph G, int n)
	{
		marked = new bool[G.V()];
		edgeto = new int[G.V()];
		for( int i = 0; i < G.V(); i++)
			marked[i] = false;
		edgeto[0] = 0;
		s = n;
		bfs(G,s);
	}
private:
	void bfs(Graph G, int s)
	{
		queue<int> que;
		marked[s] = true;
		que.push(s);
		while(!que.empty())
		{
			int v = que.front();
			que.pop();
			vector<int>::iterator ite = G.adj[v].begin();
			for( ; ite != G.adj[v].end(); ite++)
			{
				if(!marked[*ite])
				{
					edgeto[*ite] = v;
					marked[*ite] = true;
					que.push(*ite);
				}
			}
		}
	}
public:
	
	bool haspathto(int v)
	{
		return marked[v];
	}
	void pathto(int v)
	{
		if(!haspathto(v)) 
		{
			cout << s <<" to " << v <<" no path "<<endl;
			return ;
		}
		cout << s << " to " << v << " " << "0";
		stack<int> sta;
		
		for(int x = v; x != s;  x = edgeto[x])
		{sta.push(x);}
		for( ; !sta.empty(); )
		{
			cout << "-" << sta.top();
			sta.pop();
		}
		cout <<endl;
	}
	};
#endif