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
#define INF INT_MAX
#define X first
#define Y second
#define pb push_back
 
using namespace std;
 
typedef vector<int> vint;
typedef vector<long long int> vlint;
typedef vector<vector<int> > vvint;
typedef vector<vector<long long int> > vvlint;
typedef long long int lint;
 
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

void solve(void) {
	int n,m;
	cin>>n>>m;
	vint b(m);
	vint a(m);
	vvint f(n+1, vint(0));
	bool ambiguity = false;

	for(int i=1; i<=n; i++) {
		int tmp;
		cin>>tmp;
		f[tmp].pb(i);
	}

	for(int i=0; i<m; i++)
		cin>>b[i];

	for(int i=0; i<m; i++) {
		
		if(f[b[i]].size() == 0) {
			cout<<"Impossible"<<endl;
			return;
		}

		if(f[b[i]].size() > 1)
			ambiguity = true;

		auto itr = f[b[i]].begin();
		a[i] = *itr;
	}

	if(ambiguity) {
		cout<<"Ambiguity"<<endl;
		return;
	}

	cout<<"Possible"<<endl;
	for(auto it : a) {
		cout<<it<<' ';
	}
	cout<<endl;
}