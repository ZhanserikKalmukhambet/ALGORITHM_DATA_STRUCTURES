#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <int> g[1000];

vector <int> ids(1000, -1);
vector <int> low(1000);

bool inStack[1000];

stack <int> st;

int id = 0;
int cnt = 0;

void dfs(int v){
	st.push(v);
	inStack[v] = 1;
	
	ids[v] = low[v] = id++;

	for(auto adj : g[v]){
		if(ids[adj] == -1)
			dfs(adj);

		if(inStack[adj])
			low[adj] = min(low[v], low[adj]);
	}

	if(ids[v] == low[v]){
		while(st.top() != v){
			inStack[st.top()] = false;
			st.pop();
		}
		cnt++;
	}
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
		if(ids[i] == -1)
			dfs(i);
	}

	cout << cnt;

	return 0;
}