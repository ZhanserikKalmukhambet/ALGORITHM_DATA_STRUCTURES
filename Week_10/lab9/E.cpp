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

int findPattern(vector <int> v, int sz){
	int cnt = 0;
	for(auto i : v)
		if(i == sz)
			cnt++;

	return cnt;
}

int main(){
	int t;
	cin >> t;

	while(t--){
		string s;
		int k;
		cin >> s >> k;

		vector <int> p = p_f(s);
		int pos = p[p.size()-1];
		
		string temp = "";
		for(int i=pos; i<s.size(); i++)
			temp += s[i];

		string res = s;

		cout << temp.size() * (k - 1) + res.size() << '\n';
	}
}