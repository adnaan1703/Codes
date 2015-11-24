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
#define INF INT_MAX
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
 
int destination;
vvint railInput;
vvint roadInput;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
 
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
	return 0;
}

void floydWarshall(vvint &graph) {
	int n = graph.size();

	for(int k = 0; k<n; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(graph[i][k] != INF and graph[k][j] != INF)
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

void solve(void) {
	int n, m;
	cin>>n>>m;
	vvint railway(n, vint(n,INF));
	vvint road(n, vint(n, INF));

	for(int i=0; i<m; i++) {
		int u, v;
		cin>>u>>v;
		u--;
		v--;
		railway[u][v] = 1;
		railway[v][u] = 1;
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(i == j)
				railway[i][j] = road[i][j] = 0;
			else if(railway[i][j] == INF)
				road[i][j] = 1;
		}
	}

	railInput = railway;
	roadInput = road;

	floydWarshall(railway);
	floydWarshall(road);

	int timestamp;
	destination = n-1;
	
	if(railway[0][destination] == INF || road[0][destination] == INF)
		timestamp = -1;
	else
		timestamp = max(road[0][destination], railway[0][destination]);
	cout<<timestamp<<endl;
}