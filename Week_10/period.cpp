#include <iostream>
#include <vector>

using namespace std;

vector<int> p_f(string s){
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
	string s;
	cin >> s;
	int n = s.size();

	int maxi = 1;
	string t = "";	
	for(int i=0; i<=n/2; i++){
		t += s[i];

		if(n % t.size() != 0)
			continue;

		int cnt = 0;
		string temp = t + '#' + s;
		vector <int> p = p_f(temp);
		for(int j=0; j<p.size(); j++){
			if(p[j] == t.size())
				cnt++;
		}

		if(cnt * t.size() == n){
			maxi = max(maxi, cnt);
		}
	}

	cout << maxi << '\n';
}