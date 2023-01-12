#include <iostream>

using namespace std;

string s;

int partition(int * a, int low, int high){
	int i = low - 1;
	int pivot = high;

	for(int j=low; j<=high-1; j++){
		if(a[j] < a[pivot]){
			i++;
			swap(a[i], a[j]);
			swap(s[i], s[j]);
		}
	}
	swap(a[i+1], a[pivot]);
	swap(s[i+1], s[pivot]);

	return i + 1;
}

void quickSort(int * a, int low, int high){
	if(low < high){
		int pos = partition(a, low, high);
		quickSort(a, low, pos - 1);
		quickSort(a, pos + 1, high);
	}
}

int main(){
	cin >> s;

	int n = s.size();
	int a[n];
	for(int i=0; i<n; i++)
		a[i] = (s[i] - 'a' + 1);

	quickSort(a, 0, n-1);

	cout << s;
}