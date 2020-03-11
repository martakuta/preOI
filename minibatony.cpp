#include <bits/stdc++.h>
using namespace std;

const int mil = 1000*1000;
int batony[mil+5];
int grupy[mil+5];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>> n;
	for (int i=0; i<n; i++) {
		int paczka;
		cin>> paczka;
		batony[paczka] ++;
	}
	for (int i=1; i<=mil; i++)
		grupy[i] = -1;
	int m;
	cin>> m;
	for (int i=0; i<m; i++) {
		int gr;
		cin>> gr;
		if (grupy[gr] != -1) 
			cout<< grupy[gr] << "\n";
		else {
			int wynik = 0;
			for (int i=gr; i<=mil; i+= gr) {
				wynik += batony[i];
			}
			grupy[gr] = wynik;
			cout<< wynik << "\n";
		}
	}
	return 0;
}
