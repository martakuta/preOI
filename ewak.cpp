#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector <int> G[1005];
int odl[1005];
pair <pair <int, int>, bool> drogi[100*1000+5];
pair <char, int> pyt[200*1000+5];
const int inf = 1000*1000*1000;

void bfs (int v) {
	queue <int> q;
	q.push(v);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i=0; i<G[u].size(); i++) {
			int x= G[u][i];
			if (odl[u]+1 < odl[x]) {
				odl[x] = odl[u] +1;
				q.push(x);
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q, a, b;
	cin>> n >> m >> q;
	for (int i=1; i<=m; i++) {
		cin>> a >> b;
		drogi[i].f.f = a;
		drogi[i].f.s = b;
	}
	for (int i=1; i<=q; i++) {
		cin>> pyt[i].f >> pyt[i].s;
		if (pyt[i].f == 'U')
			drogi[pyt[i].s].s = 1;
	}
	for (int i=1; i<=m; i++) {
		if (drogi[i].s == 0)
			G[drogi[i].f.f].push_back(drogi[i].f.s);
	}
	for (int i=1; i<=n; i++)
		odl[i] = inf;
	odl[1] = 0;
	bfs(1);
	for (int i=q; i>0; i--) {
		if (pyt[i].f == 'E') {
			if (odl[pyt[i].s] == inf)
				pyt[i].s = -1;
			else
				pyt[i].s = odl[pyt[i].s];
		} else {
			int da = drogi[pyt[i].s].f.f;
			int db = drogi[pyt[i].s].f.s;
			G[da].push_back(db);
			if (odl[da] +1 < odl[db])
				odl[db] = odl[da] +1;
			bfs(db);
		}
	}
	for (int i=1; i<=q; i++) {
		if (pyt[i].f == 'E')
			cout<< pyt[i].s << "\n";
	}
	return 0;
}
