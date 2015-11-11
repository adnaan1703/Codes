#include <bits/stdc++.h>
using namespace std;

inline bool isSafe(vector<vector<bool> > &graph, vector<int> &path, vector<bool> &visited, int v, int pos) {
	if(!graph[path[pos-1]][v])
		return false;

	if(visited[v])
		return false;
	return true;
}

bool hamiltonianCycle(vector<vector<bool> > &graph, vector<int> &path, vector<bool> &visited, int pos = 1) {
	int n = graph.size();

	if(pos == n) {
		path.push_back(path[0]);
		return graph[path[pos-1]][path[0]];
	}

	for(int i=1; i<n; i++) {
		if(isSafe(graph, path, visited, i, pos)) {
			path.push_back(i);
			visited[i] = true;

			if(hamiltonianCycle(graph, path, visited, pos+1))
				return true;
			path.pop_back();
			visited[i] = false;
		}
	}
	return false;
}


int main(void) {

	freopen("in.txt", "r", stdin);
	int n,e;
	cin>>n>>e;

	vector<vector<bool> > graph(n, vector<bool>(n,false));
	vector<bool> visited(n, false);
	vector<int> path;

	for(int i=0; i<e; i++) {
		int u, v;
		cin>>u>>v;
		graph[u][v] = true;
		graph[v][u] = true;
	}

	path.push_back(0);
	if(hamiltonianCycle(graph, path, visited)) {
		for(int itr:path)
			cout<<itr<<" ";
		cout<<endl;
	}
	else
		cout<<"No path"<<endl;
	
	return 0;
}