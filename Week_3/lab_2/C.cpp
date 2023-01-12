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

	void deleteEachSecond(){
		if(head == NULL)
			return;

		Node* temp = head;
		while(temp != NULL && temp->next != NULL){
			Node* node = temp->next;
			temp->next = node->next;

			delete node;

			temp = temp->next;
		}
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

	int n, x;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		ll->insert(x);
	}

	ll->deleteEachSecond();

	ll->print();
}
