#include <iostream>
#include <vector>

using namespace std;

vector<int> p_f(string s){
	int n = s.size();
	vector <int> p(n);
	p[0] = 0;

	for(int i=1; i<n; i++){
		int j = p[i-1];

		while(j > 0 && s[i] != s[j])
			j = p[j-1];

		if(s[i] == s[j])
			j++;

		p[i] = j;
	}
	return p;
}

int main(){
	string s;
	cin >> s;

	vector <int> p = p_f(s);
	
	cout << s.size() - p[s.size()-1];
}