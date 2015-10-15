/*
                C++ TEMPLATE
                ================================
                Author : Adnaan 'Zohran' Ahmed
                Handle: adnaan1703
                Heritage Institute of Technology
                Category: Matrix Recurrence
                ================================

*/

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<climits>
#include<cstring>

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

class Array2d
{
public:
        int mat[3][3];
        Array2d()
        {
                memset(mat,0,sizeof mat);
        }
};

Array2d mat_mul(Array2d a,Array2d b)
{
        Array2d c;
        for(int i=0;i<3;i++)
                for(int j=0;j<3;j++)
                        for(int k=0;k<3;k++)
                                c.mat[i][j] += (a.mat[i][k]*b.mat[k][j]);
        return c;
}

Array2d fast_exp(Array2d arr,int n)
{
        if(n==1)
                return arr;
        Array2d temp;
        temp = fast_exp(arr,n>>1);
        if(n&1)
                return mat_mul(arr,mat_mul(temp,temp));
        else
                return mat_mul(temp,temp);
}

int tribonacci(int n)
{
        if(n==0)
                return 0;
        if(n==1)
                return 1;
        if(n==2)
                return 1;
        if(n==3)
                return 2;
        Array2d arr;
        arr.mat[0][0]=arr.mat[0][1]=arr.mat[0][2]=arr.mat[1][0]=arr.mat[2][1]=1;
        arr=fast_exp(arr,n-3);
        int res=arr.mat[0][1]+arr.mat[0][2]+(arr.mat[0][0]<<1);
        return res;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

        for(int i=0;i<=20;i++)
        {
                cout<<tribonacci(i)<<endl;
        }

        return 0;

}
