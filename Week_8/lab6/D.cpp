#include <iostream>

using namespace std;

int partition(pair<pair<int,int>, int> * a, int low, int high){
	int i = low - 1;
	int pivot = high;

	for(int j=low; j<=high-1; j++){
		if(a[j].second < a[pivot].second){
			i++;
			swap(a[i], a[j]);
		}
		else if(a[j].second == a[pivot].second){
			if(a[j].first.second < a[pivot].first.second){
				i++;
				swap(a[i], a[j]);
			}
			else if(a[j].first.second == a[pivot].first.second){
				if(a[j].first.first < a[pivot].first.first){
					i++;
					swap(a[i], a[j]);
				}
			}
		}
	}
	swap(a[i+1], a[pivot]);

	return i + 1;
}

void quickSort(pair<pair<int,int>, int> * a, int low, int high){
	if(low < high){
		int pos = partition(a, low, high);
		quickSort(a, low, pos - 1);
		quickSort(a, pos + 1, high);
	}
}

pair<pair<int,int>, int> get_date(string s){
	pair<pair<int,int>, int> p;
	string t = "";

	for(int i=0; i<s.size(); i++){
		t += s[i];
		
		if(i == 2){
			p.first.first = stoi(t);
			t = "";
		}
		if(i == 5){
			p.first.second = stoi(t);
			t = "";
		}
		if(i == s.size()-1)
			p.second = stoi(t);
	}

	return p;
}

int main(){
	int n;
	cin >> n;

	pair<pair<int,int>, int> a[n];
	for(int i=0; i<n; i++){
		string s;
		cin >> s;

		a[i] = get_date(s);
	}

	quickSort(a, 0, n-1);

	for(int i=0; i<n; i++){
		if(a[i].first.first < 10)
			cout << 0;
		cout << a[i].first.first << '-';

		if(a[i].first.second < 10)
			cout << 0;
		cout << a[i].first.second << '-';

		cout << a[i].second << '\n';
	}
}