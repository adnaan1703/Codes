#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX


class myComp {
public:
	bool operator () (pair<int, int> lhs, pair<int, int> rhs) {
		if(lhs.second > rhs.second)
			return true;
		else
			return false;
	}
};

void dijsktra(vector<vector<pair<int, int> > > &graph, vector<int> &dist, int start = 0) {
	
	vector<bool> marked((int) dist.size(), false);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, myComp> pq;
	// pq.push(make_pair(start, dist[start]));
	pq.push({start, dist[start]});

	while(!pq.empty()) {		// could also run the loop till n is marked
		
		int node = pq.top().first;
		pq.pop();

		if(marked[node])
			continue;

		marked[node] = true;
		for(auto itr : graph[node]) {
			if(dist[itr.first] > dist[node] + itr.second) {
				
				dist[itr.first] = dist[node] + itr.second;
				pq.push({itr.first, dist[itr.first]});
			}
		}
	}
}

void printdist(vector<int> &dist) {

	for(int i=0; i<(int) dist.size(); i++)
		cout<<i<<" : "<<dist[i]<<endl;
}


int main(void) {

	freopen("in.txt", "r", stdin);
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int, int> > > graph(n, vector<pair<int, int> >(0));
	vector<int> dist(n, INF);

	while(m--) {
		int u, v, w;
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}

	dijsktra(graph, dist);
	printdist(dist);

	return 0;
}