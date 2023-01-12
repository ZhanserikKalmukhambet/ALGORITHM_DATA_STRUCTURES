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
	Node* root;

	BST(){
		root = new Node(1);
	}

	int bfs(){
		queue <Node*> q;
		q.push(root);
		int res = 0;

		while(!q.empty()){
			int sz = q.size();
			res = max(res, sz);

			for(int i=0; i<sz; i++){
				Node* temp = q.front();
				q.pop();

				if(temp->left)
					q.push(temp->left);
				if(temp->right)
					q.push(temp->right);
			}
		}

		return res;
	}

	void insert(Node* node, int where, int val, int left){
		if(node == NULL)
			return;

		if(node->val == where){
			if(left == 0)
				node->left = new Node(val);
			else
				node->right = new Node(val);
			return;
		}

		insert(node->left, where, val, left);
		insert(node->right, where, val, left);
	}
};

int main(){
	BST *bst = new BST();

	int n;
	cin >> n;
	n--;
	while(n--){
		int x, y, z;
		cin >> x >> y >> z;

		bst->insert(bst->root, x, y, z);
	}

	cout << bst->bfs();

	return 0;
}
