#include <bits/stdc++.h>
using namespace std;

void populate_by_dfs(vector<vector<int> > &tree, int root, int parentNode, vector<int> &parent, vector<int> &height) {
	if(parentNode != -1)
		height[root] = height[parentNode]+1;

	parent[root] = parentNode;
	for(auto itr = tree[root].begin(); itr != tree[root].end(); ++itr) {
		// keep a check if the node *itr is not parent in case of bi-tree here it is not hence no check.
		populate_by_dfs(tree, *itr, root, parent, height);
	}
}

int lca(vector<int> &parent, vector<int> &height, int start, int end) {
	if(start == end)
		return start;
	if(height[start]<height[end])
		swap(start, end);
	return lca(parent, height, parent[start], end);
}


int main(void) {
	freopen("in.txt", "r", stdin);
	int n;
	cin>>n;
	vector<vector<int> > tree(n,vector<int>(0));
	vector<int> parent(n,-1);
	vector<int> height(n,0);

	for(int i=1; i<n; i++) {
		int u,v;
		cin>>u>>v;
		tree[u-1].push_back(v-1);
	}

	populate_by_dfs(tree, 0, -1, parent, height);
	int start = 5;
	int end = 4;
	cout<<lca(parent, height, start-1, end-1) + 1<<endl;

	return 0;
}