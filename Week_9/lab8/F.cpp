#include <iostream>
#include <unordered_map>

#define ll unsigned long long
#define p 31
#define MOD 1000000007

using namespace std;

ll my_pow(int ind){
	ll k = 1;
	for(int i=0; i<ind; i++)
		k = (k * p) % MOD;

	return k;
}

ll my_hash(string s){
	ll h = 0;
	for(int i=0; i<s.size(); i++){
		h = (h + (s[i] - 'a' + 1) * my_pow(i)) % MOD;
		h %= MOD;
	}
	return h;
}

vector<int> rk(string s, string t){
	vector <int> res;

	int n = s.size();
	int m = t.size();

	int pm = 1;
	for(int i=0; i<m-1; i++)
		pm *= p;

	ll h_s = my_hash(s.substr(0, m));
	ll h_t = my_hash(t);

	for(int i=0; i<=n-m; i++){
		if(h_s == h_t)
			v.push_back(i);

		if(i + m < n)
			h_s = (h_s - s[i] * pm) * p + s[i+m];
	}
}

int main(){
	string s;
	cin >> s;

	unordered_map <ll, int> mp;
	for(int i=0; i<s.size(); i++){
		string t = "";
		for(int j=i; j<s.size(); j++){
			t += s[j];

			mp[my_hash(t)]++;
		}
	}

	cout << mp.size();
	return 0;
}
