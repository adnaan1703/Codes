#include <bits/stdc++.h>
using namespace std;

class PrimeGenerator {

private:

	int N;
	vector<int> lp;
	vector<int> primes;
	vector<bool> map;

public:

	PrimeGenerator() {

		lp = vector<int>(1000001, 0);
		map = vector<bool>(1000001, false);
		N = 1000000;

		
		for (int i = 2; i <= N; ++i) {
			if (lp[i] == 0) {
				lp[i] = i;
				primes.push_back (i);
				map[i] = true;
			}

			for (int j = 0; j < (int)primes.size() && primes[j] <= lp[i] && i*primes[j] <= N; ++j)
				lp[i * primes[j]] = primes[j];
		}		
	}


	// 1 indexed
	int getPrimeAt(int n) {
		return primes.at(n-1);
	}

	// inclusive of right end
	vector<int> getPrimesInRange(int end) {
		vector<int> ret(primes.begin(), primes.begin()+end);
		return ret;
	}

	// inclusive of both left and right ends & 1 indexed
	vector<int> getPrimesInRange(int start, int end) {
		vector<int> ret (primes.begin()+start-1, primes.begin()+end);
		return ret;
	}

	bool isPrime(int n) {
		return map[n];
	}
};

int main() {
	PrimeGenerator ob;
	cout<<ob.getPrimeAt(4)<<endl;
	cout<<ob.isPrime(12)<<endl;
	cout<<ob.isPrime(7)<<endl;
	vector<int> ans = ob.getPrimesInRange(3, 5);
	for(auto itr : ans)
		cout<<itr<<' ';
	cout<<endl;
	return 0;
}
