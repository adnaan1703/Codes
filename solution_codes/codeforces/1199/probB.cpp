#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>

#include <queue>
#include <vector>
#include <set>
#include <map>

#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF LONG_MAX
#define X first
#define Y second
#define pb push_back
#define rep(i,a,b) for(int i=a; i<=b; i++)
#define FILEIN  freopen("in.txt", "r", stdin);
#define loop(n) for(int i=0; i<n; i++)
#define FAST_INPUT ios::sync_with_stdio(false);cin.tie(NULL);
#define FILEOUT freopen("out.txt", "w", stdout);
#define DB(A) cout<<#A<<" ==> "<<A<<endl;

using namespace std;

typedef long long int                   lint;
typedef vector<int>                     vint;
typedef vector<long long int>           vlint;
typedef vector<bool>                    vbool;
typedef vector<string>                  vstring;
typedef vector<vector<int> >            vvint;
typedef vector<vector<long long int> >  vvlint;
typedef vector<vector<bool> >           vvbool;

void solve(void);

int main(void)
{
    FAST_INPUT
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}

void solve(void) {
    double h, l;
    cin>>h;
    cin>>l;

    long double numerator = pow(l,2) - pow(h,2);
    long double deno = 2.0*h;
    cout<<fixed;
    cout<<setprecision(12);
    cout<<numerator/deno<<endl;
}