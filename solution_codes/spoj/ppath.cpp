/*
        ================================
        Author : Adnaan 'Zohran' Ahmed
       	Handle: adnaan1703
       	Heritage Institute of Technology
       	================================
*/
 
#include <bits/stdc++.h>
 
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF LONG_MAX
#define X first
#define Y second
#define pb push_back
 
using namespace std;
 
typedef vector<int> vint;
typedef vector<long long int> vlint;
typedef vector<vector<int> > vvint;
typedef vector<vector<long long int> > vvlint;
typedef long long int lint;
 
void solve(void);

class PrimeGenerator {

private:

	int N;
	vector<int> lp;
	vector<int> primes;
	vector<bool> map;

public:

	PrimeGenerator() {

		N = 10000;
		lp = vector<int>(N+1, 0);
		map = vector<bool>(N+1, false);

		
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

PrimeGenerator generator;

 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1;
    cin>>t;
    while(t--)
        solve();
	return 0;
}

inline int replaceNum(int number, int digit, int pos) {
	int indx = 3;
	int arr[4] = {0};
	while(number) {
		arr[indx--] = number%10;
		number /= 10;
	}
	arr[pos] = digit;
	number = 0;
	for(int i=0; i<4; i++)
		number = number*10 + arr[i];
	return number;
}

void solve(void) {
	int source, target;
	cin>>source>>target;

	queue<pair<int, int> > mQueue;
	mQueue.push({source,0});
	vector<bool> visited(10001, false);

	while(!mQueue.empty()) {
		int node = mQueue.front().X;
		int dist = mQueue.front().Y;
		mQueue.pop();

		if(node == target) {
			cout<<dist<<endl;
			break;
		}

		for(int i=0; i<4; i++) {
			for(int j=0; j<=9; j++) {
				if(j == 0 && (i == 0 or i == 3))
					continue;

				int number = replaceNum(node, j, i);
				if(!generator.isPrime(number) or visited[number])
					continue;

				mQueue.push({number, dist+1});
				visited[number] = true;
			}
		}
	}
}