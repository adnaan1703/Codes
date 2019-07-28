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
lint candies(vint arr, int n);

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
    int n;
    cin>>n;
    vint arr(n);
    loop(n) {
        cin>>arr[i];
    }

    cout<<candies(arr, n)<<endl;
}

void fillBase(vlint &dp, vint &arr, int n) {
    loop(n) {
        if(i == 0 && arr[i] <= arr[i+1]) {
            dp[i] = 1;
        } else if( i == n-1 && arr[i] <= arr[i-1]) {
            dp[i] = 1;
        } else if(i < n-1 && arr[i] <= arr[i-1] && arr[i] <= arr[i+1]) {
            dp[i] = 1;
        }
    }
}

lint fillCandies(vlint &dp, vint &arr, int i) {
    if(i < 0 || i >= arr.size()) {
        return INF;
    }

    if(dp[i] != -1) {
        return dp[i];
    }

    dp[i] = min(fillCandies(dp, arr, i-1), fillCandies(dp, arr, i+1)) + 1;
    return dp[i];
}

lint sumOfCandies(vlint &dp) {
    lint sum = 0;
    for(auto itr : dp) {
        sum += itr;
    }
    return sum;
}

lint candies(vint arr, int n) {
    if(n == 1) {
        return 1;
    }

    vlint dp(n, -1);
    fillBase(dp, arr, n);
    fillCandies(dp, arr, n-1);
    return sumOfCandies(dp);
}