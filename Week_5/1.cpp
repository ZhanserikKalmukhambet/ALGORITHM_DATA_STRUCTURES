#include <bits/stdc++.h>

using namespace std;

// baisakov's code

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

	void print(Node* cur){
		if(cur == NULL)
			return;

		print(cur->left);
		cout << cur->val << ' ';
		print(cur->right);
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

	bst->print();
	return 0;
}