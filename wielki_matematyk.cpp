#include <bits/stdc++.h>
using namespace std;

bool jest[1000*1000+5];
int ciag[1000*1000+5];
bool dp[1000*1000+5];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int nr;
	//funkcja scanf zwraca true jesli dostaje wartosc i false jesli dostaje EOF (end of file)
	//wiec jesli wczytamy z pliku dane do tego programu to nie musimy miec na poczatku podanej dlugosci ciagu
	for (nr=0; scanf("%d", &ciag[nr]) == 1; nr++); 
	dp[nr] = 1;
	jest[nr] = 1;
	for (int i=1; i<=nr; i++) {
		int x = i;
		while (dp[x] == 0 && x+ciag[x]+1 <=nr) {
			dp[x] = 1;
			x = x + ciag[x] +1;
		}
		if (jest[x] == 1) {
			x = i;
			while (jest[x] != 1) {
				jest[x] = 1;
				x = x + ciag[x] +1;
			}
		}
	}
	for (int i=1; i<=nr; i++) {
		if (jest[i] == 1)
			cout<< i << " ";
	}
	return 0;
}
