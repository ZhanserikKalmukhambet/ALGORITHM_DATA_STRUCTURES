#include <bits/stdc++.h>

using namespace std;

// merge two binary trees

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

	Node* merge(Node* t1, Node* t2){
		if(!t1 && !t2)
			return NULL;

		int t1_val, t2_val;
		if(t1)
			t1_val = t1->val;
		else
			t1_val = 0;

		if(t2)
			t2_val = t2->val;
		else
			t2_val = 0;

		Node* root = new Node(t1_val + t2_val);
		root->left = merge(t1->left, t1->right);
		root->right = merge(t2->left, t2->right);

		return root;
	}
};

int main(){
	BST *bst1 = new BST();
	BST *bst2 = new BST();

	int n, x;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		bst1->add(x);
		bst2->add(x);
	}

		
}