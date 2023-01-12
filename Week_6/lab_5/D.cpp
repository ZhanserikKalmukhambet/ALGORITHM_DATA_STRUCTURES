#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct MinHeap{
	ll * a;
	int capacity;
	int length;

	MinHeap(int capacity){
		this->capacity = capacity;
		a = new ll[capacity];
		length = 0;
	}

	int left(int i){
			return 2*i + 1;
		}
	int right(int i){
		return 2*i + 2;
	}
	int parent(int i){
		return (i - 1) / 2;
	}

	void siftUp(int i){
		if(i > 0 && a[parent(i)] > a[i]){
			swap(a[i], a[parent(i)]);
			siftUp(parent(i));
		}
	}

	void siftDown(int i){
		int minPos = i;

		if(left(i) < length && a[left(i)] < a[minPos])
			minPos = left(i);
		if(right(i) < length && a[right(i)] < a[minPos])
			minPos = right(i);

		if(i != minPos){
			swap(a[i], a[minPos]);
			siftDown(minPos);
		}
	}

	void insert(ll val){
		a[length] = val;
		length++;

		siftUp(length - 1);
	}

	ll getMin(){
		return a[0];
	}

	ll extractMin(){
		ll rootVal = a[0];

		a[0] = a[length - 1];
		length--;

		if(length > 0)
			siftDown(0);

		return rootVal;
	}

	void mixture(){
		int a = this->extractMin();
		int b = this->extractMin();
		this->insert(a + 2*b);
	}	
};

int main(){
	MinHeap hp(1e6 + 10);

	int n;
	ll m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		ll x;
		cin >> x;
		hp.insert(x);
	}
		
	int cnt = 0;
	while(hp.getMin() < m && hp.length > 0){
		hp.mixture();
		cnt++;
	}

	if(hp.length == 0)
		cout << -1;
	else
		cout << cnt;
}