#include <bits/stdc++.h>
using namespace std;

int findLIS(const vector<int> &arr, vector<int> &lis) {
	int n = arr.size();

	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			if(arr[i] >= arr[j] && lis[i] < lis[j]+1)
				lis[i] = lis[j] + 1;
		}
	}

	int maxx = 0;
	for(int i=0; i<n; i++)
		maxx = (maxx < lis[i]) ? lis[i] : maxx;

	return maxx;
}

vector<int> getLIS(const vector<int> &arr, const vector<int> &lis, int maxx) {
	int n = arr.size();
	vector<int> ret;

	for(int i=n-1; i>=0; i--) {
		if(lis[i] == maxx) {
			ret.push_back(arr[i]);
			maxx--;
		}
	}

	reverse(ret.begin(), ret.end());
	return ret;
}

int main(void) {

	int n;
	cin>>n;
	vector<int> arr(n);
	vector<int> memo(n,1);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	int num = findLIS(arr, memo);
	cout<<num<<endl;
	vector<int> newArr = getLIS(arr, memo, num);
	for(auto itr = newArr.begin(); itr != newArr.end(); ++itr)
		cout<<*itr<<' ';
	cout<<endl;
	return 0;

}