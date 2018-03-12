#include"digraph.h"

int main()
{
	DiGraph gl(13);
	gl.addEdge(7,6);
	gl.addEdge(6,9);
	gl.addEdge(6,4);
	gl.addEdge(0,5);
	gl.addEdge(5,4);
	gl.addEdge(8,7);
	gl.addEdge(7,8);
	gl.addEdge(3,5);
	gl.addEdge(4,3);
	gl.addEdge(11,4);
	gl.addEdge(10,12);
	gl.addEdge(8,9);
	gl.addEdge(9,11);
	gl.addEdge(9,10);
	gl.addEdge(12,9);
	gl.addEdge(11,12);
	gl.addEdge(2,0);
	gl.addEdge(0,1);
	gl.addEdge(6,0);
	gl.addEdge(3,2);
	gl.addEdge(2,3);
	gl.addEdge(4,2);
	
	gl.prin();
	gl.reverse().prin();

	//拓扑排序
	Depthfirstorder D(gl);
	D.Topological();
	cout << endl;
	//可达
	DirectedDFS DFS(gl,0);
	DFS.arrive(gl,0);

	//寻找有向环
	Directedcycle DC(gl);
	if(DC.hascycle())
		cout << "DC  has cycle " <<endl;
	else
		cout << "DC has no cycle " << endl;
	DC.print_cycle();
	cout <<endl;

	//测试寻找强连通分量
	Kosarajuscc KCC(gl);
	KCC.print_connect(gl);

	DiGraph gl1(13);
	gl1.addEdge(0,5);
	gl1.addEdge(0,1);
	gl1.addEdge(0,6);
	gl1.addEdge(2,0);
	gl1.addEdge(2,3);
	gl1.addEdge(3,5);
	gl1.addEdge(5,4);
	gl1.addEdge(6,9);
	gl1.addEdge(6,4);
	gl1.addEdge(7,6);
	gl1.addEdge(8,7);
	gl1.addEdge(11,12);
	gl1.addEdge(9,11);
	gl1.addEdge(9,10);
	gl1.addEdge(9,12);
	
	

	gl1.prin();
	//拓扑排序
	Depthfirstorder DT(gl1);
	DT.Topological();

	
	return 0;
}