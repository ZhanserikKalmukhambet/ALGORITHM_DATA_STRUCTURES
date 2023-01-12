#include <iostream>

using namespace std;

int solve(int n, int m, int p){
	int a[n][m];
	int highScore[m];
	fill(highScore, highScore + m, 0);

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];

			highScore[j] = max(highScore[j], a[i][j]);
		}
	}

	int sum = 0;
	for(int i=0; i<m; i++)
		sum += abs(highScore[i] - a[p][i]);

	return sum;
}

int main(){
	int t;
	cin >> t;

	for(int i=0; i<t; i++){ // rows - n - number of participants, columns - m - number of days, p - id of a John
		int n, m, p;
		cin >> n >> m >> p;

		cout << "Case #" << i+1 << ": " << solve(n, m, p-1) << '\n';
	}
}