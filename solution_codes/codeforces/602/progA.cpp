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
 
    
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif
    
 
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}

void solve(void) {
    int n,m;
    cin>>n>>m;

    lint a = 0, b = 0;
    while(n!=0) {
        int tmp;
        cin>>tmp;
        a += (tmp * (pow(m,n-1)));
        n--;
    }

    cin>>n>>m;
    while(n!=0) {
        int tmp;
        cin>>tmp;
        b += (tmp * (pow(m,n-1)));
        n--;
    }
    if(a == b) {
        cout<<'='<<endl;
    }
    else if(a>b)
        cout<<'>'<<endl;
    else
        cout<<'<'<<endl;
}