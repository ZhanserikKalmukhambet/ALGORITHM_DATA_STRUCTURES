#include <bits/stdc++.h>

using namespace std;

class Node{
public:
	Node* next;
	int val;

	Node(int val){
		this->val = val;
		next = NULL;
	}
};

class LinkedList{
public:
	Node* head;
	
	LinkedList(){
		head = NULL;
	}

	void insert(int val){
		Node* node = new Node(val);

		if(head == NULL){
			head = node;
			return;
		}

		Node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}

		temp->next = node;
	}

	void rechange(int newVal, int pos){
		Node* node = new Node(newVal);
		if(pos == 0){
			node->next = head;
			head = node;
			return;
		}

		Node* temp = head;
		while(pos != 1){
			pos--;
			temp = temp->next;
		}

		node->next = temp->next;
		temp->next = node;
	}

	void print(){
		while(head != NULL){
			cout << head->val << ' ';
			head = head->next;
		}
	}
};

int main(){
	LinkedList* ll = new LinkedList();

	int n, x, data, pos;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		ll->insert(x);
	}

	cin >> data >> pos;
	ll->rechange(data, pos);

	ll->print();
}
