#include <bits/stdc++.h>
using namespace std;

void merge(pair <pair<string, string>, double> * a, int l1, int r1, int l2, int r2){
	int n1 = r1 - l1 + 1;
	pair <pair<string, string>, double> L[n1];
	for(int i=0; i<n1; i++)
		L[i] = a[l1 + i];

	int n2 = r2 - l2 + 1;
	pair <pair<string, string>, double> R[n2];
	for(int i=0; i<n2; i++)
		R[i] = a[l2 + i];

	int i1 = 0, i2 = 0, k = l1;
	while(i1 < n1 && i2 < n2){
		if(L[i1].second < R[i2].second){
			a[k] = L[i1];
			i1++;
		}
		else if(L[i1].second == R[i2].second){
			if(L[i1].first.first < R[i2].first.first){
				a[k] = L[i1];
				i1++;
			}
			else if(L[i1].first.first == R[i2].first.first){
				if(L[i1].first.second < R[i2].first.second){
					a[k] = L[i1];
					i1++;
				}
				else{
					a[k] = R[i2];
					i2++;
				}
			}
			else{
				a[k] = R[i2];
				i2++;
			}
		}
		else{
			a[k] = R[i2];
			i2++;
		}

		k++;
	}

	while(i1 < n1)
		a[k++] = L[i1++];
	while(i2 < n2)
		a[k++] = R[i2++];
}

void merge_sort(pair<pair<string, string>, double> * a, int l, int r){
	if(l < r){
		int m = ceil((l + r) / 2.0);
		merge_sort(a, l, m-1);
		merge_sort(a, m, r);
		merge(a, l, m-1, m, r);
	}
}

map <string, double> mp;

void setMarks(){
	mp["A+"] = 4.0; mp["A"] = 3.75;
	mp["B+"] = 3.5; mp["B"] = 3.0;
	mp["C+"] = 2.5; mp["C"] = 2.0;
	mp["D+"] = 1.5; mp["D"] = 1.0;
	mp["F"] = 0;
}

int main(){
	setMarks();

	int n;
	cin >> n;

	pair <pair<string, string>, double> a[n];

	for(int i=0; i<n; i++){

		string ln, fn;
		int m;
		cin >> ln >> fn >> m;	

		int credits = 0;
		double total = 0;
		while(m--){
			string mark;
			int credit;
			cin >> mark >> credit;

			total += mp[mark] * credit;
			credits += credit;
		}
		total /= credits;

		a[i] = make_pair(make_pair(ln, fn), total);
	}

	merge_sort(a, 0, n-1);

	for(int i=0; i<n; i++){
		cout << a[i].first.first << ' ' << a[i].first.second << ' ';
		cout << fixed;
		cout << setprecision(3) << a[i].second << '\n';
	}
}