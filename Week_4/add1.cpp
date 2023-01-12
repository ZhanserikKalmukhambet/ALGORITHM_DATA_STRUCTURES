#include <bits/stdc++.h>

using namespace std;

// find first and last position of target

int bin_search(int a[], int n, int target, bool leftMost){
	int l = 0, r = n - 1, mid, ind = -1;

	while(l <= r){
		mid = (l + r) / 2;

		if(target > a[mid])
			l = mid + 1;
		else if(target < a[mid])
			r = mid - 1;
		else{
			ind = mid;

			if(leftMost)
				r = mid - 1;
			else
				l = mid + 1;
		}
	}

	return ind;
}

pair<int, int> getRes(int a[], int n, int target){
	return make_pair(bin_search(a, n, target, true), bin_search(a, n, target, false));
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	int target;
	cin >> target;

	cout << getRes(a, n, target).first << ' ' << getRes(a, n, target).second;
}