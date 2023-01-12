#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int, int>

vector <pair<int, pii>> g;

int component[1010];
int sz[1010];

void make_set(int n){
	for(int i=1; i<=n; i++){
		component[i] = i;
		sz[i] = i;
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

	component[b] = a;
	sz[a] += sz[b];
}

void setRoad(int a, int b, int c){
	g.pb(mp(c, mp(a, b)));
}

int main(){
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	int mini = min(x, y);

	while(m--){
		string s;
		int a, b, c;

		cin >> s >> a >> b >> c;

		if(s == "big"){
			setRoad(a, b, x * c);
		}
		else if(s == "small"){
			setRoad(a, b, y * c);
		}
		else{
			setRoad(a, b, mini * c);
		}
	}

	sort(g.begin(), g.end());
	make_set(n);

	int mst_sum = 0;
	for(auto e : g){
		int a = e.second.first, b = e.second.second, c = e.first;

		if(find(a) != find(b)){
			mst_sum += c;

			unite(a, b);
		}
	}

	cout << mst_sum;

	return 0;
}