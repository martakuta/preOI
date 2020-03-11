#include <iostream>
#include <algorithm>
using namespace std;
int k1[1000*1000+5], k2[1000*1000+5], k3[1000*1000+5];
int p[1000*1000+5][3];
int n;
int prefiks(int *tab1, int *tab2, int *tab3) {
	p[0][0] = tab1[0];
	for (int i=1; i<n; i++)
		p[i][0] = p[i-1][0] + tab1[i];
	p[1][1] = p[0][0] + tab2[1];
	for (int i=2; i<n; i++) {
		int mini = min (p[i-1][0], p[i-1][1]);
		p[i][1] = mini + tab2[i];
	}
	p[2][2] = p[1][1] + tab3[2];
	for (int i=3; i<n; i++) {
		int mini = min (p[i-1][1], p[i-1][2]);
		p[i][2] = mini + tab3[i];
	}
/*	for (int i=0; i<n; i++)
		cout<< p[i][0] << " ";
	cout<< "\n";
	for (int i=0; i<n ;i++)
		cout<< p[i][1] << " ";
	cout<< "\n";
	for (int i=0; i<n; i++)
		cout<< p[i][2] << " ";
	cout<< "\n" << p[n-1][2] << "\n"; */
	return p[n-1][2];
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>> n;
	for (int i=0; i<n; i++)
		cin>> k1[i];
	for (int i=0; i<n; i++)
		cin>> k2[i];
	for (int i=0; i<n; i++)
		cin>> k3[i];
	int najm = 1000*1000*1000;
	int pre = prefiks(k1, k2, k3);
	if (pre < najm)
		najm = pre;
	pre = prefiks (k1, k3, k2);
	if (pre < najm)
		najm = pre;
	pre = prefiks (k2, k1, k3);
	if (pre < najm)
		najm = pre;
	pre = prefiks (k2, k3, k1);
	if (pre < najm)
		najm = pre;
	pre = prefiks (k3, k1, k2);
	if (pre < najm)
		najm = pre;
	pre = prefiks (k3, k2, k1);
	if (pre < najm)
		najm = pre;
	cout<< najm;
	return 0;
}
