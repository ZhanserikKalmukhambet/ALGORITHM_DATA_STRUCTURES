#include <bits/stdc++.h>

using namespace std;

int bin_s(int a[], int n, int x){
	int l = 0, r = n-1, mid, ind = -1;

	while(l <= r){
		mid = (l + r) / 2;

		if(x <= a[mid]){
			ind = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}

	return ind;
}

int main(){
	vector <int> v;
	int n, m, val = 1;
	cin >> n >> m;

	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(i)
			a[i] += a[i-1];
	}

	for(int i=0; i<m; i++){
		int x;
		cin >> x;

		cout << bin_s(a, n, x) + 1 << '\n';
	}
}