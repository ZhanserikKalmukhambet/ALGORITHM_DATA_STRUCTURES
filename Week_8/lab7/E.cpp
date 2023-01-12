#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, vector<int>> a, pair<int, vector<int>> b){
	if(a.first == b.first){
		vector <int> x = a.second;
		vector <int> y = b.second;

		for(int i=0; i<x.size(); i++)
			return x[i] < y[i];
	}
	return a.first > b.first;
}

int main(){
	int n, m, x;
	cin >> n >> m;

	vector <pair<int, vector<int>>> a(n);
	for(int i=0; i<n; i++){
		vector <int> temp(m);
		int sum = 0;
		for(int j=0; j<m; j++){
			cin >> temp[j];
			sum += temp[j];
		}
		a[i] = make_pair(sum, temp);
	}

	sort(a.begin(), a.end(), cmp);

	for(int i=0; i<n; i++){
		for(int j=0; j<a[i].second.size(); j++)
			cout << a[i].second[j] << ' ';
		cout << '\n';
	}
}