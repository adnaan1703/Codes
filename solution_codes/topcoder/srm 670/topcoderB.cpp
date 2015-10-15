#include <bits/stdc++.h>
using namespace std;

class Drbalance {
public:
	int lesscng(string str, int k) {
		int n = str.size();

		int balance = 0;
		int counter = 0;
		int ans = 0;
		for(int i=0; i<n; i++) {
			if(str[i] == '+')
				balance++;
			else
				balance--;
			if(balance < 0)
				counter++;
		}

		while(counter > k) {
			ans++;
			
			for(int i=0; i<n; i++) {
				if(str[i] == '-') {
					str[i] = '+';
					break;
				}
			}

			balance = 0;
			counter = 0;

			for(int i=0; i<n; i++) {
			if(str[i] == '+')
				balance++;
			else
				balance--;
			if(balance < 0)
				counter++;
		}


		}
		return ans;
	}
};

int main(void) {
	string str = "---";
	int k = 0;
	Drbalance obj;
	cout<<obj.lesscng(str, k)<<endl;
}