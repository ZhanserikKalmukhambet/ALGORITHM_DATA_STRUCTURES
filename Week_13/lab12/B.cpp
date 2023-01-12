#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int INF = (int)1e9;

#define pii pair<int, int>
#define pb push_back
#define mp make_pair

int n, m;
vector<pii> g[N];

int getDist(int st, int end){
	vector<int> d(N, INF);
	d[st] = 0;

	priority_queue<pii> pq;
	pq.push(make_pair(-0, st));

	while(!pq.empty()){
		pii p = pq.top();
		pq.pop();

		int dv = p.first, v = p.second;

		if(dv > d[v])
			continue;

		for(auto p : g[v]){
			int w = p.first, u = p.second;
			if(d[u] > d[v] + w){
				d[u] = d[v] + w;
				pq.push(mp(-d[u], u));
			}
		}
	}

	return d[end];
}

int main(){
	cin >> n >> m;

	for(int i=0; i<m; i++){
		int x, y, w;
		cin >> x >> y >> w;
		g[x].pb(mp(w, y));
		g[y].pb(mp(w, x));
	}

	int s, a, b, f;
	cin >> s >> a >> b >> f;

	int sa = getDist(s, a);
	int sb = getDist(s, b);
	int ab = getDist(a, b);
	int af = getDist(a, f);
	int bf = getDist(b, f);

	if(min(sa + ab + bf, sb + ab + af) < INF)
		cout << min(sa + ab + bf, sb + ab + af);
	else
		cout << -1;

	return 0;
}