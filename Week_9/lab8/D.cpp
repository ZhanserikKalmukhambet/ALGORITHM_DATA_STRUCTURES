#include <iostream>
#include <climits>

long long q = LONG_LONG_MAX;
long long p_pow[100005];

using namespace std;

void set_p_pow(){
	int p = 31;
	p_pow[0] = 1;
	for(int i=1; i<100005; i++)
		p_pow[i] = (p * p_pow[i-1]) % q;
}

long long get_hash(string s){
	long long h_i = 0;
	for(int i=0; i<s.size(); i++)
		h_i += ((s[i] - 'a' + 1) * p_pow[i]) % q;

	return h_i;
}

int findExistance(long long * hash, int n, long long h_i, int m){
	int cnt = 0;
	for(int i=0; i < n - m + 1; i++){
		long long temp = hash[i + m - 1];
		if(i)
			temp -= hash[i-1];

		if(temp == h_i * p_pow[i])
			cnt++;
	}

	return cnt;
}

int main(){
	set_p_pow();

	int t;
	while(cin >> t){
		if(t == 0)
			break;

		string a[t];
		long long h[t];
		for(int i=0; i<t; i++){
			cin >> a[i];
			h[i] = get_hash(a[i]);
		}

		string txt;
		cin >> txt;
		int n = txt.size();

		long long hash[n];
		for(int i=0; i<n; i++){
			hash[i] = ((txt[i] - 'a' + 1) * p_pow[i]) % q;
			if(i)
				hash[i] += hash[i-1];
		}

		pair<string, int> res[t];
		for(int i=0; i<t; i++)
			res[i] = make_pair(a[i], findExistance(hash, n, h[i], a[i].size()));

		int maxi = res[0].second;
		for(int i=0; i<t; i++)
			maxi = max(maxi, res[i].second);

		cout << maxi << '\n';
		for(int i=0; i<t; i++)
			if(res[i].second == maxi)
				cout << res[i].first << '\n';
	}
}