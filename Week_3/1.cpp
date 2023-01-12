#include <iostream>

using namespace std;

struct Node{
	int val;
	Node* next;

	Node(int val){
		this->val = val;
		this->next = NULL;
	}
};

struct LL{
	Node* head;
	Node* tail;
	int size = 0;

	LL(){
		size = 0;
		head = tail = NULL;
	}

	void insert(int val){
		Node* node = new Node(val);
		if(head == NULL){
			head = node;
			tail = node;
		}
		else{
			tail->next = node;
			tail = node;
		}

		size++;
	}

	void print(){
		Node* cur = head;
		while(cur != NULL){
			cout << cur->val << ' ';
			cur = cur->next;
		}
	}

	void reverse(){
		Node* prev = NULL;
		while(head != NULL){
			Node* next_node = head->next;
			head->next = prev;
			prev = head;
			head = next_node;
		}
		head = prev;
	}

	int findMid(){
		Node* slow = head;
		Node* fast = head;

		while(fast != NULL && fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow->val;
	}

	void cyclicLeftShift(int k){
		if(k == 1)
			return;

		Node* cur = head;
		
		while(k != 1){
			tail->next = cur;
			tail = cur;
			cur = cur->next;
			k--;
		}
		head = cur->next;
		cur->next = NULL;	
	}

	void cyclicRightShift(int k){
		this->cyclicLeftShift(size - k);
	}
};

int main(){
	LL ll;

	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		ll.insert(x);
	}

	// ll.reverse();
	ll.print();

	cout << '\n' << ll.findMid() << '\n';

	cout << ll.size << '\n';

	return 0;
}