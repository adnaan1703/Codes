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

struct node {

	int indx;
	int volume;
	int cry;
	lint confidence;

};
 
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
	int childNumber = 1;
	cin>>n;
	vector<node> arr(n);
	vector<int> ans;
	
	for(int i=0; i<n; i++) {
		cin>>arr[i].volume>>arr[i].cry>>arr[i].confidence;
		arr[i].indx = childNumber;
		childNumber++;
	}

	list<node> queue (arr.begin(), arr.end());

	while(!queue.empty()) {
		
		node entry = queue.front();
		queue.pop_front();
		ans.pb(entry.indx);

		int factor = 0;
		for(auto itr = queue.begin(); itr != queue.end() && factor < entry.volume; ++itr) {
			(*itr).confidence -= (entry.volume-factor);
			++factor;
		}

		/*		REMOVE CRY BABIES			*/
		bool flag = true;
		while(flag) {
			flag = false;
			for(auto itr = queue.begin(); itr != queue.end(); ++itr) {
				if( (*itr).confidence < 0 ) {
					
					flag = true;
					for(auto itr2 = itr; itr2 != queue.end(); ++itr2) {
						(*itr2).confidence -= (*itr).cry;
					}
					queue.erase(itr);
					break;
				}
			}
		}

	}

	cout<<ans.size()<<endl;
	for(auto itr = ans.begin(); itr != ans.end(); ++itr)
		cout<<*itr<<' ';
	cout<<endl;
}