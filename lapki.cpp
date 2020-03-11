#include <iostream>
using namespace std;
int T[300*1000+5];
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a;
	cin>> n;
	for (int  i=1; i<=n; i++) {
		cin>> a;
		T[a] = i;
	}
	int x= n;
	while (x>0) {
		if (T[x] > T[x-1])
			x--;
		else {
			cout<< x-1;
			return 0;
		}
	}
	return 0;
}
