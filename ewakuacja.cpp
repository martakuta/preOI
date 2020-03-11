#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> G[1000+5];
int odl[1000+5];
pair <int, int> drogi[100*1000+5];
int n;
const int inf = 1000*1000*1000;
void bfs () {
	for (int i=1; i<=n; i++)
		odl[i] = inf;
	odl[1] = 0;
	queue <int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i=0; i<G[u].size(); i++) {
			int x = G[u][i];
			if (odl[x] > odl[u]+1) {
				odl[x] = odl[u] +1;
				q.push(x);
			}
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, q, a, b, p;
	string zap;
	cin>> n >> m >> q;
	for (int i=0; i<m; i++) {
		cin>> a >> b;
		G[a].push_back(b);
	}
	bfs();
	for (int i=0; i<q; i++) {
		cin>> zap;
		if (zap == "U") {
			cin>> p;
			int szb = drogi[p].first;
			int sza = drogi[p].second;
			int d = G[szb].size();
			for (int j=0; j<d; j++) {
				if (G[szb][j] == sza) {
					G[szb][j] = G[szb][d-1];
					//G.pop_back();
					//break;
				}
			}
			bfs();
		} else {
			cin>> p;
			if (odl[p] == inf)
				cout<< "-1\n";
			else
				cout<< odl[p] << "\n";
		}
	} 
	return 0;
}
