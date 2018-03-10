#include"graph.h"
int main()
{
	
	Graph gl(6);
	//采用的栈，所以添加顺序应与书上相反
	gl.addEdge(0,2);
	gl.addEdge(3,5);
	gl.addEdge(3,4);
	gl.addEdge(0,1);
	gl.addEdge(1,2);
	gl.addEdge(2,3);
	gl.addEdge(2,4);
	gl.addEdge(0,5);

	gl.prin();
	depthfirstsearch  DFS(gl,0);
	

	Depthfirstpaths DFP(gl,0);
	DFP.pathto(5);
	DFP.pathto(4);
	BreadthFirstpaths BFP(gl,0);
	BFP.pathto(5);
	BFP.pathto(4);
	return 0;
}