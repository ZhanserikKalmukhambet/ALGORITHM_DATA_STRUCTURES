#include <iostream>

using namespace std;

struct Node{
	int val;
	Node* next;
	Node* prev;

	Node(int val){
		this->val = val;
		prev = next = NULL;
	}
};

struct DLL{
	Node* head;
	Node* tail;

	DLL(){
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
			node->prev = tail;
			tail = node;
		}
	}

	void print(){
		Node* cur = head;
		while(cur != NULL){
			cout << cur->val << ' ';
			cur = cur->next;
		}
	}

	void rprint(){
		Node* cur = tail;
		while(cur != NULL){
			cout << cur->val << ' ';
			cur = cur->prev;
		}
	}
};

int main(){
	DLL dll;

	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		dll.insert(x);
	}

	dll.print();
	cout << '\n';
	dll.rprint();
}