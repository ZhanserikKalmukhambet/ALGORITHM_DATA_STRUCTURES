#include <bits/stdc++.h>

using namespace std;

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
	int help(){
		int res = 0;
		this->help(this->root, res);
		return res;
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

	void help(Node* cur, int& num){
		if(cur == NULL)
			return;

		help(cur->right, num);

		num += cur->val;
		cout << num << ' ';

		help(cur->left, num);
	}
};

int main(){	
	BST* bst = new BST();

	int n;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		bst->add(x);
	}

	bst->help();
}