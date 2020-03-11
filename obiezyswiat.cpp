#include <bits/stdc++.h>
using namespace std;

int n;
const int inf = 2*1000*1000*1000;
int odl[1000*1000+5];
vector <int> G[1000*1000+5];

void bfs (int v) {
	for (int i=1; i<=n; i++)
		odl[i] = inf;
	odl[v] = 0;
	queue <int> q;
	q.push(v);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i=0; i<G[u].size(); i++) {
			int x = G[u][i];
			if (odl[u] + 1 < odl[x]) {
				odl[x] = odl[u] + 1;
				q.push(x);
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>> n >> m;
	for (int i=1; i<n; i++) {
		int a, b;
		cin>> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bfs(1);
	int najdl = 0, p=1, k=1; // p i k to konce srednicy drzewa
	for (int i=1; i<=n; i++) {
		if (odl[i] > najdl) {
			najdl = odl[i];
			p = i;
		}
	}
	bfs(p);
	najdl = 0;
	for (int i=1; i<=n; i++) {
		if (odl[i] > najdl) {
			najdl = odl[i];
			k = i;
		}
	}
	int dlsr = najdl;
	if (dlsr >= m) {
		cout<< m+1;
		return 0;
	}
	int paliwo = m - dlsr;
	int nieodw = n - (dlsr+1);
	while (paliwo > 1 && nieodw > 0) {
		nieodw--;
		paliwo -= 2;
	}
	int wynik = n - nieodw;
	cout<< wynik;
	return 0;
}
