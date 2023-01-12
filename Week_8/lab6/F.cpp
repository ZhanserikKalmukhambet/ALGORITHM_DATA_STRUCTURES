#include <bits/stdc++.h>
using namespace std;

map <string, double> mp;

void setMarks(){
	mp["A+"] = 4.0; mp["A"] = 3.75;
	mp["B+"] = 3.5; mp["B"] = 3.0;
	mp["C+"] = 2.5; mp["C"] = 2.0;
	mp["D+"] = 1.5; mp["D"] = 1.0;
	mp["F"] = 0;
}

int partition(pair<pair<string, string>, double> * a, int low, int high){
	int i = low - 1;
	int pivot = high;

	for(int j=low; j<=high-1; j++){
		if(a[j].second < a[pivot].second){
			i++;
			swap(a[i], a[j]);
		}
		else if(a[j].second == a[pivot].second){
			if(a[j].first.first < a[pivot].first.first){
				i++;
				swap(a[i], a[j]);
			}
			else if(a[j].first.first == a[pivot].first.first){
				if(a[j].first.second < a[pivot].first.second){
					i++;
					swap(a[i], a[j]);
				}
			}
		}
	}
	swap(a[i+1], a[pivot]);

	return i + 1;
}

void quickSort(pair<pair<string, string>, double> * a, int low, int high){
	if(low < high){
		int pos = partition(a, low, high);
		quickSort(a, low, pos - 1);
		quickSort(a, pos + 1, high);
	}
}

int main(){
	int n;
	cin >> n;

	setMarks();
	pair<pair<string, string>, double> a[n];

	for(int i=0; i<n; i++){
		string surname, name;
		int m, credits = 0;
		double gpa = 0;
		cin >> surname >> name >> m;
		while(m--){
			string mark;
			int credit;
			cin >> mark >> credit;

			gpa += mp[mark] * credit;
			credits += credit;
		}
		gpa /= credits;

		a[i] = make_pair(make_pair(surname, name), gpa);
	}

	quickSort(a, 0, n-1);
	for(int i=0; i<n; i++){
		cout << a[i].first.first << ' ' << a[i].first.second << ' ';
		cout << fixed;
		cout << setprecision(3) << a[i].second << '\n';
	}
}
