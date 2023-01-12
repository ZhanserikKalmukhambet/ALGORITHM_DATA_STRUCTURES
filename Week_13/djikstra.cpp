#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int, int>

const int N = int(1e5);
const int INF = int(1e9);

vector <pii> g[N];

int u[N], pred[N];

vector<int> d(N, INF);

int main(){
	int n, m;
	cin >> n >> m;

	for(int i=0; i<m; i++){
		int x, y, w;
		cin >> x >> y >> w;

		// x--; y--;

		g[x].pb(mp(w, y));
		g[y].pb(mp(w, x));
	}

	int st;
	cin >> st;
	d[st] = 0;

	for(int i=0; i<n; i++){
		int v = -1;

		for(int j=0; j<n; j++)
			if(!u[j] && (v == -1 || d[j] < d[v]))
				v = j;

		u[v] = 1;

		if(d[v] == INF)
			break;

		for(auto p : g[v]){
			int u = p.second, w = p.first;

			if(d[v] + w < d[u]){
				d[u] = d[v] + w;
				pred[u] = v;
			}
		}
	}

	for(int i=0; i<n; i++)
		cout << d[i] << ' ';

	return 0;
}
