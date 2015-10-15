#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getLPS(string pattern, int len, vector<int> &lps) {

	int index = 0;
	int i = 1;

	lps[0] = 0;

	while (i<len) {
		
		if(pattern.at(i) == pattern.at(index)) {
			index++;
			lps[i] = index;
			i++;
		}
		else{
			if(index!=0)
				index = lps[index-1];
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPmatching(string text, string pattern) {
	
	int n = text.size();
	int m = pattern.size();
	int i = 0, j = 0;

	vector<int> lps(m);
	getLPS(pattern, m, lps);

	while(i<n) {
		
		if(text.at(i) == pattern.at(j)) {
				j++;
				i++;
		}

		if (j == m) {
			cout<<"Found Pattern at index "<<i-j<<endl;
			j = lps[j-1];
		}

		else if( i<n && text.at(i) != pattern.at(j)) {
			if(j != 0)
				j = lps[j-1];
			else
				i = i+1;
		}
	}
}

int main(void) {

	string text, pattern;
	cin>>text;
	cin>>pattern;
	KMPmatching(text, pattern);
	return 0;
}