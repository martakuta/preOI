#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair

vector <pair <int, int> > G[100*1000+5];
bool zam[100*1000+5];
long long odl[100*1000+5];
bool odw[100*1000+5];
int n;

void dijkstra (int v) {
    for (int i=1; i<=n; i++) {
        odl[i] = 1000000000;
        odw[i] = 0;
    }
    odl[v] = 0;
    priority_queue <pair <int, int> > q;
    int u, w, cost;
    q.push (make_pair(0, v));
    while (!q.empty()) {
        u=q.top().second;
        cost= - q.top().first;
        q.pop();
        if (odw[u] == 1) continue;
        odw[u] = 1;
        for (int i=0; i<G[u].size(); i++) {
            w= G[u][i].second;
            if (cost + G[u][i].first < odl[w]) {
                odl[w] = cost + G[u][i].first;
                q.push(make_pair (-odl[w], w));
            }
        }
    }
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>> n;
	for (int i=0; i<n-1; i++) {
		int a, b, c;
		cin>> a >> b >> c;
		G[a].push_back(mp(c, b));
		G[b].push_back(mp(c, a));
	}
	int q;
	cin>> q;
	for (int i=0; i<q; i++) {
		int w;
		cin>> w;
		if (zam[w] == 0)
			zam[w] = 1;
		else
			zam[w] = 0;
		int wynik = 0, ilew=0;
		for (int i=1; i<=n; i++) {
			if (zam[i] == 1) {
				ilew ++;
				dijkstra(i);
				for (int j=1; j<=n; j++) {
					if (zam[j] == 1)
						wynik += odl[j];
				}
			}
		}
		for (int i=1; i<ilew; i++) {
			cout<< wynik << " ";
			wynik /= 2;         
		}    
		cout<< wynik << "\n";
	}
	return 0;

}
