#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n, q;
	cin >> n >> q;

	int g[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> g[i][j];

	while(q--){
		int a, b, c;
		cin >> a >> b >> c;

		a--; b--; c--;

		if(g[a][b] == 1 && g[b][c] == 1 && g[a][c] == 1)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}