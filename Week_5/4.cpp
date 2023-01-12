#include <bits/stdc++.h>

using namespace std;

// bfs

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

	vector<vector<int>> bfs(){
		if(root == NULL)
			return {{}};

		vector<vector<int>> res;

		queue <Node*> q;
		q.push(root);
		res.push_back({root->val});

		while(!q.empty()){
			int sz = q.size();

			vector<int> init;
			for(int i=0; i<sz; i++){
				Node* temp = q.front();
				q.pop();

				if(temp->left){
					init.push_back(temp->left->val);
					q.push(temp->left);
				}
				if(temp->right){
					init.push_back(temp->right->val);
					q.push(temp->right);
				}
			}
			if(init.size() != 0)
				res.push_back(init);
		}

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
};

int main(){
	BST *bst = new BST();

	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		bst->add(x);
	}
	
	vector<vector<int>> res = bst->bfs();
	int ind = 1;
	for(auto v : res){
		cout << "At level " << ind++ << " --> ";
		for(auto num : v)
			cout << num << ' ';
		cout << '\n';
	}
}