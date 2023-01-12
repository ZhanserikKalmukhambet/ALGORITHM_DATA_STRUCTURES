#include <bits/stdc++.h>

using namespace std;

struct Node{
	Node* left;
	Node* right;
	int val;

	Node(int val){
		this->left = this->right = NULL;
		this->val = val;
	}
};

struct BST{
public:
	Node* root;

	BST(){
		root = NULL;
	}

	void add(int val){
		Node* res = this->add(root, val);

		if(root == NULL)
			root = res;
	}
	void print(){
		this->print(root);
	}
	Node* find(Node* cur, int target){
		if(cur->val == target)
			return cur;

		if(target < cur->val)
			cur = cur->left;
		else
			cur = cur->right;

		return find(cur, target);
	}
	void postOrder(Node* cur){
		if(cur == NULL)
			return;

		cout << cur->val << ' ';
		postOrder(cur->left);
		postOrder(cur->right);
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

	int target;
	cin >> target;
	
	Node* nodeOfTarget = bst->find(bst->root, target);

	bst->postOrder(nodeOfTarget);

	return 0;
}