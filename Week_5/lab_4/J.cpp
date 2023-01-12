// 

struct Node{
	int val;
	Node* left;
	Node* right;

	Node(int val){
		this->val = val;
		left = right = NULL;
	}
};

Node* root = NULL;

void arrayToBST(int * a, int n, int l, int r){
	if(l > r)
		return;

	int mid = (l + r) / 2;
	Node* root = new Node(a[mid]);
	root->left = arrayToBST(a, n, 0, mid-1);
	root->right = arrayToBST(a, n, mid+1, n);
}

int main(){
	int n;
	cin >> n;

	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	sort(a, a + n);

	arrayToBST(a, n, 0, n-1);

	
}