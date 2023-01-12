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
	int k;
	string s, txt;
	cin >> s >> k >> txt;

	vector <int> p = p_f(s + '#' + txt);
	int cnt = 0;
	for(auto i : p){
		if(i == s.size())
			cnt++;
	}

	if(cnt >= k)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}