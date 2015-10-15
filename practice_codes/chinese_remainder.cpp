#include <iostream>
#include <vector>
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

int chinese_remainder(vector<int> base, vector<int> mod) {
	int n = base.size();
	int p, prod = 1, sum = 0;

	for(int i=0; i<n; i++)
		prod *= mod[i];

	for(int i=0; i<n; i++) {
		p = (prod/mod[i]);
		cout<<p<<endl;
		sum += base[i]*findMMI_fermat(p,mod[i])*p;
	}
	return sum%prod;
}

int main(void) {
	vector<int> base = {2,2,1};
	vector<int> mod = {3,4,5};
	cout<<chinese_remainder(base, mod)<<endl;
	return 0;
}