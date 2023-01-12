#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int, int>

const int N = 2*1e5 + 10;

int par[N];
int sz[N];

vector <pii> g;

void make_set(int n){
	for(int i=1; i<=n; i++)
		par[i] = i;
}

int find(int a){
	if(a == par[a])
		return a;

	return par[a] = find(par[a]);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b)
		return;

	if(sz[b] > sz[a])
		swap(a, b);

	// merge
	par[b] = a;
	sz[a] += sz[b];
}


int main(){
	int n, m;
	cin >> n >> m;

	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;

		g.pb(mp(min(a,b), max(a, b)));
	}

	// cout << endl;
	// for(auto p : g){
	// 	cout << p.first << ' ' << p.second << '\n';
	// }

	make_set(n);

	int cnt = 0;
	vector <int> res;

	for(int i=n; i>0; i--){
		res.pb(cnt);

		for(auto p : g){
			if(i == p.first){
				
			}
		}
	}
}
