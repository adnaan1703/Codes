
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
 
	
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
	
 
    int t = 1;
    cin>>t;
    while(t--)
        solve();
	return 0;
}

void solve(void) {
	int n,m;
	cin>>n>>m;
	vvint arr(n, vint(m));
	vint grundy(n);

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin>>arr[i][j];


	int nimber;
	for(int i=0; i<n; i++) {
		nimber = arr[i][m-1];
		for(int j=m-2; j>=0; j--) {
			if(arr[i][j] <= nimber)
				nimber = arr[i][j]-1;
			else
				nimber = arr[i][j];
		}
		grundy[i] = nimber;
	}

	nimber = grundy[0];
	for(int i=1; i<n; i++)
		nimber = nimber^grundy[i];

	if(nimber)
		cout<<"FIRST"<<endl;
	else
		cout<<"SECOND"<<endl;
}