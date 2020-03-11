#include <bits/stdc++.h>
using namespace std;

int modn = 100000;
int mod = 1000001;

int main () {
	int seed;
	cin>> seed;
	srand(seed);
	int n = rand()%modn+1;
	cout<< n << "\n";
	for (int i=0; i<n; i++) {
		int a, b;
		a = rand()%mod;
		b = rand()%mod;
		cout<< a << " " << b << "\n";
	}
}
