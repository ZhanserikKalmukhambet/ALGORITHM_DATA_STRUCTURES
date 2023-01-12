#include <iostream>

using namespace std;

struct Node{
	string val;
	Node* next;

	Node(string val){
		this->val = val;
		this->next = NULL;
	}
};

struct LL{
	Node* head;
	Node* tail;

	LL(){
		head = tail = NULL;
	}

	void insert(string val){
		Node* node = new Node(val);
		if(head == NULL){
			head = node;
			tail = node;
		}
		else{
			tail->next = node;
			tail = node;
		}
	}

	void cyclicShift(int k){
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

	void print(){
		Node* cur = head;
		while(cur != NULL){
			cout << cur->val << ' ';
			cur = cur->next;
		}
	}
};

int main(){
	LL ll;

	int n, k;
	cin >> n >> k;
	while(n--){
		string s;
		cin >> s;
		ll.insert(s);
	}

	ll.cyclicShift(k);
	ll.print();
}