#include <bits/stdc++.h>

using namespace std;

#define N 1000005

int main(){
	bool is_composite[N];
	vector <int> primes;

	is_composite[1] = true;
	for(int i=2; i<N; i++){
		if(!is_composite[i]){
			for(int j=2*i; j<N; j+=i)
				is_composite[j] = 1;
			primes.push_back(i);
		}
	}

	int n;
	cin >> n;
	
	if(!is_composite[n])
		cout << "YES";
	else
		cout << "NO";

	return 0;
}