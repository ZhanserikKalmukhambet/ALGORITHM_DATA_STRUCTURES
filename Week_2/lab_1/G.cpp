#include <bits/stdc++.h>

using namespace std;

#define N 1000005

int main(){
	bool is_composite[N];
	vector <int> primes;

	int ind = 1;
	for(int i=2; i<N; i++){
		if(!is_composite[i]){
			for(int j=2*i; j<N; j+=i)
				is_composite[j] = 1;
			primes.push_back(i);
		}
	}

	vector <int> super;

	for(int i=0; i<primes.size(); i++){
		if(!is_composite[i+1])
			super.push_back(primes[i]);
	}

	int n;
	cin >> n;
	cout << super[n];

	return 0;
}