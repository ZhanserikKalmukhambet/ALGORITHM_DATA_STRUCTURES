#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5+1;

vector <int> g[N];
int used[N];

void dfs(int v){
	used[v] = 1;

	for(auto adj : g[v])
		if(!used[adj])
			dfs(adj);
}

int main(){
	int n, m;
	cin >> n >> m;

	while(m--){
		int x, y;
		cin >> x >> y;
		x--; y--;

		g[x].push_back(y);
		g[y].push_back(x);
	}

	int s, f;
	cin >> s >> f;

	dfs(s-1);

	if(used[f-1] == 1)
		cout << "YES";
	else
		cout << "NO";

	return  0;
}	