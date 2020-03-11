#include <bits/stdc++.h>
using namespace std;

int kubelek[1000*1000+5];
bool wierzcholki[1000*1000+5];
int rep[1000*1000+5];
int T[1000*1000+5][2];

int fin (int v) {
	if (rep[v] == v)
		return v;
	else
		return rep[v] = fin(rep[v]);
}

void onion (int a, int b) {
	rep[fin(a)] = fin(b);
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, maxw=0, wynik=1;
	cin>> n;
	for (int i=0; i<n; i++) {
		int a, b;
		cin>> a >> b;
		T[i][0] = a;
		T[i][1] = b;
		wierzcholki[a] = 1;
		wierzcholki[b] = 1;
		if (a > maxw)
			maxw = a;
		if (b > maxw)
			maxw = b;
	}
	for (int i=0; i<=maxw; i++) {
		if (wierzcholki[i] == 1) 
			rep[i] = i;
		else
			rep[i] = -1;
	}
	for (int i=0; i<n; i++) {
		int a = T[i][0];
		int b = T[i][1];
		onion(a, b);
/*		for (int j=0; j<=maxw; j++)
			cout<< rep[j] << " ";
		cout<< "\n";*/
	}
	for (int i=0; i<=maxw; i++) { 
		if (rep[i] != -1)
			rep[i] = fin(i);
	}
/*	for (int i=0; i<=maxw; i++)
		cout<< rep[i] << " ";
	cout<< "\n";*/
	for (int i=0; i<=maxw; i++)
		kubelek[rep[i]] ++;
/*	for (int i=0; i<=maxw; i++)
		cout<< kubelek[i] << " ";
	cout<< "\n";*/
	for (int i=0; i<=maxw; i++) {
		if (kubelek[i]%2 == 0)
			wynik += kubelek[i];
		else if (kubelek[i] != 1)
			wynik += (kubelek[i] -1);
	}
	cout<< wynik << "\n";
	return 0;
}
