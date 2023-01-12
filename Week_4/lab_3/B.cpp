#include <iostream>

using namespace std;

using ll = long long;

ll getMax(ll a[], ll n){
	ll maxx = a[0];
	for(ll i=0; i<n; i++)
		if(maxx < a[i])
			maxx = a[i];
	return maxx;
}

ll getSum(ll a[], ll n){
	ll sum = 0;
	for(ll i=0; i<n; i++)
		sum += a[i];
	return sum;
}

bool canSplit(ll a[], ll n, ll k, ll mid){
	ll cnt = 1;
	ll curSum = 0;
	for(ll i=0; i<n; i++){
		curSum += a[i];

		if(curSum > mid){
			cnt++;
			curSum = a[i];
		}
	}
	return cnt <= k;
}

ll bin_search(ll a[], ll n, ll k){
	ll l = getMax(a, n), r = getSum(a, n), res;

	while(l <= r){
		ll mid = (l + r) / 2;

		if(canSplit(a, n, k, mid)){
			res = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1; 
		}
	}

	return res;
}

int main(){
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for(ll i=0; i<n; i++)
		cin >> a[i];

	cout << bin_search(a, n, k);

	return 0;
}