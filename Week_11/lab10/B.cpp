#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> g[100];
vector <int> d(100, 100);

int used[100];

void bfs(int v, int end){
	used[v] = 1;
	d[v] = 0;

	queue <int> q;
	q.push(v);

	while(!q.empty()){
		int vx = q.front();
		q.pop();

		for(auto adj : g[vx]){
			if(!used[adj]){
				used[adj] = 1;
				d[adj] = d[vx] + 1;
				q.push(adj);
			}

			if(adj == end)
				return;
		}
	}
}

int main(){
	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int mode;
			cin >> mode;

			if(mode == 1)
				g[i].push_back(j);
		}
	}

	int st, end;
	cin >> st >> end;

	bfs(st-1, end-1);

	if(!used[end-1])
		cout << -1;
	else
		cout << d[end-1];

	return 0;
}