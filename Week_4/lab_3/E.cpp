#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> v;

int bin_search(vector<vector<int>> v, int n, int target){
	int cnt = 0;

	for(int i=0; i<n; i++){
		int x1 = v[i][0], y1 = v[i][1], x2 = v[i][2], y2 = v[i][3];

		if(max(x1, x2) <= target && max(y1, y2) <= target)
			cnt++;
	}
	return cnt;
}

int main(){
	int n, k;
	cin >> n >> k;

	for(int i=0; i<n; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back({x1, y1, x2, y2});
	}

	int l = 1, r = 1e9, mid;
	while(l <= r){
		mid = (l + r) / 2;

		if(bin_search(v, n, mid) >= k)
			r = mid - 1;
		else
			l = mid + 1;
	}

	cout << r + 1;
	return 0;
}