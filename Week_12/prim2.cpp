#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mp make_pair

const int N = 100;
const int inf = 1e9 + 10;

vector<pii> g[N];

bool used[N];

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int x, y, w;
        cin >> x >> y >> w;

        g[x].pb(mp(w, y));
        g[y].pb(mp(w, x));
    }

    int mst_sum = 0;
    priority_queue <pii> pq;
    pq.push({-0, 1});

    while(!pq.empty()){
        int v = pq.top().second;
        int dv = pq.top().first;
        pq.pop();

        if(used[v])
            continue;

        used[v] = 1;
        mst_sum += (dv - 2*dv);

        for(auto p : g[v]){
            if(!used[p.second]){
                pq.push(mp(-p.first, p.second));
            }
        }
    }

    cout << mst_sum;

    return 0;
}