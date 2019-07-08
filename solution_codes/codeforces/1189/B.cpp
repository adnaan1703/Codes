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
#define rep(a,b) for(int i=a; i<=b; i++)
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

bool isValid(vint arr) {
    bool valid = true;
    int len = arr.size();
    if(len <= 1) {
        return true;
    }

    for(int i=0; i<len && valid; i++) {
        if(i == 0) {
            valid &= (arr[i] < (arr[i+1] + arr[len-1]));
        } else if(i == len-1) {
            valid &= (arr[i] < (arr[i-1] + arr[0]));
        } else {
            valid &= (arr[i] < (arr[i-1] + arr[i+1]));
        }
    }
    return valid;
}

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
    vint center;
    vint left;
    vint right;
    vint ans;
    int end = len;
    
    loop(len) {
        cin>>arr[i];
    }
    
    sort(arr.begin(), arr.end());
    center.pb(arr[0]);
    if(len % 2 == 0) {
        center.push_back(arr[len-1]);
        end--;
    }

    bool isLeft = true;
    rep(1, end-1) {
        if(isLeft) {
            left.push_back(arr[i]);
        } else {
            right.push_back(arr[i]);
        }
        isLeft = !isLeft;
    }

    ans.push_back(center[0]);
    for(auto itr : left) {
        ans.push_back(itr);
    }
    if(center.size() > 1) {
        ans.push_back(center[1]);
    }
    for(int i=right.size() - 1; i>=0; i--) {
        ans.push_back(right[i]);
    }
    if(isValid(ans)) {
        cout<<"YES"<<endl;
        for(auto itr : ans) {
            cout<<itr<<' ';
        }
        cout<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}