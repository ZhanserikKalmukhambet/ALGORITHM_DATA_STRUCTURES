#include <iostream>

using namespace std;

const int N = 1e5;

struct Deque{
	int a[N];
	int st;
	int end;

	Deque(){
		st = end = N / 2;
	}

	void push_front(int x){
		st--;
		a[st] = x;
	}
	void push_back(int x){
		a[end] = x;
		end++;
	}
	int front(){
		return a[st];
	}
	int back(){
		return a[end-1];
	}
	void pop_front(){
		st++;
	}
	void pop_back(){
		end--;
	}
	int size(){
		return end - st;
	}
	void clear(){
		st = end = N/2;
	}
	bool empty(){
		return size() == 0;
	}
};

int main(){
	Deque deq;

	deq.push_back(10);
	deq.push_back(20);	
	deq.push_front(0);
	deq.push_front(-10);

	cout << deq.size() << endl;
	cout << deq.front() << endl;
	cout << deq.back() << endl;
}