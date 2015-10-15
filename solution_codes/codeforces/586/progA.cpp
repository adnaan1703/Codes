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
	cin>>n;
	int counter = 0, indx;
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	for(indx = 0; indx<n; indx++) {
		if(arr[indx] == 1)
			break;
	}

	for(int i=indx; i<n; ++i) {
		if(arr[i] == 1)
			counter++;
		else if( i != n-1) {

			if(arr[i] == 0 && arr[i+1] == 1)
				counter++;
			else {
				while(arr[i+1] != 1 && i<n-1) {
					i++;
				}
			}
		}
	}
	cout<<counter<<endl;
}