#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e7;

int g[100][100];

int main(){
	int n, m;
	cin >> n >> m;

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> g[i][j];

	for(int k=0; k<n; k++){
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(g[i][j] > g[i][k] + g[k][j])
					g[i][j] = g[i][k] + g[k][j];
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout << g[i][j] << ' ';
		cout << '\n';
	}
}