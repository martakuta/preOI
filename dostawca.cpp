#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair

vector <pair <int, int> > G[1005];
int odl[1005];
bool odw[1005];

const int inf = 1000*1000*1000;
int v;

void dijkstra (int a) {
	for (int i=1; i<=v; i++) {
		odl[i] = inf;
		odw[i] = 0;
	}
	odl[a] = 0;
	priority_queue <pair <int, int> > q;
	q.push(mp(0, a));
	while (!q.empty()) {
		int cost = -q.top().f;
		int u = q.top().s;
		q.pop();
		if (odw[u] == 1)
			continue;
		odw[u] = 1;
		for (int i=0; i<G[u].size(); i++) {
			int x = G[u][i].s;
			if (G[u][i].f + cost < odl[x]) { 
				odl[x] = G[u][i].f + cost;
				q.push(mp(-odl[x], x));
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int e, t;
	cin>> v >> e;
	for (int i=0; i<e; i++) {
		int a, b, c;
		cin>> a >> b >> c;
		G[a].push_back(mp(c, b));
		G[b].push_back(mp(c, a));
	}
	cin >> t;
	for (int i=0; i<t; i++) {
		int g, h;
		cin>> g >> h;
		dijkstra(g);
		if (odl[h] == inf)
			cout<< "INF\n";
		else
			cout<< odl[h] << "\n";
	}
	return 0;
}
