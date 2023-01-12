#include <bits/stdc++.h>

using namespace std;

queue<int> help(){
	queue <int> q;
	int x;
	for(int i=0; i<5; i++){
		cin >> x;
		q.push(x);
	}
	return q;
}

int main(){
	queue <int> q1 = help(), q2 = help();

	int cnt = 0;
	bool ok = true;
	while(!q1.empty() && !q2.empty()){
		if(cnt >= 1e6){
			ok = false;
			break;
		}

		int x1 = q1.front();
		int x2 = q2.front();
		q1.pop();
		q2.pop();
		cnt++;

		if(x1 == 0 && x2 == 9){
			q1.push(x1);
			q1.push(x2);
		}
		else if(x1 == 9 && x2 == 0){
			q2.push(x1);
			q2.push(x2);
		}
		else{
			if(x1 > x2){
				q1.push(x1);
				q1.push(x2);
			}
			else{
				q2.push(x1);
				q2.push(x2);
			}
		}
	}

	if(q1.empty())
		cout << "Nursik" << ' ' << cnt;
	if(q2.empty())
		cout << "Boris" << ' ' << cnt;
	if(!ok)
		cout << "blin nichya";

	return 0;
}