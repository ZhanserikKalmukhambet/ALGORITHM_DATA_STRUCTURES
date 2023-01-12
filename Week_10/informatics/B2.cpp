#include <iostream>
#include <vector>

#define p 31

using namespace std;

int my_hash(string s){
	int h = 0;
	for(int i=0; i<s.size(); i++)
		h = h * p + int(s[i]);

	return h;
}

vector<int> rk(string s, string t){
	int n = s.size(), m = t.size();
	vector <int> res;

	int h_s = my_hash(s.substr(0, m));
	int h_t = my_hash(t);

	int pm = 1;
	for(int i=0; i<m-1; i++)
		pm *= p;

	for(int i=0; i<=n-m; i++){
		if(h_s == h_t)
			res.push_back(i);

		if(i + m < n)
			h_s = (h_s - s[i] * pm) * p + s[i + m];
	}

	return res;
}

int main(){
	// string s, t;
	// cin >> s >> t;

	// vector <int> res = rk(s, t);

	// for(int i : res)
	// 	cout << i << ' ';

	// return 0;

	cout << 1 + int('a');
}