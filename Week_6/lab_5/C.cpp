#include <iostream>

using namespace std;

using ll = long long;

struct MaxHeap{
	int * a;
	int capacity;
	int length;

	MaxHeap(int capacity){
		this->capacity = capacity;
		a = new int[capacity];
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

	void insert(int val){
		a[length] = val;
		length++;

		siftUp(length - 1);
	}

	int getMoreMoney(){
		int maxProfit = a[0];

		a[0]--;
		siftDown(0);

		return maxProfit;
	}
};

int main(){
	MaxHeap hp(1e5 + 10);

	int n, x;
	cin >> n >> x;
	for(int i=0; i<n; i++){
		int sz;
		cin >> sz;
		hp.insert(sz);
	}

	ll money = 0;
	while(x != 0){
		money += hp.getMoreMoney();
		x--;
	}	

	cout << money;
}