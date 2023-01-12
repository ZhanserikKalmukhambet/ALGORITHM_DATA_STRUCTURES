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

vector<int> rk(string s, string t) {
    vector<int> res;
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
            res.push_back(i);
        }
        if (i < n - m) {
            hs = ((hs - pm * s[i]) * p) + s[i + m];
        }
    }
    return res;
}

int main(){
	unordered_map <int, int> mp;

	string s;
	cin >> s;
	int n = s.size();

	int t;
	cin >> t;
	while(t--){
		string w;
		cin >> w;

		int m = w.size();

		vector <int> v = rk(s, w);
		for(int i=0; i<v.size(); i++){
			int temp = v[i];
			for(int j=0; j<m; j++)
				mp[temp++]++;
		}
	}

	if(mp.size() == n)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}