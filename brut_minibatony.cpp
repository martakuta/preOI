#include <bits/stdc++.h>
using namespace std;

int batony[1000*1000+5];

int main () {
	int n;
	cin>> n;
	for (int i=0; i<n; i++)
		cin>> batony[i];
	int m;
	cin>> m;
	for (int i=0; i<m; i++) {
		int grupa;
		cin>> grupa;
		int wynik = 0;
		for (int i=0; i<n; i++) {
			if (batony[i]%grupa == 0)
				wynik++;
		}
		cout<< wynik << "\n";
	}
	return 0;
}
