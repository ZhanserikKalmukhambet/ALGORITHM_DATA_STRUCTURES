#include <iostream>
#include <map>

using namespace std;

struct MinHeap{
	int * a;
	int length;
	map <int, bool> m;

	MinHeap(int capacity){
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

	int getMin(){
		return a[0];
	}
	int extractMin(){
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
	MinHeap hp(100);

	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		hp.insert(x);
	}

	hp.print();
	cout << '\n';

	for(int i=0; i<n; i++)
		cout << hp.extractMin() << ' ';
}