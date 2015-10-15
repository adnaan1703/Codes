#include <bits/stdc++.h>
using namespace std;

int logTable[100005];

void initLogTable(int n) {
	logTable[0] = logTable[1] = 0;
	for(int i=2; i<=n; i++)
		logTable[i] = logTable[i>>1]+1;
}

void initSparseTable(vector<int> &arr, vector<vector<int> > &sparse, int n) {
	for(int i=1; i<=n; i++)
		sparse[0][i] = arr[i-1];

	for(int i=1; i <= logTable[n]; i++) {
		for(int j=1; j <= n; j++) {
			sparse[i][j] = min(sparse[i-1][j], sparse[i-1][j+(1<<(i-1))]);
		}
	}
}

int querySparseTable(vector<vector<int> > &sparse, int l, int r) {
	int k = logTable[r-l+1];
	return min(sparse[k][l], sparse[k][r-(1<<k)+1]);
}

int main(void) {
	int n = 10;
	vector<int> arr = {34,12,6,67,1,-646,34,0,3,11};
	initLogTable(n+1);
	vector<vector<int> > sparse(logTable[n+1]+1, vector<int>(n+1));
	initSparseTable(arr, sparse, n);
	int l,r;
	n*=5;
	while(n--) {
		cin>>l>>r;
		cout<<querySparseTable(sparse, l, r)<<endl;
	}
	return 0;

}