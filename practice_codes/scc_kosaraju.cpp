#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > scc(100, vector<int>(0));
stack<int> mStack;
int indx = 0;

void dfsSCC(vector<vector<int> > &graph, vector<bool> &visited, int root = 0) {

	visited[root] = true;
	for(auto itr = graph[root].begin(); itr != graph[root].end(); ++itr) {
		if(!visited[*itr])
			dfsSCC(graph, visited, *itr);
	}
	mStack.push(root);
}

void dfs(vector<vector<int> > &graph, vector<bool> &visited, int root = 0) {
	
	visited[root] = true;
	scc[indx].push_back(root);
	for(auto itr = graph[root].begin(); itr != graph[root].end(); ++itr) {
		if(!visited[*itr])
			dfs(graph, visited, *itr);
	}
}

void findSCC(vector<vector<int> > &graph, vector<bool> &visited) {
	
	while(!mStack.empty()) {

		int node = mStack.top();
		mStack.pop();

		if(!visited[node]) {
			dfs(graph, visited, node);
			indx++;
		}
	}
}

void printSCC() {

	for(int i=0; i<indx; i++, cout<<endl) {
		for(auto itr = scc[i].begin(); itr != scc[i].end(); ++itr) {
			cout<<*itr<<' ';
		}
	}
}

int main(void) {
	int n,m;
	cin>>n>>m;
	vector<vector<int> > graph(n, vector<int>(0));
	vector<vector<int> > transposeGraph(n, vector<int>(0));
	vector<bool> visited(n, false);

	while(m--) {
		int u, v;
		cin>>u>>v;
		graph[u].push_back(v);
		transposeGraph[v].push_back(u);
	}

	dfsSCC(graph, visited);
	
	for(auto itr = visited.begin(); itr != visited.end(); ++itr)
		*itr = false;

	findSCC(transposeGraph, visited);
	printSCC();

	return 0;

}