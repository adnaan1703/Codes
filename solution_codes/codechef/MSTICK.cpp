
/*
        ================================
        Author : Adnaan 'Zohran' Ahmed
       	Handle: adnaan1703
       	Heritage Institute of Technology
       	================================
*/
 
#include <bits/stdc++.h>
 
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF LONG_MAX
#define X first
#define Y second
#define pb push_back
 
using namespace std;
 
typedef vector<int> vint;
typedef vector<long long int> vlint;
typedef vector<vector<int> > vvint;
typedef vector<vector<long long int> > vvlint;
typedef long long int lint;

struct node {
	int maxVal;
	int minVal;

	void merge(node &lhs, node &rhs) {
		maxVal = max(lhs.maxVal,rhs.maxVal);
		minVal = min(lhs.minVal, rhs.minVal);
	}
};

int logTable[100005];

void initLogTable(int n) {
	logTable[0] = logTable[1] = 0;
	for(int i=2; i<=n; i++)
		logTable[i] = logTable[i>>1]+1;
}

void initSparseTable(vector<int> &arr, vector<vector<node> > &sparse, int n) {
	for(int i=1; i<=n; i++){
		sparse[0][i].maxVal = arr[i-1];
		sparse[0][i].minVal = arr[i-1];
	}

	for(int i=1; i <= logTable[n]; i++) {
		for(int j=1; j <= n; j++) {
			sparse[i][j].merge(sparse[i-1][j], sparse[i-1][j+(1<<(i-1))]);
		}
	}
}

node querySparseTable(vector<vector<node> > &sparse, int l, int r) {
	int k = logTable[r-l+1];
	node ret;
	ret.merge(sparse[k][l], sparse[k][r-(1<<k)+1]);
	return ret;
}



void solve(void);
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    while(t--)
        solve();
	return 0;
}

void solve(void) {
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	initLogTable(n+1);
	vector<vector<node> > sparse(logTable[n+1]+1, vector<node>(n+1));
	initSparseTable(arr, sparse, n);
	int m,l,r;
	cin>>m;
	while(m--) {
		cin>>l>>r;
		int t = querySparseTable(sparse, l+1, r+1).minVal;
		float ans = 0.0;
		int maxx1 = querySparseTable(sparse, 1, l).maxVal;
		int maxx2 = querySparseTable(sparse, r+2, n+1).maxVal;
		int maxx3 = querySparseTable(sparse, l+1, r+1).maxVal;

		float maxxF = ((float) maxx3-t)/2.0;
		if(maxx1 > maxx2 && maxx1 >maxxF)
			ans = (float) maxx1;
		else if(maxx2 > maxxF)
			ans = (float) maxx2;
		else
			ans = (float) maxxF;

		ans = (float)(t+ans);
		printf("%.1f\n", ans);
	}

}