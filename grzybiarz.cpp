#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair

struct grzyb {
	int pol, w;
	long long t;
};

bool compareT (grzyb a, grzyb b) {
	return a.t < b.t;
}

int n;
const long long inf = 1000*1000*1000*1000LL*1000*1000;
vector <pair <int, int> > G[6005];
long long odl[1005];
bool odw[1005];
grzyb grzyby[6005];
long long odleg[1005][1005];
long long dp[6005];

void dijkstra(int v) {
	for (int i=1; i<=n; i++) {
		odl[i] = inf;
		odw[i] = 0;
	}
	odl[v] = 0;
	priority_queue <pair <long long, int> > q;
	q.push(mp(0, v));
	while (!q.empty()) {
		long long cost = -q.top().f;
		int u = q.top().s;
		q.pop();
		if (odw[u] == 1)
			continue;
		odw[u] = 1;
		for (int i=0; i<G[u].size(); i++) {
			int x = G[u][i].s;
			if (odl[x] > cost + G[u][i].f) {
				odl[x] = cost + G[u][i].f;
				q.push(mp(-odl[x], x));
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>> n >> m;
	for (int i=0; i<m; i++) {
		int a, b, w;
		cin>> a >> b >> w;
		G[a].push_back(mp(w, b));
		G[b].push_back(mp(w, a));
	}
	for (int i=1; i<=n; i++) {
		dijkstra(i);
		for (int j=1; j<=n; j++)
			odleg[i][j] = odl[j];
	}
	int q;
	cin>> q;
	for (int i=1; i<=q; i++)
		cin>> grzyby[i].pol >> grzyby[i].t >> grzyby[i].w;
	sort (grzyby+1, grzyby + q+1, compareT);
	grzyby[0].pol = 1;
	grzyby[0].t = -1;
	grzyby[0].w = 0;
	dp[0] = 0;
	for (int i=1; i<=q; i++)
		dp[i] = -inf;
	for (int i=1; i<=q; i++) { // w dp[i] bedzie najwieksza mozliwa waga pod warunkiem ze wezme grzyb i
		for (int j=0; j<i; j++) {
			if (grzyby[j].t + 1 + odleg[grzyby[i].pol][grzyby[j].pol] <= grzyby[i].t) { //czyli biore grzyb j
				if (dp[j] + grzyby[i].w > dp[i])
					dp[i] = dp[j] + grzyby[i].w;
			}
		}
	}
	long long wynik = 0;
	for (int i=0; i<=q; i++) {
		if (dp[i] > wynik)
			wynik = dp[i];
	}
	cout<< wynik << "\n";
	return 0;
}
