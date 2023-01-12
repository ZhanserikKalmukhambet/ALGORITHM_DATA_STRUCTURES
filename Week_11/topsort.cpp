#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> g[1000];
vector <int> order(1000, 0);

bool used[1000];

void dfs(int v, int & ind){
	used[v] = 1;

	for(auto adj : g[v])
		if(!used[adj])
			dfs(adj, ind);

	order[ind] = v;
	ind--;
}

int main(){
	int n, m;
	cin >> n >> m;

	while(m--){
		int x, y;
		cin >> x >> y;
		x--; y--;

		g[x].push_back(y);
	}

	int ind = n-1;
	for(int i=0; i<n; i++){
		if(!used[i])
			dfs(i, ind);
	}

	for(int i=0; i<n; i++)
		cout << order[i]+1 << ' ';
}