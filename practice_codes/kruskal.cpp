#include <bits/stdc++.h>
using namespace std;

class DisjointSet {

private:
	int length;
	vector<int> nodes;
	vector<int> size;

	int root(int i) {
		while(nodes[i] != i) {
			nodes[i] = nodes[nodes[i]];
			i = nodes[i];
		}
		return i;
	}

public:

	DisjointSet() {
		length = 1e6;
		DisjointSet(length);
	}

	DisjointSet(int len) {
		length = len;
		nodes = vector<int>(length);
		size = vector<int>(length, 1);

		for(int i=0; i<length; i++) {
			nodes[i] = i;
		}
	}

	void weighted_union(int a, int b) {

		int root_a = root(a);
		int root_b = root(b);

		if(size[root_a] < size[root_b]) {
			nodes[root_a] = nodes[root_b];
			size[root_b] += size[root_a];
		}
		else {
			nodes[root_b] = nodes[root_a];
			size[root_a] += size[root_b];
		}

	}

	bool find(int a, int b) {

		if(root(a) == root(b))
			return true;
		
		return false;
	}

};

struct edge {
	int node1;
	int node2;
	int weight;
};

bool myComp(edge lhs, edge rhs) {
	return (lhs.weight < rhs.weight);
}

int kruskal(vector<edge> &edges, int n) {
	DisjointSet dsu(n);

	sort(edges.begin(), edges.end(), myComp);

	int counter = 0;
	int ans = 0;
	
	for(int i=0; i < (int)edges.size(); i++) {

		if(counter >= n)
			break;

		if(!dsu.find(edges[i].node1, edges[i].node2)) {
			ans += edges[i].weight;
			dsu.weighted_union(edges[i].node1, edges[i].node2);
			counter++;
			// cout<<edges[i].node1<<"----"<<edges[i].node2<<" == "<<edges[i].weight<<endl;
		}
	}
	return ans;
}

int main(void) {
	int n,m;
	cin>>n>>m;
	vector<edge> edges(m);

	while(m--) {
		cin>>edges[m].node1>>edges[m].node2>>edges[m].weight;
	}

	cout<<"Total weight : "<<kruskal(edges, n)<<endl;
	return 0;
}