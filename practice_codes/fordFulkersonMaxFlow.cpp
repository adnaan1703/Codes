#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

bool bfs(vector<vector<int> > &rGraph, int source, int destination, vector<int> &parent) {

	int n = parent.size();
	queue<int> q;
	vector<bool> visited(n, false);

	q.push(source);
	visited[source] = true;
	parent[source] = -1;

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(int v = 0; v<n; v++) {
			if(visited[v] == false && rGraph[u][v] > 0) {
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	return (visited[destination] == true);
}


int forFulkerson(vector<vector<int> > &graph, int source, int destination) {

	int n = graph.size();
	vector<vector<int> > rGraph = graph;
	vector<int> parent(n);
	int max_flow = 0;

	while(bfs(rGraph, source, destination, parent)) {
		int path_flow = INF;
		for(int v = destination; v != source; v = parent[v]) {
			int u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);
		}

		for(int v = destination; v != source; v = parent[v]) {
			int u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}



int main(void) {
	int n = 6;
	vector<vector<int> > graph = {
		{	0, 16, 13, 0, 0, 0	},
		{	0, 0, 10, 12, 0, 0	},
		{ 	0, 4, 0, 0, 14, 0 	},
		{	0, 0, 9, 0, 0, 20	},
		{	0, 0, 0, 7, 0, 4	},
		{	0, 0, 0, 0, 0, 0	}
	};

	// indices are 0 indexed as evident below where 0 is the source and 5 is destination
	cout<<"The maximum flow in the network : "<<forFulkerson(graph, 0, 5);
	return 0;

}