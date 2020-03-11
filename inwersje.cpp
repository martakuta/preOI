#include <iostream>
using namespace std;
int T[1000*1000+5];
bool inw[1000*1000+5];
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>> n;
	for (int i=1; i<=n; i++)
		cin>> T[i];
	int x=1, ost=0, ilosc=0;
	for (int i=1; i<=n; i++) {
		inw[T[i]] = 1;
		while (inw[x] == 1)
			x++;
		if (x-1 == i) { //mamy spojna skladowa
/*			cout<< x-1-ost << " ";
			for (int j=ost+1; j<=x-1; j++)
				cout<< j << " ";
			cout<< "\n"; */
//			ost = x-1;
			inw[x-1] = 0;
			ilosc ++;
		}
	}
	cout<< ilosc << "\n";
	for (int i=1; i<=n; i++) {
		if (inw[i] == 0) {
			cout<< i-ost << " ";
			for (int j=ost+1; j<=i; j++)
				cout<< j << " ";
			cout<< "\n";
			ost = i;
		}
	}
	return 0;
}
