#include <iostream>
#include <vector>

using namespace std;

vector <int> p_f(string s){
	int n = s.size();
	vector <int> p(n);
	p[0] = 0;

	for(int i=1; i<n; i++){
		int j = p[i-1];
		while(j > 0 && s[i] != s[j])
			j = p[j-1];

		if(s[i] == s[j])
			j++;

		p[i] = j;
	}
	return p;
}

int main(){
	string city;
	int n;
	cin >> city >> n;

	city[0] = tolower(city[0]);

	vector <pair<string, int>> res;
	int maxi = -1;
	for(int i=0; i<n; i++){
		string s;
		cin >> s;

		string t = "";
		for(int j=0; j<s.size(); j++){
			t += tolower(s[j]);

			vector <int> p = p_f(t + '#' + city);
			if(p[p.size()-1] == t.size()){
				int temp = t.size();
				res.push_back(make_pair(s, temp));
				maxi = max(maxi, temp);
			}
		}
	}

	if(res.size() == 0){
		cout << 0;
		return 0;
	}

	vector <string> ans;
	for(auto pr : res){
		if(maxi == pr.second)
			ans.push_back(pr.first);
	}

	cout << ans.size() << '\n';
	for(auto s : ans)
		cout << s << '\n';
}