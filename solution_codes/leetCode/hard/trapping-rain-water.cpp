/*
    LEETCODE
    url: https://leetcode.com/problems/trapping-rain-water/
    level: HARD
 */


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

class Solution {
    public:
    int trap(vector<int> &arr) {
        int ans = 0;

        if(arr.size() == 0) {
            return 0;
        }

        vector<int> leftHeight = getLeftMax(arr);
        vector<int> rightHeight = getRightMax(arr);

        for(int i=0; i<arr.size(); i++) {
            int limit = min(leftHeight[i], rightHeight[i]);
            ans += limit >= arr[i] ? limit - arr[i] : 0;
        }
        return ans;
    }

    vector<int> getLeftMax(vector<int> &arr) {
        vector<int> maxArr(arr.size());
        int maxx = arr[0];
        for(int i=0; i<arr.size(); i++) {
            maxx = max(maxx, arr[i]);
            maxArr[i] = maxx;
        }
        return maxArr;
    }

    vector<int> getRightMax(vector<int> &arr) {
        int len = arr.size();
        vector<int> maxArr(len);
        int maxx = arr[len-1];
        for(int i=len-1; i>=0; i--) {
            maxx = max(maxx, arr[i]);
            maxArr[i] = maxx;
        }
        return maxArr;
    }
};

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
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution solution;
    cout<<solution.trap(arr)<<endl;
}