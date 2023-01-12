#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;

	int p = 2;
	long long p_pow[n];
	p_pow[0] = 1;
	for(int i=1; i<n; i++)
		p_pow[i] = p * p_pow[i-1];

	char a[n];
	long long temp = 0;
	for(int i=0; i<n; i++){
		long long x;
		cin >> x;

		a[i] = char((x - temp) / p_pow[i] + 97);
		temp = x;
	}

	for(int i=0; i<n; i++)
		cout << a[i];

	return 0;
}