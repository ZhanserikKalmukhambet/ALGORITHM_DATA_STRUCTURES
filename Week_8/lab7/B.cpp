#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	int m;
	cin >> m;
	int b[m];
	for(int i=0; i<m; i++)
		cin >> b[i];

	int res[n + m];
	int i = 0, j = 0, k = 0;
	while(i < n && j < m){
		if(a[i] < b[j]){
			res[k] = a[i];
			i++;
		}
		else{
			res[k] = b[j];
			j++;
		}
		k++;
	}

	while(i < n){
		res[k] = a[i];
		i++; k++;
	}
	while(j < m){
		res[k] = b[j];
		j++; k++;
	}

	for(int i=0; i<n+m; i++)
		cout << res[i] << ' ';
	return 0;
}