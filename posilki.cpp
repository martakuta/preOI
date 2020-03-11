#include <bits/stdc++.h>
using namespace std;

int mod;
const int M = 1000*1000;
long long d[2*M];
int prz[1000*1000+5];

void dodaj (int a, int w) {
	a = M + a-1;
	d[a] = w;
	while (a > 1) {
		a /= 2;
		d[a] = d[2*a] * d[2*a+1];
		d[a] %= mod;
	}
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin>> n >> mod >> q;
	for (int i=1; i<=n; i++) {
		cin>> prz[i];
		d[M+i-1] = prz[i];
	}
	for (int i=M+n; i<2*M; i++)
		d[i] = 1;
	for (int i=M-1; i>0; i--) {
		d[i] = d[2*i] * d[2*i+1];
		d[i] %= mod;
	}
	for (int l=0; l<q; l++) {
		bool zap;
		cin>> zap;
		if (zap == 1) {
			int k;
			cin>> k;
			queue <int> q;
			for (int i=0; i<k; i++) {
				int a;
				cin>> a;
				q.push(a);
				dodaj(a, 1);
			}
			cout<< d[1] << "\n";
			while (!q.empty()) {
				int x= q.front();
				q.pop();
				dodaj(x, prz[x]);
			}
		} else {
			int p, w;
			cin>> p >> w;
			prz[p] = w;
			dodaj (p, w);
		}
	}
	//czy pamietasz o long long'ach?
	return 0;
}
