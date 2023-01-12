#include <bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	int cnt;
	Node* next;

	Node(int val){
		this->val = val;
		this->cnt = 0;
		this->next = NULL;
	}
};

struct LL{
	Node* head;
	int mostFreq;

	LL(){
		head = NULL;
		mostFreq = 1;
	}

	void insert(int val){
		Node* node = new Node(val);
		if(head == NULL){
			head = node;
			node->cnt++;
			return;	
		}

		Node* cur = head;
		while(cur->next != NULL){
			if(cur->val == val){
				cur->cnt++;
				mostFreq = max(mostFreq, cur->cnt);
				return;
			}
			cur = cur->next;
		}

		if(cur->val == val){
			cur->cnt++;
			mostFreq = max(mostFreq, cur->cnt);
			return;
		}
		cur->next = node;
		node->cnt++;
		mostFreq = max(mostFreq, node->cnt);
	}

	vector<int> printRes(){
		vector <int> v;

		Node* cur = head;
		while(cur != NULL){
			if(cur->cnt == mostFreq)
				v.push_back(cur->val);
			cur = cur->next;
		}
		return v;
	}
};

int main(){
	LL ll;

	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		ll.insert(x);
	}

	vector <int> res = ll.printRes();
	if(res.size() > 1)
		sort(res.begin(), res.end());

	for(int i=res.size()-1; i>=0; i--)
		cout << res[i] << ' ';
}