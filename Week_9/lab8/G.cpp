#include <iostream>
#include <climits>

using namespace std;

long long q = LONG_LONG_MAX;

int findCntAppearance(long long * hash, int n, long long * p_pow, int l, int r){
	int m = r - l + 1, cnt = 0;

	long long h = hash[r];
	if(l)
		h -= hash[l-1];

	for(int i=0; i<n-m+1; i++){
		long long temp = hash[i + m - 1];
		if(i)
			temp -= hash[i-1];

		if(temp * p_pow[n - 1 - i] == h * p_pow[n - 1 - l])
			cnt++;
	}

	return cnt;
}

int main(){
	string s;
	cin >> s;

	int n = s.size();
		
	int p = 31;
	long long p_pow[n];
	p_pow[0] = 1;
	for(int i=1; i<n; i++)
		p_pow[i] = (p_pow[i-1] * p) % q;

	long long hash[n];
	for(int i=0; i<n; i++){
		hash[i] = ((s[i] - 'a' + 1) * p_pow[i]) % q;
		if(i)
			hash[i] += hash[i-1];
	}

	int t, l, r;
	cin >> t;
	while(t--){
		cin >> l >> r;
		l--; r--;

		cout << findCntAppearance(hash, n, p_pow, l, r) << '\n';
	}	
}