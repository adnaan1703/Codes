#include <iostream>
#include <vector>
using namespace std;

long long int smallC(int n, int r, int MOD) {
	vector<vector<long long int> > memoC(2, vector<long long int>(r+1, 0));

	for(int i=0; i<=n; i++) {
		for(int j=0; j<=r && j<=i; j++) {
			if(j==0 || j==i)
				memoC[i&1][j] = 1;
			else
				memoC[i&1][j] = (memoC[(i-1)&1][j-1] + memoC[(i-1)&1][j]) % MOD;
		}
	}
	return memoC[n&1][r];
}


long long int lucas(int n, int r, int p) {
	if(n==0 && r==0)
		return 1;
	int ni = n%p;
	int ri = r%p;
	if(ri > ni)
		return 0;
	return lucas(n/p, r/p, p) * smallC(ni, ri, p);
}


int main(void) {
	int n,r,p;
	cin>>n>>r>>p;
	cout<<lucas(n, r, p)<<endl;
	return 0;
}