// Time complexity of kruskal - O(E * logV)
// more specific data structure
// it's not profitable when number of edges is greater than its' vertices

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int, int>

vector<pair<int, pii>> g;

int component[100], sz[100];

void make_set(int n){
	for(int i=1; i<=n; i++){
		component[i] = i;
		sz[i] = 1;
	}
}

int find(int a){
	if(a == component[a])
		return a;
	return component[a] = find(component[a]);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b)
		return;

	if(sz[b] > sz[a])
		swap(a, b);

	// merge
	component[b] = a;
	sz[a] += sz[b];
}

int main(){
	int n, m;
	cin >> n >> m;

	for(int i=0; i<m; i++){
		int a, b, w;
		cin >> a >> b >> w;

		g.pb(mp(w, mp(a, b)));
	}

	sort(g.begin(), g.end());

	make_set(n);

	vector <pii> mst;
	int mst_sum = 0;
	for(auto e : g){
		if(find(e.second.first) != find(e.second.second)){
			mst.pb(mp(e.second.first, e.second.second));
			mst_sum += e.first;
			unite(e.second.first, e.second.second);
		}
	}

	cout << mst_sum << '\n';
	for(auto p : mst)
		cout << p.first << ' ' << p.second << '\n';

	return 0;
}