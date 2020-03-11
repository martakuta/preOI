#include <bits/stdc++.h>
#include "twilib.h"
using namespace std;

int n, p, k;
bool szukana[25];
int potegi[25];
bool klucze[1000*1000+5];

int bin (int kon) {
	int wynik = 0, potega=1;
	for (int i=0; i<kon; i++) {
		wynik += potega *szukana[i];
		potega *= 2;
	}
	return wynik;
}

void szuk (int x) {
	int popril0, mojail0=0;
	queue <int> q0;
	queue <int> q1;
	/*int rozp = k-p;
	if (p == 1)
		rozp ++;
	for (int i=0; i<22; i++) {
		if (potegi[i+1] > rozp) { //  k-p+1 to ilosc rozpatrywanych elementow
			popril0 = potegi[i]; // i powinno byc tyle 0 ile wynosi najwyzsza potega 2 
			break;	//mieszczaca sie w tej ilosci rozpatrywanej
		}
	}
	if (p == 1)
		popril0 --;*/
	popril0 = potegi[x];
	if (p == 1)
		popril0 --;
	popril0 = min(popril0, k-p+1);
	for (int i=1; i<n; i++) {
		if (klucze[i] == 1)
			continue;
		if (pytaj(i, x) == 0) {
			mojail0 ++; // zliczam ile w moim zbiorze kluczy na x-tym miejscu jest 0
			q0.push(i);
		} else
			q1.push(i);
	}
//	cout << "p=" << p << " k=" << k << " popril0=" << popril0 << " mojail0=" << mojail0 << "\n";
	if (mojail0 < popril0) { // jesli jest mniej 0 niz byc powinno to znaczy 
				//ze w szukanym kluczu na miejscu x-tym znajduje sie 0
		szukana[x] = 0;
//		cout<< "brakuje 0\n";
		k = p + popril0 -1;
		while (!q1.empty()) {
			klucze[q1.front()] = 1;
			q1.pop();
		}
	} else {
		szukana[x] = 1;
//		cout<< "brakuje 1\n";
		p = p + popril0;
		while (!q0.empty()) {
			klucze[q0.front()] = 1;
			q0.pop();
		}
	}
}

int main () {
	n = inicjuj();
	
	potegi[0] = 1;
	for (int i=1; i<=22; i++)
		potegi[i] = 2*potegi[i-1];
	p=1; k=n;
	int maxcyfr;
	for (int i=0; i<=22; i++) {
		if (potegi[i+1] > n) {
			maxcyfr = i+1;
			break;
		}
	}
	for (int i=maxcyfr-1; i>=0; i--)
		szuk(i);
/*	for (int i=maxcyfr-1; i>=0; i--)
		cout<< szukana[i] << " ";
	cout<< "\n";*/
	int wynik = bin(maxcyfr);
	odpowiedz(wynik);
}
