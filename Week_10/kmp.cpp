#include <iostream>
#include <vector>

using namespace std;

vector<int> p_f(string s){ // this algorithm works in O(n), in worst case 2 * n, diff of adjacent values in p - maximum 1 or 0
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
	cin >> s >> t; // occurences of t in s


	string gen = t + '#' + s;

	vector <int> p = p_f(gen);
	int m = t.size();
	for(int i=0; i<p.size(); i++){
		if(p[i] == m)
			cout << i - 2 * m << ' ';
	}
}