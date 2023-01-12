#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		deque <int> d;
		int cnt = n;

		for(int i=n; i>=1; i--){
			d.push_front(i);

			int tmp = cnt;
			while(tmp != 0){
				int zadnyi = d.back();
				d.pop_back();
				d.push_front(zadnyi);
				tmp--;
			}
			cnt--;
		}

		while(!d.empty()){
		cout << d.front() << ' ';
		d.pop_front();
		}
		cout << '\n';	
	}
}
