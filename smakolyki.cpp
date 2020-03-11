#include <iostream>
using namespace std;
int konk[100*1000+5], niek[100*1000+5];
long long p[100*1000+5][2];
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>> n;
	for (int i=0; i<n; i++)
		cin>> konk[i];
	for (int i=0; i<n-1; i++)
		cin>> niek[i];
	p[0][0] = konk[0];
	p[0][1] = niek[0];
	for (int i=1; i<n; i++) {
		p[i][0] = (p[i-1][0] + p[i-1][1]) * konk[i] + p[i-1][0] * niek[i-1] + p[i-1][1] * (niek[i-1] -1);
		p[i][1] = (p[i-1][0] + p[i-1][1]) * niek[i];
		p[i][0] %= 1000*1000*1000+7;
		p[i][1] %= 1000*1000*1000+7;
	}
/*	for (int i=0; i<n; i++)
		cout<< p[i][0] << " ";
	cout<< "\n";
	for (int i=0; i<n; i++)
		cout<< p[i][1] << " ";
	cout<< "\n"; */
	cout<< p[n-1][0];
	return 0;
}
