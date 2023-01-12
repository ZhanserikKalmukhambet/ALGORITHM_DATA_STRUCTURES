#include <iostream>

using namespace std;

string bin_s(int a[], int l, int r, int tar){
	int mid;
	while(l <= r){
		mid = (l + r) / 2;

		if(a[mid] == tar)
			return "Yes";

		if(tar > a[mid])
			l = mid + 1;
		else
			r = mid - 1;
	}
	return "No";
}

int main(){
	int n, target;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	cin >> target;

	cout << bin_s(a, 0, n-1, target);
}