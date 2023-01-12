#include <iostream>
#include <map>

using namespace std;

struct MaxHeap{
	int * a;
	int length;
	map <int, bool> m;

	MaxHeap(int capacity){
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

	int getMax(){
		return a[0];
	}
	int extractMax(){
		m[a[0]] = false;

		int rootVal = a[0];
		a[0] = a[length - 1];
		length--;

		if(length > 0)
			siftDown(0);

		return rootVal;
	}

	void insert(int val){
		if(m[val] == false){
			m[val] = true;

			a[length] = val;
			length++;
	
			siftUp(length - 1);
		}
	}

	void updateVal(int i, int newVal){
		int oldVal = a[i];
		a[i] = newVal;

		if(oldVal < newVal)
			siftDown(i);
		else
			siftUp(i);
	}

	void print(){
		for(int i=0; i<length; i++)
			cout << a[i] << ' ';
	}
};

int main(){
	MaxHeap hp(100);

	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		hp.insert(x);
	}

	for(int i=0; i<n; i++)
		cout << hp.extractMax() << ' ';
}