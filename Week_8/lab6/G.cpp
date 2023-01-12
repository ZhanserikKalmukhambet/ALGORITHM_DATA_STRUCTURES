#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair <string, string> a, pair <string, string> b){
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main(){
	int n;
	cin >> n;

	string old, new_;
	pair<string, string> a[n];

	int res_size = n;

	map <string, string> m;

	map <string, string> mode;

	for(int i=0; i<n; i++){
		cin >> old >> new_;

		m[old] = new_;
		mode[new_] = "previous";
		a[i] = make_pair(old, new_);
	}

	for(int i=0; i<n; i++){

		if(mode[a[i].first] == "unused")
			continue;

		auto it = m.find(a[i].second);
		if(it != m.end()){
			res_size--;
			mode[a[i].second] = "unused";
			a[i].second = m[a[i].second];
		}
		else{
			mode[a[i].second] = "same";
		}
	}

	sort(a, a + n, cmp);

	cout << res_size << '\n';
	for(int i=0; i<n; i++){
		if(mode[a[i].first] != "unused")
			cout << a[i].first << ' ' << a[i].second << '\n';
	}
}