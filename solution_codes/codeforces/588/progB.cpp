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
#define N 1000010
// #define N 100

 
using namespace std;
 
typedef vector<int> vint;
typedef vector<long long int> vlint;
typedef vector<vector<int> > vvint;
typedef vector<vector<long long int> > vvlint;
typedef long long int lint;
lint lp[N+1];
void solve(void);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
	/*
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
	*/
 
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
	return 0;
}

void populateSquarememo(vector<lint> &memo) {

	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			memo.push_back (i);
		}
		for (int j=0; j<(int) memo.size() && memo[j]<=lp[i] && i*memo[j]<=N; ++j)
			lp[i * memo[j]] = memo[j];
	}

	for(int i=0; i<(int) memo.size(); i++)
		memo[i] = memo[i] * memo[i];
}

bool hasFactor(const vector<lint> &memo, lint key) {
	
	for(int i=0; i<(int) memo.size() && memo[i] <= key; i++) {
		if(key % memo[i] == 0) {
			return true;
		}
	}
	return false;
}

void solve(void) {
	lint n;
	cin>>n;
	lint ans = -1;
	vector<lint> memo;
	populateSquarememo(memo);

	for( lint i=1; i <= (lint) sqrt(n); i++) {
		if(n%i == 0) {
			if(!hasFactor(memo, n/i)) {
				ans = max(ans, (lint) n/i);
			}
			if(!hasFactor(memo, i)) {
				ans = max(ans, (lint) i);
			}
		}
	}
	cout<<ans<<endl;
}