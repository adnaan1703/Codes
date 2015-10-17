#include <bits/stdc++.h>
using namespace std;

vector<int> result;

void euler_tour(vector<vector<int> > &tree, int root) {
	result.push_back(root);
	for(auto itr = tree[root].begin(); itr != tree[root].end(); ++itr) {
		euler_tour(tree, *itr);
		result.push_back(root);
	}
}

void print_euler(void) {
	for(auto itr = result.begin(); itr != result.end(); ++itr) {
		cout<<(*itr)+1<<' ';
	}
	cout<<endl;
}


int main(void) {
	freopen("in.txt", "r", stdin);
	int n;
	cin>>n;
	vector<vector<int> > tree(n,vector<int>(0));

	for(int i=1; i<n; i++) {
		int u,v;
		cin>>u>>v;
		tree[u-1].push_back(v-1);
		// tree[v-1].push_back(u-1);
	}

	euler_tour(tree, 0);
	print_euler();
	return 0;
}