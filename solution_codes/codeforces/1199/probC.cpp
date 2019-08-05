#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>

#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

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

int main(void)
{
    FAST_INPUT
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}

lint power(lint x, lint y)  
{  
    lint temp;  
    if(y == 0)  
        return 1;  
    temp = power(x, y / 2);  
    if (y % 2 == 0)  
        return temp * temp;  
    else
    {  
        return x * temp * temp;  
    }  
}  

lint calculateK(lint n, lint i) {
    lint pow = (lint) i/n;
    return power(2, pow);
}

void solve(void) {
    lint n, i;
    cin>>n;
    cin>>i;
    i *= 8;
    
    vint record(n);
    vint num;
    unordered_map<int, lint> hash;
    int distinct = 0;
    
    loop(n) {
        int temp;
        cin>>temp;
        record[i] = temp;
        if(hash[temp] == 0) {
            hash[temp] = 1;
            distinct++;
            num.push_back(temp);
        } else {
            hash[temp] = hash[temp]+1;
        }
    }
    lint maxK = calculateK(n, i);
    sort(num.begin(), num.end());

    lint sum = 0;

    for(int i=0; i<maxK && i<num.size(); i++) {
        sum += hash[num[i]];
    }

    lint maxSum = sum, maxL = 0, maxR = maxK < num.size() ? maxK - 1 : num.size()-1;

    for(int i=maxK, j=1; i < num.size(); i++, j++) {
        sum -= hash[num[j-1]];
        sum += hash[num[i]];
        if(sum > maxSum) {
            maxSum = sum;
            maxL = j;
            maxR = i;
        }
    }
    
    int valL = num[maxL];
    int valR = num[maxR];
    int ans = 0;
    
    loop(n) {
        if(record[i] < valL || record[i] > valR) {
            ans++;
        }
    }

    cout<<ans<<endl;
}