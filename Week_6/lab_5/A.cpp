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

	ll extractMin(){
		ll rootVal = a[0];

		a[0] = a[length - 1];
		length--;

		if(length > 0)
			siftDown(0);

		return rootVal;
	}

	ll getTwoMin(){
		ll num = 0;
		num += extractMin();
		num += extractMin();

		insert(num);
		return num;
	}
};

int main(){
	MinHeap hp(2 * 1e5 + 10);

	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		ll x;
		cin >> x;
		hp.insert(x);
	} // in worst case O(nlogn)

	ll res = 0;
	while(n-1 != 0){
		res += hp.getTwoMin();
		n--;
	} // n * (2*logn + logn) = n * 3logn = nlogn

	cout << res;
	return 0;
}