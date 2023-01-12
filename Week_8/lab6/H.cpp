#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;

	char a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	char tar;
	cin >> tar;

	int p = 0;
	while(p != n){
		if(a[p] > tar){
			cout << a[p];
			return 0;
		}
		p++;
	}

	cout << a[0];
	return 0;
}