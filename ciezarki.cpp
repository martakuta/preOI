#include <bits/stdc++.h>
using namespace std;

long long dane[100*1000+5][3];
vector <int> G[100*1000+5];
bool odw[100*1000+5];
long long masa[100*1000+5];
int zerwana;
const long long inf = 1000*1000*1000*1000LL*1000*1000;

long long dfs (int v) {
	if (zerwana == 1) // jesli wczesniejszy dfs pokazal ze nitka sie zerwala to nic dalej mnie nie interesuje - chce zakonczyc cala rekurencje jak najszybciej
		return 0;
	odw[v] = 1;
	for (int i=0; i<G[v].size(); i++) {
		if (odw[G[v][i]] == 0) {
			masa[v] += dfs(G[v][i]); // wartosci mas z synow dodaje do ojca, bo jego nitka musi tez wytrzymywac obciazenie synow
		}
	}
	masa[v] += dane[v][1]; // do masy lacznej poddrzewa ojca dodaje mase samego ojca
	if (masa[v] > dane[v][0]) { // czyli nitka nie wytrzymuje obciazenia
		zerwana = 1;
		return 0;
	}
	return masa[v]; // oddaje swojemu ojcu mase swoja i swojego poddrzewa
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>> n;
	for (int i=1; i<=n; i++)
		cin>> dane[i][0] >> dane[i][1] >> dane[i][2];
	dane[0][0] = inf; // hak ma nieskonczona wytrzymalosc
	//binsearch po wyniku
	int p=0, k=n+1;
	while (p+1<k) {
		for (int i=0; i<=n; i++)
			G[i].clear();
		int s = (p+k)/2;
		for (int i=1; i<=s; i++) { // tworze od nowa graf z zakresu wskazanego przez binsearch
			G[i].push_back(dane[i][2]);
			G[dane[i][2]].push_back(i);
		}
		// i czyszcze wszystkie struktury ktorych bede uzywac podczas sprawdzania czy jakas nitka jest zerwana
		zerwana = 0;
		for (int i=0; i<=n; i++) {
			odw[i] = 0;
			masa[i] = 0;
		}
		dfs(0);
		if (zerwana == 1)
			k = s;
		else
			p = s;
	}
	if (k > n) // czyli ani razu nie znalazl zerwanej nitki
		cout<< "NIE\n";
	else
		cout<< k << "\n";
	return 0;
}
