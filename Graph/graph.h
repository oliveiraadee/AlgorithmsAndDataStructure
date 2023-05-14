
#ifndef GRAPH_H_
#define GRAPH_H_


class Graph {
private:
	int numVertices;

	int * used; 	
	int **matrix; 	

	int * group;  	
	void _union(int v1, int v2);	
	int  _find(int v1, int v2);		
public:
	Graph(int numVerices);

	~Graph();

	int connected();			
	int degree(int v);			

	void edge(int v1, int v2);	
};


#endif /* GRAPH_H_ */
