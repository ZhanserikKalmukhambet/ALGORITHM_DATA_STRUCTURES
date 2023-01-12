#include <bits/stdc++.h>

using namespace std;

// invert bin tree - reverse each level

struct Node{
	Node* left;
	Node* right;
	int val;

	Node(int val){
		this->val = val;
		this->left = this->right = NULL;
	}
};

struct BST{
public:
	BST(){
		root = NULL;
	}

	void add(int val){
		Node* res = add(this->root, val);
		if(root == NULL)
			root = res;
	}
	void print(){
		this->print(this->root);
	}
	void invert(){
		invert(this->root);
	}

protected:
	Node* root;

	Node* add(Node* cur, int val){
		if(cur == NULL){
			cur = new Node(val);
		}
		else if(val < cur->val){
			if(cur->left == NULL)
				cur->left = add(cur->left, val);
			else
				add(cur->left, val);
		}
		else if(val > cur->val){
			if(cur->right == NULL)
				cur->right = add(cur->right, val);
			else
				add(cur->right, val);
		}

		return cur;
	}

	void invert(Node* cur){
		if(cur == NULL)
			return;

		Node* temp = cur->left;
		cur->left = cur->right;
		cur->right = temp;

		invert(cur->left);
		invert(cur->right);
	}
};

int main(){
	BST *bst = new BST();

	int n, x;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		bst->add(x);
	}	
}