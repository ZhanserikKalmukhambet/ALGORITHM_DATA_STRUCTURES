#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;

    string a[t];
    string s;
    getline(cin, s);
    a[0] = s;

    for(int i=0; i<t; i++){
  		getline(cin, s);
  		a[i] = s;
    }

    for(int i=0; i<t; i++){
    	int n = 0;
		vector<pair<int, string>> v;
    	string t = "";
    	for(int j=0; j<a[i].size(); j++){
    		if(a[i][j] != ' ')
    			t += a[i][j];
    		else{
    			n++;
    			v.push_back(make_pair(t.size(), t));
    			t = "";
    		}

    		if(j == a[i].size()-1)
    			v.push_back(make_pair(t.size(), t));
    	}

    	sort(v.begin(), v.end());

    	for(int j=0; j<=n; j++)
    		cout << v[j].second << ' ';
    	cout << '\n';
    }
}