#include <iostream>

using namespace std;

using ll = long long;

struct MinHeap{
	ll * a;
	int capacity;
	int length;
	int sum;

	MinHeap(int capacity){
		this->capacity = capacity;
		a = new ll[capacity];
		length = 0;
		sum = 0;
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
		int maxPos = i;

		if(left(i) < length && a[left(i)] < a[maxPos])
			maxPos = left(i);
		if(right(i) < length && a[right(i)] < a[maxPos])
			maxPos = right(i);

		if(i != maxPos){
			swap(a[i], a[maxPos]);
			siftDown(maxPos);
		}
	}

	void insert(ll val){
		if(length == capacity){
			if(val > a[0]){
				this->sum -= a[0];
				a[0] = val;
				this->sum += a[0];

				siftDown(0);
			}
			return;
		}

		a[length] = val;
		length++;
		this->sum += val;

		siftUp(length - 1);
	}


};

int main(){
	ll q, k;
	cin >> q >> k;

	MinHeap hp(k);

	while(q--){
		string s;
		cin >> s;
		if(s == "print"){
			cout << hp.sum << '\n';
		}
		else{
			ll val;
			cin >> val;
			hp.insert(val);
		}
	}	
}