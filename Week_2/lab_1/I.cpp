#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string s;
	cin >> n >> s;

	if(n == 1){
		if(s[0] == 'S')
			cout << "SAKAYANAGI";
		else
			cout << "KATSURAGI";
		return 0;
	}

	int died[n];
	vector <int> ss, kk;

	for(int i=0; i<n; i++){
		if(s[i] == 'S')
			ss.push_back(i);
		else
			kk.push_back(i);
	}

	bool stop = false;
	int s_i = 0, k_i = 0;
	while(!stop){
		for(int i=0; i<n; i++){
			if(!died[i]){
				if(s[i] == 'S'){
					died[kk[k_i]] = 1;
					k_i++;

					if(k_i == kk.size()){
						stop = true;
						break;
					}
				}
				else{
					died[ss[s_i]] = 1;
					s_i++;

					if(s_i == ss.size()){
						stop = true;
						break;
					}
				}
			}
		}
	}

	if(s_i == ss.size())
		cout << "KATSURAGI";
	if(k_i == kk.size())
		cout << "SAKAYANAGI";
}