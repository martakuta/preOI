#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair

vector <pair <int, int> > G[2005][2005];
bool mapa[2005][2005];
pair <int, int> odl[2005][2005];
int n;
const int inf = 1000*1000*1000;	

void bfs (int a, int b) {
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++)
			odl[i][j].f = inf;
	}
	//odl[][].s: =0-->jeszcze nie odwiedzony =1-->ostatni skret najlepszej trasy byl poziomy =2-->ostatni skret najlepszej trasy byl pionowy 
	//=3-->najlepsze trasy z ostatnim skretem poziomym i pionowym sa jednakowej dlugosci
	odl[a][b].f = 0;
	odl[a][b].s = 3;
	list <pair <int, int> > q;
	q.push_back(mp(a, b));
	while (!q.empty()) {
		int ua = q.front().f;
		int ub = q.front().s;
		q.pop_front();
		for (int j=0; j<G[ua][ub].size(); j++) {
			int xa = G[ua][ub][j].f;
			int xb = G[ua][ub][j].s;
			if (odl[ua][ub].s == 1) { //czyli ostatni skret najlepszej trasy byl poziomy
				if (ua == xa) { //czyli dalej da sie isc poziomo do tego sasiada
					if (odl[xa][xb].f > odl[ua][ub].f) { //jesli znaleziona trasa jest najkrotsza dotychczas
						odl[xa][xb].f = odl[ua][ub].f; //ilosc skretow zostaje ta sama
						odl[xa][xb].s = 1; //ostatni ruch do niego bedzie poziomy
						q.push_front(mp(xa, xb));
					} else if (odl[xa][xb].f == odl[ua][ub].f && odl[xa][xb].s == 2) { //trasa rownej dlugosci byla juz znaleziona 
													//ale jesli szlo sie ostatni fragment pionowo
						odl[xa][xb].s = 3; //czyli trasami rownej dlugosci da sie przyjsc i z poziomu i z pionu
						q.push_front(mp(xa, xb));
					}
				} else { //czyli do tego sasiada trzeba isc pionowo wykonujac skret
					if (odl[xa][xb].f > odl[ua][ub].f + 1) { //czyli znaleziona trasa jest najkrotsza dotychczas
						odl[xa][xb].f = odl[ua][ub].f +1; //zwieksza sie o 1 ilosc skretow
						odl[xa][xb].s = 2; //ostatni ruch do niego bedzie pionowy
						q.push_back(mp(xa, xb));
					} else if (odl[xa][xb].f == odl[ua][ub].f + 1 && odl[xa][xb].s == 1) { //trasa rownej dlugosci byla juz znaleziona
													//ale jesli szlo sie ostatni fragment poziomo
						odl[xa][xb].s = 3; //czyli trasami rownej dlugosci da sie przyjsc i z poziomu i z pionu
						q.push_back(mp(xa, xb));
					}
				}
			} else if (odl[ua][ub].s == 2) { //czyli ostatni skret najlepszej trasy byl pionowy
				if (ub == xb) { //czyli dalej da sie isc pionowo do tego sasiada
					if (odl[xa][xb].f > odl[ua][ub].f) { //jesli znaleziona trasa jest najkrotsza dotychczas
						odl[xa][xb].f = odl[ua][ub].f; //ilosc skretow zostaje ta sama
						odl[xa][xb].s = 2; //ostatni ruch do niego bedzie pionowy
						q.push_front(mp(xa, xb));
					} else if (odl[xa][xb].f == odl[ua][ub].f && odl[xa][xb].s == 1) { //trasa rownej dlugosci byla juz znaleziona
													//ale jesli szlo sie ostatni fragment poziomo
						odl[xa][xb].s = 3; //czyli trasami rownej dlugosci da sie przyjsc i z poziomu i z pionu
						q.push_front(mp(xa, xb));
					}
				} else { //czyli do tego sasiada trzeba isc poziomo wykonujac skret
					if (odl[xa][xb].f > odl[ua][ub].f +1) { //czyli znalezniona trasa jest najkrotsza z mozliwych
						odl[xa][xb].f = odl[ua][ub].f +1; //zwieksza sie o 1 ilosc skretow
						odl[xa][xb].s = 1; //ostatni ruch do niego bedzie poziomy
						q.push_back(mp(xa, xb));
					} else if (odl[xa][xb].f == odl[ua][ub].f +1 && odl[xa][xb].s == 2) { //trasa rownej dlugosci byla juz znaleziona
													//ale jesli szlo sie ostatni fragment pionowo
						odl[xa][xb].s = 3; //czyli trasami rownej dlugosci da sie przyjsc i z poziomu i z pionu
						q.push_back(mp(xa, xb));
					}
				}
			} else if (odl[ua][ub].s == 3) { //czyli do biezacego wierzcholka da sie przyjsc trasami najkrotszej dlugosci zarowno z poziomu jak i z pionu
				if (ua == xa) { //jesli idzie sie do tego sasiada poziomo to wybieramy trase pozioma
					if (odl[xa][xb].f > odl[ua][ub].f) { //jesli znaleziona trasa jest najkrotsza dotychczas
						odl[xa][xb].f = odl[ua][ub].f; //ilosc skretow zostaje ta sama
						odl[xa][xb].s = 1; //ostatni ruch dla niego bedzie poziomy
						q.push_front(mp(xa, xb));
					} else if (odl[xa][xb].f == odl[ua][ub].f && odl[xa][xb].s == 2) { //trasa rownej dlugosci byla juz znaleziona
													//ale jesli szlo sie ostatni fragment pionowo
						odl[xa][xb].s = 3; //czyli trasami rownej dlugosci da sie przyjsc i z poziomu i z pionu
						q.push_front(mp(xa, xb));
					}
				} else if (ub == xb) { //jesli idzie sie do tego sasiada pionowo to wybieramy trase pionowa
					if (odl[xa][xb].f > odl[ua][ub].f) { //jesli znaleziona trasa jest najkrotsza dotychczas
						odl[xa][xb].f = odl[ua][ub].f; //ilosc skretow zostaje ta sama
						odl[xa][xb].s = 2; //ostatni ruch dla niego bedzie pionowy
						q.push_front(mp(xa, xb));
					} else if (odl[xa][xb].f == odl[ua][ub].f && odl[xa][xb].s == 1) { //trasa rownej dlugosci byla juz znaleziona
													//ale jesli szlo sie ostatni fragment poziomo
						odl[xa][xb].s = 3; //czyli trasami rownej dlugosci sa sie przyjsc i z posiomu i z pionu
						q.push_front(mp(xa, xb));
					}
				}
			}
		}
	}
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	char znak;
	pair <int, int> w;
	pair <int, int> m;
	cin>> n;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin>> znak;
			if (znak == '.')
				mapa[i][j] = 1;
			else if (znak == 'W') {
				mapa[i][j] = 1;
				w = mp(i, j);
			} else if (znak == 'M') {
				mapa[i][j] = 1;
				m = mp(i, j);
			}
			// 0 jest w miejscu X oraz jako straznicy na bokach
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (mapa[i][j-1] == 1) //pole po lewo
				G[i][j].push_back(mp(i, j-1));
			if (mapa[i][j+1] == 1) //pole na prawo
				G[i][j].push_back(mp(i, j+1));
			if (mapa[i-1][j] == 1) //pole u gory
				G[i][j].push_back(mp(i-1, j));
			if (mapa[i+1][j] == 1) //pole u dolu
				G[i][j].push_back(mp(i+1, j));
		}
	}
	bfs(w.f, w.s);
/*	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++)
			cout<< odl[i][j].f << ","<< odl[i][j].s << "    ";
		cout<< "\n";
	}*/
	int wynik = odl[m.f][m.s].f;
	if (wynik == inf)
		cout<< "-1\n";
	else
		cout<< wynik+1 << "\n";
	return 0;
}
