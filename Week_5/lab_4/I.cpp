#include <bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	int cnt;
	Node *left;
	Node *right;

	Node(int val){
		this->val = val;
		this->left = this->right = NULL;
		this->cnt = 0;
	}
};

struct BST{
public:
	Node *root;

	BST(){
		root = NULL;
	}

	void add(int val){
		Node* res = this->add(root, val);
		if(root == NULL)
			root = res;
	}

	void deleteNode(int val){
		this->deleteNode(root, val);
	}

	int getCnt(int val){
		Node* temp = find(root, val);

		if(temp == NULL)
			return 0;

		return temp->cnt;
	}

private:
	Node* add(Node* cur,int val){
		if(cur == NULL){
			cur = new Node(val);
			cur->cnt++;
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
		else{
			cur->cnt++;
		}

		return cur;
	}

	Node* find(Node* cur, int val){
		if(cur == NULL)
			return NULL;

		if(cur->val == val)
			return cur;

		if(val < cur->val)
			cur = cur->left;
		else
			cur = cur->right;

		return find(cur, val);
	}

	Node* findMin(Node* cur){
		if(cur == NULL)
			return NULL;

		while(cur->left != NULL)
			cur = cur->left;
		return cur;
	}

	void deleteNode(Node* cur, int val){
		if(cur == NULL)
			return;

		Node* temp = find(cur, val);
		if(temp != NULL && temp->cnt > 1){
			temp->cnt--;
			return;
		}

		temp->cnt = 0;
		if(temp->left == NULL && temp->right == NULL)
			temp = NULL;
		else if(temp->left)
			temp = temp->left;
		else if(temp->right)
			temp = temp->right;
		else{
			Node* minInRightSubtree = findMin(cur->right);
			temp->val = minInRightSubtree->val;
			deleteNode(temp->right, temp->val);
		}
	}
};

int main(){
	BST* bst = new BST();

	int n;
	cin >> n;

	while(n--){
		string q;
		int x;
		cin >> q >> x;

		if(q == "insert"){
			bst->add(x);
		}
		else if(q == "cnt"){
			cout << bst->getCnt(x) << '\n';
		}
		else{
			bst->deleteNode(x);
		}
	}
}
