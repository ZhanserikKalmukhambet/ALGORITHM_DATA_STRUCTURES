#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define ull unsigned long long
#define p 11
#define MOD 1000000007

ull my_pow(int i){
	ull k = 1;
	for(int ind=0; ind < i; ind++){
		k = (k * p) % MOD;
	}
	return k;
}

ull my_hash(string s){
	ull h = 0;
	for(int i=0; i<s.size(); i++){
		h = (h + (s[i] - 47) * my_pow(i)) % MOD;
		h %= MOD;
	}
	return h;
}

int main(){
	int n;
	cin >> n;

	unordered_map <string, ull> mp;
	vector <pair<string, ull>> v(2 * n);
	for(int i=0; i<2*n; i++){
		string s;
		cin >> s;

		mp[s]++;
		v[i] = make_pair(s, my_hash(s));
	}

	int cnt = 0;
	for(auto pair : v){
		if(cnt < n && mp.count(to_string(pair.second))){
			cout << "Hash of string " << "\"";
			cout << pair.first << "\" is" << ' ' << pair.second << '\n';
			cnt++;
		}
	}
	return 0;
}