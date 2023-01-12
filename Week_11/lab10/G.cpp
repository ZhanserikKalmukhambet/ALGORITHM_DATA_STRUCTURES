#include <bits/stdc++.h>

using namespace std;

vector <int> g[505];

int mark[505];

vector <int> cycle_path;

stack <int> st;

bool cycle = false;

void dfs(int v){
	st.push(v);

	mark[v] = 1;

	for(auto adj : g[v]){
		if(mark[adj] == 0){
			dfs(adj);
		}
		else if(mark[adj] == 1 && !cycle){
			cycle = true;

			while(st.top() != adj){
				cycle_path.push_back(st.top());
				st.pop();
			}

			cycle_path.push_back(adj);
			cycle_path.push_back(v);
			reverse(cycle_path.begin(), cycle_path.end());

			return;
		}
	}

	mark[v] = 2;

	if(!st.empty())
		st.pop();
}

void dfs2(int v, int sour, int dest, bool & cycle_found){
	mark[v] = 1;

	for(auto adj : g[v]){
		if(v == sour && adj == dest)
			continue;

		if(mark[adj] == 0){
			dfs2(adj, sour, dest, cycle_found);
		}
		else if(mark[adj] == 1){
			cycle_found = true;
			return;
		}
	}

	mark[v] = 2;
}

int main(){
	int n, m;
	cin >> n >> m;

	while(m--){
		int x, y;
		cin >> x >> y;

		g[x].push_back(y);
	}

	for(int i=1; i<=n; i++){
		if(mark[i] == 0)
			dfs(i);

		if(cycle)
			break;
	}

	if(!cycle){
		cout << "YES";
		return 0;
	}

	for(int i=1; i<cycle_path.size(); i++){
		int sour = cycle_path[i-1], dest = cycle_path[i];

		for(int j=1; j<=n; j++)
			mark[j] = 0;

		bool cycle_found = false;

		for(int j=1; j<=n; j++){
			if(mark[j] == 0)
				dfs2(j, sour, dest, cycle_found);
		}

		if(!cycle_found){
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}