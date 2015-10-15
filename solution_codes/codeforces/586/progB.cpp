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
	cin>>n;
	vector<int> lane1(n-1);
	vector<int> lane2(n-1);
	vector<int> road(n);

	for(int i=0; i<n-1; i++)
		cin>>lane1[i];

	for(int i=0; i<n-1; i++)
		cin>>lane2[i];

	for(int i=0; i<n; i++)
		cin>>road[i];

	int minn1 = INF, minn2 = INF;

	for(int i=0; i<n; i++) {
		int sum = 0;

		sum += road[i];

		for(int j=0; j<i; j++)
			sum += lane1[j];

		for(int j=i; j<n-1; j++)
			sum += lane2[j];

		if(sum < minn1) {
			minn2 = minn1;
			minn1 = sum;
		}
		else if( sum < minn2) {
			minn2 = sum;
		}
	}
	cout<<minn1 + minn2<<endl;
}