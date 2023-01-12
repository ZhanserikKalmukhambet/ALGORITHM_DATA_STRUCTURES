#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>

const int N = (int)1e5 + 7;
const int inf = (int)1e9;

int n, m;
int d[N], pr[N];

vector<pii> g[N];

int main() {
	int st;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;

		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, w));
	}

	cin >> st;	

	for (int i = 0; i < n; i++)
		d[i] = inf;

	d[st] = 0;		

	priority_queue<pii> pq;
	pq.push(make_pair(-0, st));

	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();

		int dv = p.first, v = p.second;

		if (dv > d[v])
			continue;

		for (auto p : g[v]){
			int u = p.first, w = p.second;
			if (d[u] > d[v] + w){
				d[u] = d[v] + w;
				pq.push(make_pair(-d[u], u));
				pr[u] = v;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
		cout << "d[" << i << "] = " << (d[i] == inf ? -1 : d[i]) << "\n";

	return 0;
}
