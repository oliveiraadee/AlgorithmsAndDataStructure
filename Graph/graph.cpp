
#include "graph.h"

Graph::Graph(int numVertices) {
	this->numVertices = numVertices;

	used = new int[numVertices];
	group = new int[numVertices];
	matrix = new int*[numVertices];

	for (int i = 0; i < numVertices; i++) {
		used[i] = 0;
		matrix[i] = new int[numVertices];
		for (int n = 0; n < numVertices; n++)
			matrix[i][n] = 0;
	}
}

Graph::~Graph() {
	for (int i = 0; i < numVertices; i++)
		delete [] matrix[i];

	delete [] matrix;
	delete [] used;
	delete [] group;
}


void Graph::edge(int v1, int v2) {
	    matrix[v1][v2] = 1;

}


int Graph::_find(int v1, int v2) {
	return (group[v1] == group[v2]);
}

void Graph::_union(int v1, int v2) {
	if (group[v1] == group[v2]) return;

	for (int k = 0; k < numVertices; k++) {
		if (group[k] == group[v2])
			group[k] = group[v1];
	}
}

int Graph::connected() {
	
		for (int k = 0; k < numVertices; k++) {
			group[k] = 0;
			}

	   for(int i = 0; i < numVertices; i++){
	   	   for(int j = 0 ; j < numVertices; j++){
	   	   	   if(matrix[i][j] == 1){
	   	   	   	     _union(i,j);
					 }
			  }
	   }


	return 1;
}

int Graph::degree(int v) {
	int grau = 0;
	for(int i = 0; i < numVertices; i++){
		if(matrix[v][i] >= 1){
			grau++;
		}
	}
	return grau;
}



