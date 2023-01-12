#include <bits/stdc++.h>

using namespace std;

struct Node{
	char val;
	Node* next;

	Node(char val){
		this->val = val;
		next = NULL;
	}
};

struct LinkedList{
	Node* head;

	LinkedList(){
		head = NULL;
	}

	void insert(char val){
		Node* node = new Node(val);

		if(head == NULL){
			head = node;
			return;
		}

		Node*temp = head;
		while(temp->next != NULL)
			temp = temp->next;

		temp->next = node;
	}

	int leftMost(){
		int a[26];
		for(int i=0; i<26; i++)
			a[i] = 0;

		for(Node*temp = head; temp != NULL; temp=temp->next)
			a[temp->val - 97]++;

		for(Node*temp = head; temp != NULL; temp=temp->next){
			if(a[temp->val - 97] == 1)
				return temp->val;
		}
		return -1;
	}
};

int main(){

	int t;
	cin >> t;

	for(int j=0; j<t; j++){
		int n;
		cin >> n;

		LinkedList* ll = new LinkedList();
		for(int i=0; i<n; i++){
			char c;
			cin >> c;
			ll->insert(c);

			if(ll->leftMost() != -1)
				cout << char(ll->leftMost()) << ' ';
			else
				cout << ll->leftMost() << ' ';
		}
		cout << '\n';
	}
}