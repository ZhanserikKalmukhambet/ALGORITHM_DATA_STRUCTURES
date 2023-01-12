#include <iostream>

using namespace std;

struct Node{
	int val;
	int ind;
	Node* next;

	Node(int val){
		this->val = val;
		this->next = NULL;
	}
};

struct LL{
	Node* head;
	Node* tail;
	int cnt;

	LL(){
		cnt = 0;
		head = tail = NULL;
	}

	void insert(int val){
		Node* node = new Node(val);
		node->ind = cnt;

		if(head == NULL){
			head = node;
			tail = node;
		}
		else{
			tail->next = node;
			tail = node;
		}

		cnt++;
	}

	void print(){
		Node* cur = head;
		while(cur != NULL){
			cout << cur->val << ' ';
			cur = cur->next;
		}
	}

	int nearestDist(int k){
		Node* cur = head;
		int dist = 1e8, res;
		while(cur != NULL){
			if(abs(cur->val - k) < dist){
				dist = abs(cur->val - k);
				res = cur->ind;
			}
			cur = cur->next;
		}
		return res;
	}
};

int main(){
	LL ll;
	int n, x;
	cin >> n;
	while(n--){
		cin >> x;
		ll.insert(x);
	}

	int k;
	cin >> k;

	cout << ll.nearestDist(k);
	return 0;
}