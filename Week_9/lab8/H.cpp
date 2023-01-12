#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define p 31


ll my_hash(string s) {
    ll h = 0;
    for (int i = 0; i < s.size(); i++) {
        h = h * p + (int)s[i];
    }
    return h;
}

bool rk(string s, string t) {
    int n = s.size();
    int m = t.size();

    ll ht = my_hash(t);
    ll hs = my_hash(s.substr(0, m));

    ll pm = 1;
    for (int i = 0; i < m - 1; i++) {
        pm *= p;
    }

    for (int i = 0; i <= n - m; i++) {
        if (hs == ht) {
            return true;
        }
        if (i < n - m) {
            hs = ((hs - pm * s[i]) * p) + s[i + m];
        }
    }
    return false;
}

int main(){
	int n;
	cin >> n;

	if(n == 1){
		cout << "";
		return 0;
	}

	vector<pair<int, string>> words(n);
	for(int i=0; i<n; i++){
		string s;
		cin >> s;

		words[i] = make_pair(s.size(), s);
	}

	sort(words.begin(), words.end());

	int longest = 0;
	string ans;
	string basic = words[0].second;

	for(int i=0; i<basic.size(); i++){
		string t = "";
		for(int j=i; j<basic.size(); j++){
			t += basic[j];
			bool ok = true;

			for(int q=1; q<n; q++){
				if(rk(words[q].second, t) == false){
					ok = false;
					break;
				}
			}

			if(ok && longest < t.size()){
				longest = t.size();
				ans = t;
			}
		}
	}

	cout << ans;
	return 0;
}