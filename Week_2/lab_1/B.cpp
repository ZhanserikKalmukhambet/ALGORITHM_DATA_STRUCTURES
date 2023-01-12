#include <bits/stdc++.h>

using namespace std;

int main(){
	stack <int> st;
	vector <int> v;
	int n, x;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;

		if(st.empty()){
			st.push(x);
			v.push_back(-1);

		}
		else{
			while(!st.empty() && x < st.top()){
				st.pop();
			}

			if(!st.empty())
				v.push_back(st.top());
			else
				v.push_back(-1);

			st.push(x);
		}
	}

	for(int i=0; i<n; i++)
		cout << v[i] << ' ';
}