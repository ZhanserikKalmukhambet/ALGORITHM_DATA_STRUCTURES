#include <bits/stdc++.h>

using namespace std;

// AVL

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

	int balance_factor(Node* cur){
		if(cur == NULL)
			return 0;

		int l = balance_factor(cur->left), r = balance_factor(cur->right);

		return r - l;
	}

	Node* left_rotation(Node* cur){
		Node* tempright = cur->right;
		cur->right = tempright->left;
		tempright->left = cur;

		return tempright;
	} 
	Node* right_rotation(){
		Node* templeft = cur->left;
		cur->left = templeft->right;
		templeft->right = cur;

		return templeft;
	}
	Node* left_right_rotation(Node* cur){
		cur->left = left_rotation(cur->left);

		return right_rotation(cur);
	}
	Node* right_left_rotation(Node* cur){
		cur->right = right_rotation(cur->right);

		return left_rotation(cur);
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

	void inOrder(Node* cur){
		if(cur == NULL)
			return;

		inOrder(cur->left);
		inOrder(cur->right);

		if(!(-1 < balance_factor(cur) && balance_factor(cur) < 1)){
			// call left_rotation
			// call right_rotation
			// call left_right rotation
			// call right-left rotation
		}
	}
};

int main(){
	BST *bst = new BST();


}