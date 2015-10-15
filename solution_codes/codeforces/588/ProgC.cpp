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
	int tmp;
	int counter = 0;
	cin>>n;
	priority_queue<int, vector<int>, greater<int> > list;
	for(int i=0; i<n; i++) {
		cin>>tmp;
		list.push(tmp);
	}

	while(!list.empty()) {
		int node1 = list.top();
		list.pop();
		
		if(list.empty()) {
			counter++;
			break;
		}

		int node2 = list.top();
		if(node1 != node2) {
			counter++;
		}
		else {
			list.pop();
			list.push(node1 + 1);
		}
	}
	cout<<counter<<endl;
}