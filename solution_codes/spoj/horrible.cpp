#include <bits/stdc++.h>
using namespace std;
typedef long long int lint;

struct node {
	int numleaves;
	lint sum, add;

	void split(node &lhs, node &rhs) {
		lhs.add += add;
		lhs.sum += add*lhs.numleaves;
		rhs.add += add;
		rhs.sum += add*rhs.numleaves;
		add = 0;
	}

	void merge(node &lhs, node &rhs) {
		numleaves = lhs.numleaves + rhs.numleaves;
		add = 0;
		sum = lhs.sum + rhs.sum;
	}
};

node tree[400040];

void build_tree(int root, int a, int b) {
	if(a>b)
		return;
	if(a==b) {
		tree[root].sum = 0;
		tree[root].add = 0;
		tree[root].numleaves = 1;
		return;
	}

	int mid = (a+b)>>1;
	int leftChild = root<<1;
	int rightChild = leftChild+1;

	build_tree(leftChild, a, mid);
	build_tree(rightChild, mid+1, b);

	tree[root].merge(tree[leftChild], tree[rightChild]);
}

void update_tree(int root, int a, int b, int i, int j, lint val) {

	if(a>b || a>j || b<i)
		return;
	int mid = (a+b)>>1;
	int leftChild = root<<1;
	int rightChild = leftChild + 1;

	if(a>=i && b<=j) {
		tree[root].add += val;
		tree[root].sum += (val*tree[root].numleaves);
		return;
	}

	tree[root].split(tree[leftChild], tree[rightChild]);
	update_tree(leftChild, a, mid, i, j, val);
	update_tree(rightChild, mid+1, b, i, j, val);
	tree[root].merge(tree[leftChild], tree[rightChild]);
}

node query_tree(int root, int a, int b, int i, int j) {

	node identity;
	identity.numleaves = 0;
	identity.add = 0;
	identity.sum = 0;

	if(a>b || a>j || b<i)
		
		return identity;

	if(a>=i && b<=j)
		return tree[root];

	int mid = (a+b)>>1;
	int leftChild = root<<1;
	int rightChild = leftChild+1;

	tree[root].split(tree[leftChild], tree[rightChild]);
	node l = query_tree(leftChild, a, mid, i, j);
	node r = query_tree(rightChild, mid+1, b, i, j);
	tree[root].merge(tree[leftChild], tree[rightChild]);

	node n;
	n.merge(l,r);
	return n;
}

void solve() {
	int n,c;
	int op,p,q;
	lint v;
	cin>>n>>c;
	build_tree(1,0,n-1);
	while(c--) {
		cin>>op;
		if(op) {
			cin>>p>>q;
			cout<<query_tree(1,0,n-1,p-1,q-1).sum<<endl;
		}
		else {
			cin>>p>>q>>v;
			update_tree(1,0,n-1,p-1,q-1,v);
		}
	}
}

int main(void) {

	ios::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif

	int t=1;
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
}