#include <bits/stdc++.h>
using namespace std;
vector<int> st(10, -1);
vector<int> ft(10, -1);

void dfs(vector<vector<int> > &graph, vector<bool> &visited, int root = 0) {
	static int time = 0;
	visited[root] = true;
	cout<<root<<' ';
	st[root] = time++;

	for(auto itr = graph[root].begin(); itr != graph[root].end(); ++itr) {
		if(!visited[*itr])
			dfs(graph, visited, *itr);
	}

	ft[root] = time;
}

void printTime(int n) {
	for(int i=0; i<n; i++)
		cout<<i<<" : "<<st[i]<<" , "<<ft[i]<<endl;
}


int main(void) {
	int n, m;
	cin>>n>>m;
	vector<vector<int> > graph(n, vector<int>(0));
	vector<bool> visited(n, false);

	while(m--) {
		int u, v;
		cin>>u>>v;
		graph[u].push_back(v);
	}

	dfs(graph, visited);
	cout<<endl;
	printTime(n);
	return 0;
}