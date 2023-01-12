#include <bits/stdc++.h>

using namespace std;

void merge(int * a, int l1, int r1, int l2, int r2){
	int n1 = r1 - l1 + 1;
	int L[n1];
	for(int i=0; i<n1; i++)
		L[i] = a[l1 + i];

	int n2 = r2 - l2 + 1;
	int R[n2];
	for(int i=0; i<n2; i++)
		R[i] = a[l2 + i];

	int i1 = 0, i2 = 0, k = l1;

	while(i1 < n1 && i2 < n2){
		if(L[i1] < R[i2])
			a[k++] = L[i1++];
		else
			a[k++] = R[i2++];
	}

	while(i1 < n1)
		a[k++] = L[i1++];
	while(i2 < n2)
		a[k++] = R[i2++];
}

void merge_sort(int * a, int l, int r){
	if(l < r){
		int m = ceil((l + r) / 2.0);

		merge_sort(a, l, m-1);
		merge_sort(a, m, r);
		merge(a, l, m-1, m, r);
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	int a[n], b[m];

	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<m; i++)
		cin >> b[i];

	merge_sort(a, 0, n-1);
	merge_sort(b, 0, m-1);

	vector <int> v;
	int p1 = 0, p2 = 0;
	while(p1 < n && p2 < m){
		if(a[p1] < b[p2])
			p1++;
		else if(a[p1] > b[p2])
			p2++;
		else{
			v.push_back(a[p1]);
			p1++; p2++;
		}
	}

	for(int i=0; i<v.size(); i++)
		cout << v[i] << ' ';
	return 0;
}