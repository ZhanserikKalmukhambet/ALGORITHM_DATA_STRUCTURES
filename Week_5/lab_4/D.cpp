#include <bits/stdc++.h>

using namespace std;

int get_sum(vector <int> v){
	int sum = 0;
	for(int num : v)
		sum += num;
	return sum;
}

struct Node{
	int val;
	Node* left;
	Node* right;

	Node(int val){
		this->val = val;
		left = right = NULL;
	}
};

struct BST{
	Node* root;

	BST(){
		root = NULL;
	}

	Node* insert(Node* cur, int val){
		if(cur == NULL){
			cur = new Node(val);
		}
		else if(val <= cur->val){
			if(cur->left == NULL)
				cur->left = insert(cur->left, val);
			else
				insert(cur->left, val);
		}
		else{
			if(cur->right == NULL)
				cur->right = insert(cur->right, val);
			else
				insert(cur->right, val);
		}

		return cur;
	}

	vector<vector<int>> bfs(Node* cur){

		queue <Node*> q;
		q.push(cur);
		vector<vector<int>> general;
		general.push_back({cur->val});
		while(!q.empty()){
			int sz = q.size();

			vector <int> v;
			for(int i=0; i<sz; i++){
				Node* temp = q.front();
				q.pop();

				if(temp->left){
					q.push(temp->left);
					v.push_back(temp->left->val);
				}
				if(temp->right){
					q.push(temp->right);
					v.push_back(temp->right->val);
				}
			}

			if(v.size() != 0)
				general.push_back(v);
		}

		return general;
	}
};

int main(){
	BST * bst = new BST();

	int n, x;
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> x;

		bst->root = bst->insert(bst->root, x);
	}

	vector <vector<int>> res = bst->bfs(bst->root);

	cout << res.size() << '\n';
	for(int i=0; i<res.size(); i++){
		cout << get_sum(res[i]) << ' ';
	}
	return 0;
}