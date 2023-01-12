#include <iostream>
#include <cmath>

using namespace std;

void func(int n){
	bool is_prime[n];
	for(int i=0; i<n; i++)
		is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;

	for(int i=0; i * i <= n; i++){
		if(is_prime[i]){
			int j = 2*i;
			while(j <= n){
				is_prime[j] = false;
				j += i;
			}
		}
	}

	for(int i=0; i<n; i++)
		if(is_prime[i])
			cout << i << ' ';
}

int main(){
	int n;
	cin >> n;

	func(n);

	return 0;
}