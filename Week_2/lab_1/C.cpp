#include <bits/stdc++.h>

using namespace std;

stack<char> help(string s){
	stack <char> st;

	for(int i=0; i<s.size(); i++){
		if(s[i] != '#')
			st.push(s[i]);
		else{
			if(st.size() > 0)
				st.pop();
		}	
	}

	return st;
}

int main(){
	string s1, s2;
	cin >> s1 >> s2;

	if(help(s1) == help(s2))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}