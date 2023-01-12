#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, order = 1;
	cin >> t;

	while(t--){
		int n;
		cin >> n;
		int a[n];
		int sum = 0;

		for(int i=0; i<n; i++)
			cin >> a[i];

		int i = 0;
		while(i < n){
			int curSum = 0;
			for(int j=i; j<n; j++){
				curSum += a[j];

				if(curSum < 0){
					i = j;
					break;
				}
				else{
					sum += curSum;
				}
			}

			i++;
		}

		cout << "Case #" << order << ": " << sum << '\n';
		order++;
	}
}