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

const int N = 100;
const int INF = 100000;

vector<int> d(N, INF);
vector<int> pred(N, -1);

int main(){
	int n;
	cin >> n;

	vector <Edge> edges;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			int w;
			cin >> w;

			edges.push_back(Edge(i, j, w));
		}
	}

	int st = 0;
	d[st] = 0;

	for(int i=0; i<n; i++){
		bool any = false;
		for(int j=0; j<edges.size(); j++){
			if(d[edges[j].a] < INF || d[edges[j].a] + edges[j].cost < d[edges[j].b]){
				d[edges[j].b] = d[edges[j].a] + edges[j].cost;
				pred[edges[j].b] = edges[j].a;
				any = true;
			}
		}

		if(!any)
			break;
	}

	bool cycle = false;
	int src;
	for(int i=0; i<edges.size(); i++){
		int v = edges[i].a, u = edges[i].b, w = edges[i].cost;
		if(d[v] + w < d[u]){
			cycle = true;
			src = u;
			break;
		}
	}

	if(!cycle){
		cout << "NO";
	}
	else{
		cout << "YES";
		while(pred[src] != -1){
			cout << src << ' ';
			src = pred[src];
		}
	}
}