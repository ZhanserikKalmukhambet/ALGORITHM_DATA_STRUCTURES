#include <iostream>
#include <vector>

using namespace std;

const int p = 31;

using ll = long long;

ll MOD = 1e9 + 7;

ll my_hash(string s){
    ll h = 0;
    for(int i=0; i<s.size(); i++)
        h = h * p + s[i];
    return h;
}

vector<ll> rk(string s, string w){
    vector <ll> res;
    int n = s.size();
    int m = w.size();

    int pm = 1;
    for(int i=0; i<m-1; i++)
        pm = p * pm;

    ll h_s_sub = my_hash(s.substr(0, m));
    ll h_w = my_hash(w);

    for(int i=0; i<=n-m; i++){
        if(h_s_sub == h_w)
            res.push_back(i);

        if(i + m < n)
            h_s_sub = (h_s_sub - s[i] * pm) * p + s[i + m];
    }

    return res;
}

int main(){
    string s, w;
    cin >> s >> w;

    vector <ll> res = rk(s, w);

    for(auto ind : res)
        cout << ind << ' ';
}