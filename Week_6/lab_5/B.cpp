#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct MaxHeap{
	ll * a;
	int capacity;
	int length;

	MaxHeap(int capacity){
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
		if(i > 0 && a[parent(i)] < a[i]){
			swap(a[i], a[parent(i)]);
			siftUp(parent(i));
		}
	}

	void siftDown(int i){
		int maxPos = i;

		if(left(i) < length && a[left(i)] > a[maxPos])
			maxPos = left(i);
		if(right(i) < length && a[right(i)] > a[maxPos])
			maxPos = right(i);

		if(i != maxPos){
			swap(a[i], a[maxPos]);
			siftDown(maxPos);
		}
	}

	void insert(ll val){
		a[length] = val;
		length++;

		siftUp(length - 1);
	}

	ll extractMax(){
		ll rootVal = a[0];

		a[0] = a[length - 1];
		length--;

		if(length > 0)
			siftDown(0);

		return rootVal;
	}

	void getTwoMax(){
		int a = extractMax();
		int b = extractMax();

		if(a == b)
			return;

		insert(abs(a - b));
	}
};

int main(){
	MaxHeap hp(1e5 + 10);

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		ll x;
		cin >> x;
		hp.insert(x);
	} // in worst case O(nlogn)

	while(hp.length > 1){
		hp.getTwoMax();
	}

	if(hp.length == 0)
		cout << 0;
	else
		cout << hp.a[0];

	return 0;
}