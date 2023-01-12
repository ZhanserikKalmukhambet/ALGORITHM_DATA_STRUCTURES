#include <bits/stdc++.h>

using namespace std;

struct Edge{
	int a, b, cost;

	Edge(int a, int b, int cost){
		this->a = a;
		this->b = b;
		this->cost = cost;
	}
};

const int N = 100000;
const int INF = (int)1e9;

vector<int> d(N, INF);

int main(){
	int n, m;
	cin >> n >> m;

	vector <Edge> edges;

	for(int i=0; i<m; i++){
		int x, y, w;
		cin >> x >> y >> w;

		edges.push_back(Edge(x, y, w));
	}

	d[0] = 0;

	for(int i=0; i<n-1; i++){
		bool any = false;

		for(int j=0; j<m; j++){
			if(d[edges[j].a] < INF){
				d[edges[j].b] = min(d[edges[j].b], d[edges[j].a] + edges[j].cost);
				any = true;
			}
		}


		if(!any)
			break;
	}

	for(int i=0; i<n; i++)
		cout << d[i] << ' ';

	
}