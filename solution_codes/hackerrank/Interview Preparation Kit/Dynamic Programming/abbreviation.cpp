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
typedef vector<vector<bool> >           vvbool;
typedef long long int                   lint;
typedef vector<int>                     vint;

void solve(void);
string abbreviation(string a, string b);

int main(void)
{
    FAST_INPUT
    int t = 1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}

void solve(void) {
    string str1, str2;
    cin>>str1>>str2;
    cout<<abbreviation(str1, str2)<<endl;
}

bool isCapOf(char ch1, char ch2) {
    return ch2 == toupper(ch1);
}

void fillBase(vvbool &dp, string &a) {
    int rows = dp.size();
    int cols = dp[0].size();
    dp[0][0] = true;
    for(int i=1; i<rows; i++) {
        dp[i][0] = dp[i-1][0] && islower(a[i-1]);
    }
}

string abbreviation(string a, string b) {
    int rows = a.length() + 1;
    int cols = b.length() + 1; 
    vvbool dp(rows, vbool(cols, false));
    fillBase(dp, a);
    for(int i=1; i<rows; i++) {
        for(int j=1; j<cols; j++) {
            bool cond1 = dp[i-1][j-1] && isCapOf(a[i-1], b[j-1]); // using the upper case(d) character
            bool cond2 = dp[i-1][j] && islower(a[i-1]); // deleting the lower case character
            dp[i][j] = cond1 || cond2;
        }
    }

    return dp[rows-1][cols-1] ? "YES" : "NO";
}