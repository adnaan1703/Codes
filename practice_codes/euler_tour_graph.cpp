#include <bits/stdc++.h>
using namespace std;
vector<int> eulerTour;


void findEulerTour(vector<vector<bool> > &graph, int root = 0) {

	eulerTour.push_back(root);

	for(int i=0; i < (int)graph[root].size(); i++) {
		if(graph[root][i]){
			graph[root][i] = false;
			graph[i][root] = false;
			findEulerTour(graph, i);
		}
	}
}

void printEulerTour() {
	for(auto itr = eulerTour.begin(); itr != eulerTour.end(); ++itr) {
		cout<<*itr<<' ';
	}
	cout<<endl;
}

int main(void) {
	int n, m;
	cin>>n>>m;
	vector<vector<bool> > graph(n, vector<bool> (n, false));

	while(m--) {
		int u, v;
		cin>>u>>v;
		graph[u][v] = true;
		graph[v][u] = true;
	}

	findEulerTour(graph);
	printEulerTour();

	return 0;
}