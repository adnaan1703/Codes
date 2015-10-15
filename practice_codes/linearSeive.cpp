#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define N 10000000
int lp[N+1];

int main() {
	vector<int> pr;
	freopen("out.txt","w",stdout);
 
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back (i);
			cout<<i<<" ";
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
			lp[i * pr[j]] = pr[j];
	}

	return 0;
}