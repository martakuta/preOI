#include <bits/stdc++.h>
using namespace std;

const int M = 1024*16;
//const int M = 8;
int D[2*M];

void dodaj(int x) {
	x = M + x-1;
	D[x] ++;
	while (x>1) {
		x /= 2;
		D[x] ++;
	}
}

int sumuj (int p, int k) {
	//cout<< "sumuj " << p << "-" << k << " ";
	p = M + p;
	k = M + k-1;
	int wynik = D[p];
	//cout<< "      " << p << "-" << k << " ";
	if (p != k)
		wynik += D[k];
	while (p/2 != k/2) {
		if (p%2 == 0)
			wynik += D[p+1];
		if (k%2 == 1)
			wynik += D[k-1];
		p /= 2;
		k /= 2;
	}
	//cout<< wynik << "\n";
	return wynik;
}

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, kontrola=0;
	cin>> n;
	for (int i=0; i<n; i++) {
		int zdarzenie;
		cin>> zdarzenie;
		if (zdarzenie == 1) {
			int cena;
			cin>> cena;
			dodaj(cena);
		} else {
			kontrola ++;
			int p=0, k=M;
			while (p+1<k) {
				int s= (p+k)/2;
				//cout<< p << " " << k << " " << s << "   ";
				if (sumuj(0,s) >= kontrola)
					k = s;
				else
					p = s;
			}
			cout<< k << "\n";
		}
	}
	return 0;
}
