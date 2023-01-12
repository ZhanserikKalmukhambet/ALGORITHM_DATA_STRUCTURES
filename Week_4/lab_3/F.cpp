#include <iostream>
#include <algorithm>

using namespace std;

int bin_search(int a[], int n, int tar){
	int l = 0, r = n - 1, mid, ind = -1;

	while(l <= r){
		mid = (l + r) / 2;

		if(tar < a[mid]){
			ind = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	return ind;
}

int getSum(int a[], int pos){
	int sum = 0;
	for(int i=0; i<pos; i++)
		sum += a[i];
	return sum;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a + n);

	int q;
	cin >> q;
	for(int i=0; i<q; i++){
		int x;
		cin >> x;

		if(x < a[0]){
			cout << 0 << ' ' << 0 << '\n';
			continue;
		}
		if(x >= a[n-1]){
			cout << n << ' ' << getSum(a, n) << '\n';
			continue;
		}

		int pos = bin_search(a, n, x);
		int sum = getSum(a, pos);
		cout << pos << ' ' << sum << '\n';
	} 
}