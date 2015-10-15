
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
    //cin>>t;
    while(t--)
        solve();
	return 0;
}

struct node
{
	int val;
	int player1;
	int player2;
};

bool myComp(node lhs, node rhs) {
	return (lhs.val > rhs.val);
}

void solve(void) {
	int n,tmp;
	node element;
	cin>>n;
	vector<node> arr;
	vector<int> memo(2*n, -1);

	for(int i=2; i<=2*n; i++) {
		for(int j=1; j<i; j++) {
			cin>>tmp;
			element.val = tmp;
			element.player1 = i;
			element.player2 = j;
			arr.pb(element);
		}
	}

	sort(arr.begin(), arr.end(), myComp);

	for(vector<node>::iterator itr = arr.begin(); itr != arr.end(); itr++) {
		element = *itr;
		if(memo[element.player1-1] == -1 && memo[element.player2-1] == -1) {
			memo[element.player1-1] = element.player2;
			memo[element.player2-1] = element.player1;
		}
	}

	for(vector<int>::iterator itr = memo.begin(); itr != memo.end(); itr++)
		cout<<*itr<<" ";
}