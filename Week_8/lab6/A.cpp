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
	int n;
	string s;
	cin >> n >> s;

	int a[n];
	char res[28];
	for(int i=0; i<n; i++){
		if(s[i] == 'a')
			a[i] = 1;
		else if(s[i] == 'e')
			a[i] = 2;
		else if(s[i] == 'i')
			a[i] = 3;
		else if(s[i] == 'o')
			a[i] = 4;
		else if(s[i] == 'u')
			a[i] = 5;
		else
			a[i] = (s[i] - 'b') + 6;

		res[a[i]] = s[i];
	}

	quickSort(a, 0, n-1);

	for(int i=0; i<n; i++)
		cout << res[a[i]];
}