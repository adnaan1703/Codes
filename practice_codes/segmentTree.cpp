/*
                C++ TEMPLATE
                ================================
                Author : Adnaan 'Zohran' Ahmed
                Handle: adnaan1703
                Heritage Institute of Technology
                Category : Segment Tree
                ================================

*/

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<iostream>
#include<queue>
#include<vector>
#include<set>
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

vector<int> tree(4000000);
vector<int> arr(1000000);

void build_segment(int node,int a,int b)
{
        if(a>b)
                return;

        if(a==b)
        {
                tree[node] = arr[a];
                return;
        }

        build_segment(node<<1,a,(a+b)>>1);
        build_segment((node<<1)+1,((a+b)>>1)+1,b);

        tree[node] = max(tree[node<<1],tree[(node<<1)+1]);
}

void update_segment(int node,int a,int b,int i,int j,int val)
{
        if(a>b || a>j || b<i)
                return;

        if(a==b)
        {
                tree[node] += val;
                return;
        }

        update_segment(node<<1,a,(a+b)>>1,i,j,val);
        update_segment((node<<1)+1,((a+b)>>1)+1,b,i,j,val);

        tree[node] = max(tree[node<<1],tree[(node<<1)+1]);
}

int query_segment(int node,int a,int b,int i,int j)
{
        if(a>b || a>j || b<i)
                return -INF;

        if(a>=i && b<=j)
                return tree[node];

        int q1 = query_segment(node<<1,a,(a+b)>>1,i,j);
        int q2 = query_segment((node<<1)+1,((a+b)>>1)+1,b,i,j);

        int ret = max(q1,q2);
        return ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

        int n;

        cin>>n;

        for(int i=0;i<n;i++)
                cin>>arr[i];

        build_segment(1,0,n-1);

        int q;
        cin>>q;

        while(q--)
        {
                int l,r;
                cin>>l>>r;
                cout<<query_segment(1,0,n-1,l,r)<<endl;
        }

	return 0;
}
