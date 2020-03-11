#include <bits/stdc++.h>
using namespace std;

const int mod = 2000;

int main () {
	int seed;
	cin>> seed;
	srand(seed);
	int n = rand()%(mod+1);
	cout<< n << "\n";
	for (int i=0; i<n; i++) {
		int opak = rand()%mod+1;
		cout<< opak << " ";
	}
	cout<< "\n";
	int m = rand()%(mod+1);
	cout<< m << "\n";
	for (int i=0; i<m; i++) {
		int grupa = rand()%mod+1;
		cout<< grupa << "\n";
	}
	
}
