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
	void print(){
		this->print(this->root);
	}
	string help(Node* cur, string s){
		for(int i=0; i<s.size(); i++){
			if(cur == NULL)
				return "NO";

			if(s[i] == 'L')
				cur = cur->left;
			else
				cur = cur->right;
		}

		if(cur == NULL)
			return "NO";

		return "YES";
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

	int n, m, x;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> x;
		bst->add(x);
	}

	for(int i=0; i<m; i++){
		string s;
		cin >> s;
		cout << bst->help(bst->root, s) << '\n';
	}
}
