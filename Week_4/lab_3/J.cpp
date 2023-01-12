#include <bits/stdc++.h>

using namespace std;

int bin_search(int a[], int n, int target){
	int cnt = 0;
	for(int i=0; i<n; i++){
		int temp = a[i];
		if(temp % target == 0)
			cnt += temp / target;
		else
			cnt += temp / target + 1;
	}

	return cnt;
}

int main(){
	int n, h;
	cin >> n >> h;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	int l = 1, r = 1e9, mid;

	while(l <= r){
		mid = (l + r) / 2;

		if(bin_search(a, n, mid) <= h)
			r = mid - 1;
		else
			l = mid + 1;
	}

	cout << r + 1;
	return 0;
}