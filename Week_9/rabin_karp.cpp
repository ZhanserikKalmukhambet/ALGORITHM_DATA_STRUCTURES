#include <bits/stdc++.h>	

using namespace std;

long long q = LONG_LONG_MAX;

int main(){
	vector <int> res;

	string s;
	string t;
	cin >> s >> t;

	int n = s.size();
	int m = t.size();
	int p = 31;

	vector <long long> p_pow(n);
	
	p_pow[0] = 1;
	for(int i=1; i<n; i++)
		p_pow[i] = (p_pow[i-1] * p) % q;

	vector <long long> h(n);
	for(int i=0; i<n; i++){
		h[i] = ((s[i] - 'a' + 1) * p_pow[i]) % q;
		if(i)
			h[i] += h[i-1];
	}

	long long hash_of_t = 0;
	for(int i=0; i<m; i++)
		hash_of_t += ((t[i] - 'a' + 1) * p_pow[i]) % q;

	for(int i=0; i<n-m+1; i++){
		long long hash = h[i + m - 1];
		if(i)
			hash -= h[i-1];	

		if(hash_of_t * p_pow[i] == hash)
			res.push_back(i);
	}

	for(auto ind : res)
		cout << ind << ' ';

	return 0;
}

