#include <iostream>
using namespace std;
int T[1000001], minima[500000];
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int n, maxilosc=0;
    cin>> n;
    for (int i=0; i<n; i++){
        cin>> T[i];
    }
    int p=1;
    minima[0]=0;
    for ( int i=0; i<n; i++) {
        if (T[i]<T[i-1] && T[i]<T[i+1]) {
            minima[p]=i;
            p++;
        }
    }
    minima[p]=n-1;
    for (int i=0; i<p; i++) {
        int ilosc=minima[i+1]-minima[i]+1;
        if (ilosc>maxilosc) maxilosc=ilosc;
    }
    cout<< maxilosc;
    return 0;
}
