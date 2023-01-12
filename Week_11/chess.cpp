#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

int used[100][100];

pii pred[100][100];

int main(){
	for(int i=0; i<100; i++)
		for(int j=0; j<100; j++)
			pred[i][j] = mp(0, 0);

	vector <pii> move = { {-1, -2}, {-2, -1}, {-1, 2}, {-2, 1}, {1, 2}, {1, -2}, {2, 1}, {2, -1} };

	int n, x1, y1, x2, y2, cnt = 0;
	cin >> n >> x1 >> y1 >> x2 >> y2;

	queue <pii> q;
	q.push(mp(x1, y1));

	used[x1][y1] = 1;

	vector <pii> path;
	while(!q.empty()){
		int sz = q.size();

		for(int i=0; i<sz; i++){
			pii pos = q.front();
			q.pop();

			for(int j=0; j<8; j++){
				int x = move[j].first + pos.first;
				int y = move[j].second + pos.second;

				if(x >= 0 && x <= n && y >= 0 && y <= n && !used[x][y]){
					pred[x][y] = mp(x - move[j].first, y - move[j].second);

					q.push(mp(x, y));
					used[x][y] = 1;
				}

				if(x == x2 && y == y2){
					cout << cnt + 1 << '\n';

					int tmp1 = x, tmp2 = y;
					while(tmp1 != 0 && tmp2 != 0){
						path.push_back(mp(tmp1, tmp2));

						int z = tmp1;
						tmp1 = pred[tmp1][tmp2].first;
						tmp2 = pred[z][tmp2].second;
					}

					reverse(path.begin(), path.end());

					for(auto p : path)
						cout << p.first << ' ' << p.second << '\n';

					return 0;
				}
			}
		}
		cnt++; 
	}

	cout << cnt;

	return 0; 
}