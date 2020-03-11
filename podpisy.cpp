#include <iostream>
#include <vector>
using namespace std;
vector <int> G[500+5];
int odw[500+5];
bool dowodcy[500+5];
int vis[500+5];
void dfs (int v) {
//	cout<< "dfs" << v << " ";
	vis[v] = 1;
	for (int i=0; i<G[v].size(); i++) {
		if (vis[G[v][i]] == 0 && dowodcy[G[v][i]] == 0)
			dfs(G[v][i]);
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, ilpor, por;
	cin>> n;
	for (int i=1; i<=n; i++) {
		cin>> ilpor;
		if (ilpor == 0) {
			dowodcy[i] = 1;
		}
		for (int j=0; j<ilpor; j++) {
			cin>> por;
			G[por].push_back(i);
		}
	}
	for (int dow=1; dow<=n; dow++) {
		if (dowodcy[dow] == 1) {
//			cout<< dow << " ";
			dfs(dow);
			for (int i=1; i<=n; i++) {
//				cout<< vis[i] << " ";
				odw[i] += vis[i];
				vis[i] = 0;
			}
//			cout<< "\n";
		}
	}
	bool jest=0;
	for (int i=1; i<=n; i++) {
//		cout<< odw[i] << " ";	
		if (odw[i] == 1 && dowodcy[i] == 0) {
			cout<< i << "\n";
			jest = 1;
		}
	}
	if (jest == 0)
		cout<< "BRAK";
	return 0;
}
