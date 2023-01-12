#include <bits/stdc++.h>

using namespace std;

int main(){
	deque <int> d;

	char sign;
	int x;

	while(true){
		cin >> sign;
		if(sign == '!')
			break;
		else if(sign == '*'){
			if(d.size() >= 2){
				cout << d.front() + d.back() << '\n';
				d.pop_back();
				d.pop_front();
			}
			else{
				if(d.size() == 1){
					cout << d.front() + d.back() << '\n';
					d.pop_back();
				}
				else
					cout << "error" << '\n';
			}
		}
		else{
			cin >> x;

			if(sign == '+')
				d.push_front(x);
			else
				d.push_back(x);
		}
	}
}