#include <bits/stdc++.h>
using namespace std;
#define ROOT 0

vector<int> parent(100);
vector<int> h(100);
vector<int> d(100);
set<int> points;

void findArticulationPoints(vector<vector<int> > &graph, vector<bool> &visited, int root = 0, int par = -1) {

	int children = 0;
	visited[root] = true;
	parent[root] = par;

	if(root != ROOT)
		h[root] = h[par] + 1;

	d[root] = h[root];

	for(auto itr = graph[root].begin(); itr != graph[root].end(); ++itr) {
		if(!visited[*itr]) {
			children++;
			findArticulationPoints(graph, visited, *itr, root);
			d[root] = min(d[root], d[*itr]);

			if(d[*itr] >= h[root] and root != ROOT) {
				points.insert(root);
			}
		}
		else if(*itr != parent[root])
			d[root] = min(d[root], h[*itr]);
	}

	if(root == ROOT && children > 1)
		points.insert(root);
}

void printArticulationPoints() {
	for(auto itr = points.begin(); itr != points.end(); ++itr) {
		cout<<*itr<<' ';
	}
}

int main(void) {
	int n, m;
	cin>>n>>m;
	vector<vector<int> > graph(n, vector<int> (0));
	vector<bool> visited(n, false);

	while(m--) {
		int u, v;
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	h[ROOT] = 0;
	parent[ROOT] = -1;
	findArticulationPoints(graph, visited);
	printArticulationPoints();
	cout<<endl;


	return 0;
}