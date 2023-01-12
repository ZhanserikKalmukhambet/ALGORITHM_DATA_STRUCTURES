#include <iostream>

using namespace std;

const int N = 1e8 + 5;

int n;
int a[N];

void merge(int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1];
	int R[n2];

	for(int i=0; i<n1; i++)
		L[i] = a[l + i];
	for(int i=0; i<n2; i++)
		R[i] = a[m + i + 1];

	int p1 = 0, p2 = 0, k = l;
	while(p1 < n1 && p2 < n2){
		if(L[p1] <= R[p2]){
			a[k] = L[p1];
			p1++;
		}
		else{
			a[k] = R[p2];
			p2++;
		}
		k++;
	}

	while(p1 < n1){
		a[k] = L[p1];
		k++;
		p1++;
	}
	while(p2 < n2){
		a[k] = R[p2];
		k++;
		p2++;
	}
}

void merge_sort(int l, int r){
	if(l < r){
		int m = l + (r - l) / 2;

		merge_sort(l, m);
		merge_sort(m + 1, r);
		merge(l, m, r);
	}
}

int main(){
	cin >> n;

	for(int i=0; i<n; i++)
		cin >> a[i];

	merge_sort(0, n-1);

	for(int i=0; i<n; i++)
		cout << a[i] << ' ';

	return 0;
}