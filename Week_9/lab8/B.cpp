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

int main() {
    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    vector<int> a = rk(s1, t);
    vector<int> b = rk(s2, t);

    unordered_map<int, int> m;

    for (auto i: a) {
        m[i]++;
    }
    ll cnt = 0;
    for (auto i: b) {
        if (m[i]) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}