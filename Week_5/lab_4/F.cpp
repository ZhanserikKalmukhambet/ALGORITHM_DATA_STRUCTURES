#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

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
	Node* root;

	BST(){
		root = NULL;
	}

	void add(int val){
		Node* res = add(this->root, val);
		if(root == NULL)
			root = res;
	}

	void inOrder(){
		this->inOrder(root);
	}

protected:
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

	void inOrder(Node* cur){
		if(cur->left && cur->right)
			cnt++;

		if(cur->left)
			inOrder(cur->left);
		if(cur->right)
			inOrder(cur->right);
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

	bst->inOrder();	

	cout << cnt;
}