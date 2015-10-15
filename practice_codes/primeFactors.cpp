/*
                C++ TEMPLATE
                ================================
                Author : Adnaan 'Zohran' Ahmed
                Handle: adnaan1703
                Heritage Institute of Technology
                Category: Finds all Prime Factors
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

void primeFactors(unsigned long long n)
{
        unsigned long long counter = 0;
        vector<int> vec;
        while(!(n&1))
        {
               vec.pb(2);
               n/=2;
               counter++;
        }
        for(unsigned long long i=3;i<=sqrt(n);i+=2)
        {
                while(n%i==0)
                {
                        counter++;
                        vec.pb(i);
                        n/=i;
                }
        }
        if(n>2)
        {
                counter++;
                vec.pb(n);
        }

        cout<<counter<<endl;
        for(vector<int>::iterator itr = vec.begin();itr!=vec.end();itr++)
                cout<<*itr<<endl;
        vec.clear();
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

        int t;
        cin>>t;
        while(t--)
        {
                unsigned long long n;
                cin>>n;
                primeFactors(n);
        }
	return 0;
}
