#include <iostream>
#include <vector>
using namespace std;

long long int computeC(int n, int r, int mod) {
	vector<vector<long long int> > memoC(n+1, vector<long long int>(r+1,0));

	for(int i=0; i<=n; i++) {
		for(int j=0; j<=r && j<=i; j++) {
			if(j==0 || j==i)
				memoC[i][j] = 1;
			else
				memoC[i][j] = (memoC[i-1][j-1] + memoC[i-1][j])%mod;
		}
	}
	return memoC[n][r];
}

int main(void) {
	int n,r,mod;
	cin>>n>>r>>mod;
	cout<<computeC(n,r,mod)<<endl;
}
