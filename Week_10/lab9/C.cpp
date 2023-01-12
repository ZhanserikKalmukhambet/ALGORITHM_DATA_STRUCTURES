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
	string s, t;
	cin >> s >> t;

	vector <int> p = p_f(s + '#' + t + t);
	bool ok = false;
	for(int i=0; i<p.size(); i++){
		if(s.size() == p[i]){
			ok = true;
			cout << i - 2 * s.size();
		}
	}

	if(!ok)
		cout << -1;
}