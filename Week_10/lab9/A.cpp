#include <bits/stdc++.h>

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

bool checkPattern(vector <int> v, int sz){
	for(auto i : v)
		if(i == sz)
			return true;
	return false;
}

int main(){
	string a, b;
	cin >> a >> b;

	string res = a;	
	int cnt = 1;
	while(res.size() < b.size()){
		res += a;
		cnt++;
	}

	if(checkPattern(p_f(b + '#' + res), b.size())){
		cout << cnt;
	}
	else{
		if(checkPattern(p_f(b + '#' + res + a), b.size()))
			cout << cnt + 1;
		else
			cout << -1;
	}

	return 0;
}