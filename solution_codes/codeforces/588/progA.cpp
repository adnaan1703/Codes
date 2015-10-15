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
	int n;
	lint sum = 0;
	cin>>n;
	vector<int> meat(n);
	vector<int> cost(n);

	for(int i=0; i<n; i++) {
		cin>>meat[i]>>cost[i];
	}

	int check = cost[0];
	int i=0;
	while(i<n) {
		if(check <= cost[i]) {
			sum += (meat[i]*check);
			i++;
		}
		else {
			check = cost[i];
		}
	}
	cout<<sum<<endl;
}