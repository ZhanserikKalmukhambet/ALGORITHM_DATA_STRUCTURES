#include <bits/stdc++.h>

using namespace std;

struct Queue{
    int a[100000];
    int start;
    int end;

    Queue(){
        start = 0;
        end = 0;
    }

    void push(int x){
        a[end] = x;
        end++;
    }
    void pop(){
        if(end == start)
            return;
        start++;
    }
    int front(){
        return a[start];
    }
    int size(){
        return end - start;
    }
    bool empty(){
        return start == end;
    }
    void clear(){
        start = 0;
        end = 0;
    }
};

int main(){
    Queue q;
    int x;
    while(cin >> x){
        if(x == 0)
            break;
        q.push(x);
    }

    cout << q.size() << endl;
    cout << q.front() << endl;
    q.pop();
    cout << q.size() << endl;
    cout << q.front() << endl;
    cout << q.empty() << endl;
}