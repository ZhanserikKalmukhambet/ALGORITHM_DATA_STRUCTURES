#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector <int> primes;
	bool is_composite[n+1];

	for(int i=2; i<=n; i++){
		if(!is_composite[i]){
			for(int j=2*i; j<=n; j+=i)
				is_composite[j] = 1;
			primes.push_back(i);
		}
	}

	for(int i=0; i<primes.size(); i++)
		cout << primes[i] << ' ';
}

