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

using namespace std;


bool isGood(string str) {
    int count0 = 0, count1 = 0;
    for(char itr: str) {
        if(itr == '1') {
            count1++;
        } else {
            count0++;
        }
    }
    return count0 != count1;
}


int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int len;
    string str;
    cin>>len;
    cin>>str;
    if(len == 1 || isGood(str)) {
        cout<<1<<endl;
        cout<<str<<endl;
        return 0;
    }

    cout<<2<<endl;
    for(int i=0; i<len-1; i++) {
        cout<<str[i];
    }

    cout<<' '<<str[len-1]<<endl;
    return 0;
}