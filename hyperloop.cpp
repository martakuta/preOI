#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> G[1000*1000+5];
int odl[1000*1000+5];
int n, m;
const int inf = 1000*1000*1000+5;
void bfs () {
	for (int i=0; i<=n+m; i++)
		odl[i] = inf;
	odl[1]= 0;
	queue <int> q;
	q.push(1);
	while (!q.empty()) {
		int w= q.front();
		q.pop();
		for (int i=0; i<G[w].size(); i++) {
			int u= G[w][i];
			if (odl[w]+1 < odl[u]) {
				odl[u] = odl[w] +1;
				q.push(u);
			}
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int k, p;
	cin>> n >> k >> m;
	for (int i=1; i<=m; i++) {
		for (int j=0; j<k; j++) {
			cin>> p;
			G[n+i].push_back(p);
			G[p].push_back(n+i);
		}
	}
	bfs();
	if (odl[n] == inf)
		cout<< "-1";
	else
		cout<< (odl[n])/2+1;
	return 0;
}
