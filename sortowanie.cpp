#include <iostream>
using namespace std;
long long wynik=0;
int A[100*1000+5], B[100*1000+5];
void merge (int p, int q, int r) {
    int i=p, j=q+1, s=p;
    while (i<=q && j<=r) {
        if (A[i] <= A[j]) {
            B[s] = A[i];
            i++;
        }
        else {
        	B[s] = A[j];
        	wynik += q+1-i;
		j++;
        }
        s++;
    }
    /* Skonczyl sie ktorys z ciagow: A[p..q] lub A[q+1..r]. Nalezy ogon
     drugiego ciagu przepisac do tablicy B na pozycje s+1..r */
    while (i<=q) {
        B[s] = A[i];
        i++;
        s++;
    }
    while (j <= r) {
        B[s] = A[j];
        j++;
        s++;
    }
    /* Teraz pozostaje tylko przepisac wynik-posortowany ciag z tablicy B
     do tablicy A                                                      */
    for (int i=p; i<=r; i++)
        A[i] = B[i];
}
void mergesort(int p, int r) {
    if (p == r) return;
    int q = (p + r)/2;
    mergesort(p, q);
    mergesort(q + 1, r);
    merge(p, q, r);
}
int main() {
	int n, ost=0;
	long long odejmij=0;
	cin>> n;
	cin>> A[0];
	A[n] = 1000*1000*1000+5;
	for (int i=1; i<=n; i++) {
		if (i != n)
			cin>> A[i];
		if (A[i] > A[i-1]) {
			int d = i-ost;
			if (d > 2)
				odejmij += (d*(d-1))/2 -1;
			ost = i;
		}
	}
    mergesort(0, n - 1);
	wynik -= odejmij;
	cout<< wynik;
    return 0;
}
