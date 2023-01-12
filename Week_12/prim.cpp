// Time complexity of Prim's algorithm - O(E * log(E))
// It's profitable to use when number of edges is much more than its' edges
// adjacency matrix - for effeciency

#include <bits/stdc++.h>

using namespace std;

const int N = 1e7;

vector <int> d(100, N);
int g[100][100];

int used[100];
int path[100];

int mst_sum(int n){
	int sum = 0;
	for(int i=0; i<n; i++)
		sum += d[i];

	return sum;
}

int main(){
	int n, m, x, y, l;
	cin >> n >> m;

	for(int i=0; i<m; i++){
		cin >> x >> y >> l;
		// x--; y--;

		g[x][y] = l;
		g[y][x] = l;
	}

	d[0] = 0;
	for(int i=0; i<n; i++){
		int v = -1;

		for(int j=0; j<n; j++){
			if(!used[j] && (v == -1 || d[v] > d[j]))
				v = j;
		}

		used[v] = 1;
		for(int j=0; j<n; j++){
			if(!used[j] && g[v][j] > 0){
				if(d[j] > g[v][j])
					d[j] = g[v][j];
			}
		}	
	}

	// for(int i=0; i<n; i++)
	// 	cout << i << ' ' << d[i] << '\n';

	// cout << mst_sum(n);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout << g[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}