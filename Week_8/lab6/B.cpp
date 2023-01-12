#include <iostream>

using namespace std;

int partition(int * a, int low, int high){
	int i = low - 1;
	int pivot = high;
	for(int j=low; j<=high-1; j++){
		if(a[j] < a[pivot]){
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i+1], a[pivot]);

	return i + 1;
}

void quickSort(int * a, int low, int high){
	if(low < high){
		int pos = partition(a, low, high);
		quickSort(a, low, pos-1);
		quickSort(a, pos+1, high);
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	int b[m];
	for(int i=0; i<m; i++)
		cin >> b[i];

	quickSort(a, 0, n-1);
	quickSort(b, 0, m-1);

	int p1 = 0, p2 = 0;
	while(p1 != n && p2 != m){
		if(a[p1] < b[p2])
			p1++;
		else if(a[p1] > b[p2])
			p2++;
		else{
			cout << a[p1] << ' ';
			p1++;
			p2++;
		}
	}
}