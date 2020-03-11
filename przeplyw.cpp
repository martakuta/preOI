#include <bits/stdc++.h>
using namespace std;

vector <int> G[205];
int kolory[205];
int usun1, usun2, sprzecznosc=0;

void dfs (int v) {
//    	cout<< "dfs" << v <<" "<< kolory[v] << " : ";
    	if (sprzecznosc == 1)
        	return;
    	for (int i=0; i<G[v].size(); i++) {
//        	cout<< " G[v][i]=" << G[v][i] << ": " << kolory[G[v][i]] << "-->";
        	if (G[v][i] == usun1 || G[v][i] == usun2)
            		continue;
	        if (kolory[G[v][i]] == 0)
        	    	kolory[G[v][i]] = 3 - kolory[v];
	        else if (kolory[G[v][i]] == kolory[v]) {
        	    	sprzecznosc = 1;
//			cout<< "\nsprzecznosc\n";
		}
//        	cout<< kolory[G[v][i]] << "    ";
    	}
//	cout<< "\n";
}

int main () {
	ios::sync_with_stdio(0); cin.tie(0);
  	int n, m;
    	cin>> n >> m;
    	for (int i=0; i<m; i++) {
        	int a, b;
        	cin>> a >> b;
	        G[a].push_back(b);
	        G[b].push_back(a);
	}
	if (n == 1) {
		cout<< "TAK\n";
		return 0;
	}
	for (int i=1; i<=n; i++) {
        	usun1 = i;
		for (int k=i+1; k<=n; k++) {
			usun2 = k;
//        		cout<< "usun" << usun << ": ";
        		for (int j=1; j<=n; j++)
            			kolory[j] = 0;
        		for (int j=1; j<=n; j++) {
            			if (j == usun1 || j == usun2)
                			continue;
            			if (kolory[j] == 0)
                			kolory[j] = 1;
				dfs(j);
/*                		cout<< "kolory: ";
	                	for (int i=1; i<=n; i++)
        	            		cout<< kolory[i] << " ";
                		cout<< "\n";*/
/*      			cout<< "kolory: ";
			        for (int i=1; i<=n; i++)
			        cout<< kolory[i] << " ";
	        		cout<< "\n";
		        	cout<< "sprzecznosc: " << sprzecznosc << "\n";*/
			}
			if (sprzecznosc == 0) {
		            	cout<< "TAK\n";	
			        return 0;
		        }
        		sprzecznosc = 0;
		}
    	}
    	cout<< "NIE\n";
    	return 0;
}
