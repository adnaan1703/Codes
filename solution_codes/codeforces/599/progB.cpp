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
	int n;
	int counter = 0;
	cin>>n;
	vint arr(n);

	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}

	vint memo(n, 0);
	memo[n-1] = arr[n-1];
	for(int i = n-2; i>=0; i--) {
		memo[i] = min(arr[i], memo[i+1]);
	}

	int pivot = arr[0];
	for(int i=0; i<n-1; i++) {
		pivot = max(pivot, arr[i]);
		if(memo[i+1] >= pivot)
			counter++;
	}
	cout<<counter+1<<endl;
}