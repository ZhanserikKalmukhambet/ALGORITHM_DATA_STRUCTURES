#include <bits/stdc++.h>

using namespace std;

int bin_search(int a[], int n, int target){
	int cnt = 0;
	for(int i=0; i<n; i++){
		int temp = a[i];
		cnt += temp / target;
		if(temp % target != 0)
			cnt++;
	}
	return cnt;
}

int main(){
	int n, f;
	cin >> n >> f;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	int l = 1, r = 1e5, mid;
	while(l <= r){
		mid = (l + r) / 2;

		if(bin_search(a, n, mid) <= f)
			r = mid - 1;
		else
			l = mid + 1;
	}
	cout << r + 1;
	return 0; 
}