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

typedef vector<bool>                    vbool;
typedef vector<string>                  vstring;
typedef vector<long long int>           vlint;
typedef vector<vector<int> >            vvint;
typedef vector<vector<long long int> >  vvlint;
typedef long long int                   lint;
typedef vector<int>                     vint;

void solve(void);
int maxSubsetSum(vector<int> arr);

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
    int len;
    cin>>len;
    vint arr(len);
    loop(len) {
        cin>>arr[i];
    }
    cout<<maxSubsetSum(arr)<<endl;
}

int maxSubsetSum(vector<int> arr) {
    int n = arr.size();
    vlint state(n);
    loop(n) {
        if(i==0) {
            state[i] = arr[i];
            continue;
        } else if(i==1) {
            state[i] = max(arr[0], arr[1]);
            continue;
        }

        state[i] = max(max(state[i-2] + arr[i], state[i-2]), max(state[i-1], (lint)arr[i]));
    }
    return state[n-1];
}