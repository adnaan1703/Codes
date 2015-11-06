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

int main(void) {
	int op, a, b;
	DisjointSet ob(10);

	while(true) {
		cout<<"1. Union\n2. Find\nEnter : ";
		cin>>op;
		switch(op) {
			case 1:
				cin>>a>>b;
				ob.weighted_union(a,b);
				break;

			case 2:
				cin>>a>>b;
				cout<<ob.find(a,b)<<endl;
				break;
			default:
				cout<<"Re-enter : ";
		}
	}
	return 0;
}