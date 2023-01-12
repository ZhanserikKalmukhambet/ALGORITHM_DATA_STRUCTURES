#include <iostream>
#include <vector>
#include <queue>

#define mp make_pair

using namespace std;

int used[100][100];	
char g[100][100];

void bfs(int row, int col, int n, int m){
	queue <pair<int, int>> q;
	q.push(mp(row, col));

	used[row][col] = 1;

	while(!q.empty()){
		int i = q.front().first;
		int j = q.front().second;

		if(i-1 >= 0 && g[i-1][j] == '1' && !used[i-1][j]){
			used[i-1][j] = 1;
			q.push(mp(i-1, j));
		}
		if(i+1 < n && g[i+1][j] == '1' && !used[i+1][j]){
			used[i+1][j] = 1;
			q.push(mp(i+1, j));
		}
		if(j-1 >= 0 && g[i][j-1] == '1' && !used[i][j-1]){
			used[i][j-1] = 1;
			q.push(mp(i, j-1));
		}
		if(j+1 < m && g[i][j+1] == '1' && !used[i][j+1]){
			used[i][j+1] = 1;
			q.push(mp(i, j+1));
		}

		q.pop();
	}
}

int main(){
	int n, m, cnt = 0;
	cin >> n >> m;

	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> g[i][j];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!used[i][j] && g[i][j] == '1'){
				bfs(i, j, n, m);
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}