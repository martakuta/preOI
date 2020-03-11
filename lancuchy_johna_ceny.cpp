#include <iostream>
#include <algorithm>
using namespace std;
int T[500*1000+5];
int x=0, wynik=0;
void lacz (int z) {
	int lancuch = T[x];
	if (lancuch >= z)
		wynik += z;
	else if (lancuch == z-1)
		wynik += z-1;
	else {
		x++;
		wynik += lancuch;
		lacz(z-1-lancuch);
	}
}
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>> n;
	for (int i=0; i<n; i++)
		cin>> T[i];
	sort (T, T+n);
	int z= n-1;
	lacz(z);
	cout<< wynik;
	return 0;
}
