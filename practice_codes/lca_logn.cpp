#include <bits/stdc++.h>
using namespace std;

void populate_by_dfs(vector<vector<int> > &tree, int root, int p, vector<vector<int> > &parent, vector<int> &height) {

	parent[root][0] = p;
	if( p != -1) 
		height[root] = height[p] + 1;
	
	for(int i=1; i<(int) parent[0].size(); i++)
		if(parent[root][i-1] != -1)
			parent[root][i] = parent[parent[root][i-1]][i-1];

	for(auto itr = tree[root].begin(); itr != tree[root].end(); ++itr)
		if( *itr != p)
			populate_by_dfs(tree, *itr, root, parent, height);

}

int lca(vector<vector<int> > &parent, vector<int> &height, int start, int end) {
	
	if(height[start] < height[end])
		swap(start, end);

	for(int i = parent[0].size()-1; i>=0; i--)
		if(parent[start][i] != -1 and height[parent[start][i]] >= height[end])
			start = parent[start][i];

	// At this point height of both start and end nodes are same

	if(start == end)
		return start;

	for(int i = parent[0].size()-1; i >= 0; i--)
		if(parent[start][i] != parent[end][i])
			start = parent[start][i] , end = parent[end][i];

	return parent[start][0];

}

int main(void) {

	freopen("in.txt", "r", stdin);
	int n,logn;
	cin>>n;
	logn = log2(n);
	vector<vector<int> > tree(n,vector<int>(0));
	vector<vector<int> > parent(n, vector<int>(logn, -1));
	vector<int> height(n, 0);

	for(int i=1; i<n; i++) {
		int u,v;
		cin>>u>>v;
		tree[u-1].push_back(v-1);
	}

	populate_by_dfs(tree, 0, -1, parent, height);
	int start 	= 5;
	int end 	= 4;
	cout<<lca(parent, height, start-1, end-1) + 1<<endl;

	return 0;
}
