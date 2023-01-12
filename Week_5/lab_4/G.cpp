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
		Node* res = add(root, val);
		if(root == NULL)
			root = res;
	}

	int diameter(){
		int res = 0;
		diameter(this->root, res);
		return res;
	}

private:
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

	int diameter(Node* cur, int &res){
		if(cur == NULL)
			return 0;

		int l = diameter(cur->left, res), r = diameter(cur->right, res);

		res = max(res, l + r + 1);

		return max(l, r) + 1;
	}
};

int main(){
	BST* bst = new BST();

	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		bst->add(x);
	}

	cout << bst->diameter();

	return 0;
}