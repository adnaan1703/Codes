#include <bits/stdc++.h>
using namespace std;


void topodfs(vector<vector<int> > &graph, vector<bool> &visited, stack<int> &Stack, int root) {

	visited[root] = true;

	for(int itr : graph[root]) {
		if(!visited[itr])
			topodfs(graph, visited, Stack, itr);
	}
	Stack.push(root);
}

void toposort(vector<vector<int> > &graph) {

	int n = graph.size();
	vector<bool> visited(n, false);
	stack<int> Stack;

	for(int i=0; i<n; i++) {
		if(!visited[i])
			topodfs(graph, visited, Stack, i);
	}

	while(!Stack.empty()) {
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
	cout<<endl;

}



int main(void) {

	freopen("in.txt", "r", stdin);
	int n, m;
	cin>>n>>m;

	vector<vector<int> > graph(n, vector<int>(0));
	vector<bool> indeg(n, false);

	while(m--) {
		int u, v;
		cin>>u>>v;
		indeg[v] = true;
		graph[u].push_back(v);
	}

	toposort(graph);

	return 0;
}