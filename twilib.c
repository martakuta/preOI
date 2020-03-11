// Przykładowa implementacja biblioteki do eksperymentów.

#include <stdio.h>
#include <stdlib.h>
#include "twilib.h"

static int n;
static int _pyt;
int _klucze[1000 * 1000 + 10];

int inicjuj() {
	printf("Podaj liczbę n: ");
	scanf("%d", &n);
	printf("Podaj wartosci kolejnych kluczy:\n");
	for(int i = 1; i < n; ++i) scanf("%d", _klucze + i);
	return n;
}

int pytaj(int k, int i) {
	_pyt++;
	int wyn = _klucze[k] & (1 << i) ? 1 : 0;
	printf("Pytanie o %d cyfre klucza %d\nOdpowiedz Kazimierza: %d\n", i, k, wyn);
	return wyn;
}

void odpowiedz(int wynik) {
	printf("Twoja odpowiedź to: %d\n", wynik);
	printf("Liczba zapytań: %d\n", _pyt);
	exit(0);
}


