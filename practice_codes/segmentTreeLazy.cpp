/*
                C++ TEMPLATE
                =========================================
                Author : Adnaan 'Zohran' Ahmed
                Handle: adnaan1703
                Heritage Institute of Technology
                Category: Segment Tree Lazy Propagation
                =========================================

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

#define N 4000000

vector<int> arr(N/4);
vector<int> tree(N);
vector<int> lazy(N,0);

void build_tree(int node,int a,int b)
{
        if(a>b)
                return;

        if(a==b)
        {
                tree[node]=arr[a];
                return;
        }

        build_tree(node<<1,a,(a+b)>>1);
        build_tree(1+(node<<1),1+((a+b)>>1),b);

        tree[node] = max(tree[node<<1],tree[1+(node<<1)]);
}

void update_tree(int node,int a,int b,int i,int j,int val)
{
        if(lazy[node]!=0)
        {
                tree[node]+=lazy[node];
                if(a!=b)
                {
                        lazy[node<<1]+=lazy[node];
                        lazy[1+(node<<1)]+=lazy[node];
                }
                lazy[node]=0;
        }

        if(a>b || a>j || b<i)
                return;

        if(a>=i && b<=j)
        {
                tree[node]+=val;
                if(a!=b)
                {
                        lazy[node<<1]+=val;
                        lazy[1+(node<<1)]+=val;
                }
                return;
        }

        update_tree(node<<1,a,(a+b)>>1,i,j,val);
        update_tree(1+(node<<1),1+((a+b)>>1),b,i,j,val);

        tree[node] = max(tree[node<<1],tree[1+(node<<1)]);
}

int query_tree(int node,int a,int b,int i,int j)
{
        if(a>b || a>j || b<i)
                return -INF;

        if(lazy[node]!=0)
        {
                tree[node]+=lazy[node];
                if(a!=b)
                {
                        lazy[node<<1]+=lazy[node];
                        lazy[1+(node<<1)]+=lazy[node];
                }
                lazy[node]=0;
        }

        if(a>=i && b<=j)
                return tree[node];

        int q1 = query_tree(node<<1,a,(a+b)>>1,i,j);
        int q2 = query_tree(1+(node<<1),1+((a+b)>>1),b,i,j);

        return max(q1,q2);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n=100;

	for(int i=0;i<n;i++)
                arr[i]=1;

        build_tree(1,0,n-1);

	update_tree(1,0,n-1,0,6,5);
	update_tree(1,0,n-1,10,n-1,100);
	update_tree(1,0,n-1,7,10,12);

        cout<<query_tree(1,0,n-1,0,n-1)<<endl;

	return 0;
}
