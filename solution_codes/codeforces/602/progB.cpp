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
	vint inp(n);
	vector<pair<int, int> > arr;

	for(int i=0; i<n; i++) {
		cin>>inp[i];
	}

	int counter = 1;
	for(int i=0; i<n; i++) {
		if(i+1 != n and inp[i] == inp[i+1]) {
			counter++;
			continue;
		}
		else {
			arr.pb({inp[i], counter});
			counter = 1;
		}
	}

	// for(auto itr : arr) {
	// 	cout<<itr.X<<' '<<itr.Y<<endl;
	// }

	if(arr.size() == 1) {
		cout<<arr[0].Y<<endl;
		return;
	}

	int minn = min(arr[0].X, arr[1].X);
	int maxx = max(arr[0].X, arr[1].X);

	counter = 0;
	if(abs(minn - maxx) <= 1)
		counter = arr[0].Y + arr[1].Y;

	int ans = counter;
	for(int i=2; i<(int) arr.size(); i++) {
		if(minn != -1 and maxx != -1) {
			if(arr[i].X == minn || arr[i].X == maxx) {
				counter += arr[i].Y;
			}
			else {
				if(abs(arr[i].X - arr[i-1].X) <= 1) {
					minn = min(arr[i].X, arr[i-1].X);
					maxx = max(arr[i].X, arr[i-1].X);
					ans = max(ans, counter);
					counter = arr[i-1].Y + arr[i].Y;
				}
				else {
					minn = arr[i].X;
					maxx = -1;
					ans = max(ans, counter);
					counter = arr[i].Y;
				}
			}
		}

		else if(minn != -1) {
			if(abs(minn - arr[i].X) <= 1) {
				maxx = max(minn, arr[i].X);
				minn = min(minn, arr[i].X);
				counter += arr[i].Y;
			}
			else {
				minn = arr[i].X;
				ans = max(ans, counter);
				counter = arr[i].Y;
			}
		}
	}
	ans = max(ans, counter);
	cout<<ans<<endl;
}