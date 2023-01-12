#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool satisfy(ll x, ll y, ll r, ll par){
	double temp = sqrt(x*x + y*y);

	return temp + r > par;
}

int main(){
	int t;
	cin >> t;

	for(int i=0; i<t; i++){
		ll sphere, house;
		cin >> sphere >> house;

		ll n, cntRed = 0;
		cin >> n;
		for(ll j=0; j<n; j++){
			ll x, y;
			cin >> x >> y;

			if(satisfy(x, y, sphere, house))
				cntRed++;
		}

		ll m, cntYel = 0;
		cin >> m;
		for(ll j=0; j<m; j++){
			ll x,y;
			cin >> x >> y;

			if(satisfy(x, y, sphere, house))
				cntYel++;
		}

		cout << "Case #" << i+1 << ": ";
		if(cntRed > cntYel)
			cout << cntRed - cntYel << ' ' << 0;
		else
			cout << 0 << ' ' << cntYel - cntRed;
		cout << '\n';
	}
}