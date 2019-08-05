/*
    LEETCODE
    url: https://leetcode.com/problems/longest-consecutive-sequence/
    level: HARD
 */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>

#include <queue>
#include <vector>
#include <unordered_map>
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



class DisjointSet {

private:
	int length;
	vector<int> nodes;
	vector<int> size;

	int root(int i) {
		while(nodes[i] != i) {
			nodes[i] = nodes[nodes[i]];
			i = nodes[i];
		}
		return i;
	}

public:

	DisjointSet() {
		length = 1e6;
		DisjointSet(length);
	}

	DisjointSet(int len) {
		length = len;
		nodes = vector<int>(length);
		size = vector<int>(length, 1);

		for(int i=0; i<length; i++) {
			nodes[i] = i;
		}
	}

	void weighted_union(int a, int b) {

		int root_a = root(a);
		int root_b = root(b);

		if(size[root_a] < size[root_b]) {
			nodes[root_a] = nodes[root_b];
			size[root_b] += size[root_a];
		}
		else {
			nodes[root_b] = nodes[root_a];
			size[root_a] += size[root_b];
		}

	}

	bool find(int a, int b) {

		if(root(a) == root(b))
			return true;
		
		return false;
	}

};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> hash;
        for(auto itr : nums) {
            int left = hash[itr - 1];
            int right = hash[itr + 1];
            hash[itr] = left + right + 1;
            ans = max(ans, hash[itr]);
        }
        return ans;
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
    Solution solution;
    vint arr = {100, 4, 200, 1, 3, 2};
    cout<<solution.longestConsecutive(arr)<<endl;
}