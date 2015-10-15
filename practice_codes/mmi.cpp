/*
                C++ TEMPLATE
                ================================
                Author : Adnaan 'Zohran' Ahmed
                Handle: adnaan1703
                Heritage Institute of Technology
                Category: find MMI
                ================================

*/

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>

#include<queue>
#include<vector>
#include<set>

#include<iostream>
#include<iterator>
#include<string>
#include<algorithm>
#include<functional>
#include<utility>


#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF LONG_MAX
#define X first
#define Y second
#define pb push_back

using namespace std;

int fast_pow(long long base, long long n,long long M)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
int findMMI_fermat(int n,int M)
{
    return fast_pow(n,M-2,M);
}

int main() {
	// your code goes here
	int n;
	cout<<"Enter the number to find its mmi : ";
	cin>>n;
	int ans = findMMI_fermat(n,1000000007);
	cout<<ans<<endl;
	return 0;
}
