#include <iostream>

using namespace std;

struct Stack{
	int a[100000];
	int end;

	Stack(){
		end = 0;
	}

	void push(int x){
		a[end] = x;
		end++;
	}
	int top(){
		return a[end-1];
	}
	void pop(){
		if(end == 0)
			return;
		end--;
	}
	int size(){
		return end;
	}
	bool empty(){
		return end == 0;
	}
	void clear(){
		end = 0;
	}
};	

int main(){
	Stack st;
	int x;
	while(cin >> x){
		if(x == 0)
			break;
		st.push(x);
	}

	// while(!st.empty()){
	// 	cout << st.top() << ' ';
	// 	st.pop();
	// }

	cout << st.empty() << '\n';
	cout << st.size() << '\n';
	cout << st.top() << '\n';
	st.pop();
	st.pop();
	cout << st.size() << '\n';
	cout << st.top() << '\n';
}