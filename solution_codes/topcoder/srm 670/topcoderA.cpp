#include <bits/stdc++.h>
using namespace std;

class Cdgame {
public:
	int rescount(vector<int> a, vector<int> b) {
		int counter = 0;
		set<int> myset;
		int sum1 = 0, sum2 = 0;
		for(int i=0; i<(int)a.size(); i++) {
			sum1 += a[i];
			sum2 += b[i];
		}

		for(int i=0; i<(int)a.size(); i++) {
			int tmpSum1 = sum1-a[i];
			for(int j=0; j<(int)b.size(); j++) {
				int tmpSum2 = sum2-b[j];
				int check = (tmpSum1+b[j])*(tmpSum2+a[i]);

				if(myset.find(check) == myset.end()) {
					counter++;
					myset.insert(check);
				}
			}
		}
		return counter;
	}
};

int main(void) {
	vector<int> a = {1,1,1};
	vector<int> b = {1,1,1};
	Cdgame obj;
	cout<<obj.rescount(a,b)<<endl;
	return 0;
}