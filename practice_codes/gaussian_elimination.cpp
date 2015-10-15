#include <iostream>
#include <vector>
using namespace std;

void forwardSubstitution(vector<vector<float> > &mat) {
	int maxx;
	float t;
	int n = mat.size();

	for(int i=0; i<n; i++) {
		maxx = i;
		for(int j=i+1; j<n; j++) {
			if(mat[j][i] > mat[maxx][i])
				maxx = j;
		}

		for(int j=0; j<n+1; j++) {
			t = mat[maxx][j];
			mat[maxx][j] = mat[i][j];
			mat[i][j] = t;
		}

		for(int j=n; j>=i; j--)
			for(int k=i+1; k<n; k++)
				mat[k][j] -= mat[k][i]/mat[i][i] * mat[i][j];
	}
}

void reverseElimination(vector<vector<float> > &mat) {

	int n = mat.size();

	for(int i=n-1; i>=0; --i) {
		mat[i][n] = mat[i][n] / mat[i][i];
		mat[i][i] = 1;
		for(int j=i-1; j>=0; j--) {
			mat[j][n] -= mat[j][i] * mat[i][n];
			mat[j][i] = 0;
		}
	}
}

void gauss(vector<vector<float> > &mat) {
	forwardSubstitution(mat);
	reverseElimination(mat);
}

int main(void)
{
	int n;
	cin>>n;
	vector<vector<float> > mat(n, vector<float>(n+1));

	for(int i=0; i<n; i++) {
		for(int j=0; j<=n; j++)
			cin>>mat[i][j];
	}

	gauss(mat);

	for(int i=0; i<n; i++, cout<<endl)
		for(int j=0; j<=n; j++)
			cout<<mat[i][j]<<' ';
}