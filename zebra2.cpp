#include <bits/stdc++.h>
using namespace std;

vector <int> G[1000*1000+5];
bool wierzcholki[1000*1000+5];
bool przedzialy[1000*1000+5];
bool odw[1000*1000+5];

void dfs (int v) {
//	cout<< "d" << v << " ";
	odw[v] = 1;
	for (int i=0; i<G[v].size(); i++) {
		if (odw[G[v][i]] == 0)
			dfs(G[v][i]);
	}
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, maxw=0, wynik=1;
	cin>> n;
	for (int i=0; i<n; i++) {
		int a, b;
		cin>> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
		wierzcholki[a] = 1;
		wierzcholki[b] = 1;
		if (a > maxw)
			maxw = a;
		if (b > maxw)
			maxw = b;
	}
	for (int i=0; i<=maxw; i++) {
		if (wierzcholki[i] == 1 && przedzialy[i] == 0) {
//			cout << "dfs" << i << ": ";
			dfs(i);
			int suma=0;
//			cout<< odw[5] << "\n";
//			for (int j=0; j<=maxw; j++)
//				cout<< odw[j] << " ";
//			cout<< "\n";
			for (int j=0; j<=maxw; j++) {
				if (odw[j] == 1) {
					suma++;
					przedzialy[j] = 1;
					odw[j] = 0;
				}
			}
			if (suma%2 == 0)
				wynik += suma;
			else
				wynik += (suma - 1);
//			for (int j=0; j<=maxw; j++)
//				cout<< przedzialy[j] << " ";
//			cout<< "\n";
//			cout<< suma << " " << wynik << " ";
		}
	}
	cout<< wynik << "\n";
	return 0;
}
