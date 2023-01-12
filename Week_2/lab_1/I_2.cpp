#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    queue <int> q1, q2;
    for(int i=0; i<n; i++){
        if(s[i] == 'S')
            q1.push(i);
        else
            q2.push(i);
    }

    while(!q1.empty() && !q2.empty()){
        if(q1.front() < q2.front()){
            q2.pop();
            q1.push(q1.front() + n);
            q1.pop();
        }
        else{
            q1.pop();
            q2.push(q2.front() + n);
            q2.pop();
        }
    }

    if(q1.empty())
        cout << "KATSURAGI";
    else
        cout << "SAKAYANAGI";
}