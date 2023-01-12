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

vector<int> occurences(vector <int> p, int sz){
	vector <int> res;
	for(int i=0; i<p.size(); i++)
		if(p[i] == sz)
			res.push_back(i - 2*sz);
	return res;
}

int main(){
	string txt, s;
	cin >> txt >> s;

	vector <int> p = p_f(s + '#' + txt);

	vector <int> res = occurences(p, s.size());

	cout << res.size() << '\n';
	for(auto i : res)
		cout << i + 1 << ' ';
}