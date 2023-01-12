#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    string val;
    Node* prev;
    Node* next;

    Node(string val){
        this->val = val;   
        prev = next = NULL;
    }
};

class DLL{
public:
    Node* head;
    Node* tail;

    DLL(){
        head = tail = NULL;
    }

    void add_front(string val){
        Node* node = new Node(val);
        if(head == NULL){
            head = node;
            tail = node;
        }
        else{
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void add_back(string val){
        Node* node = new Node(val);
        if(head == NULL){
            head = node;
            tail = node;
        }
        else{
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    string erase_front(){
        if(head == NULL)
            return "error";
        
        string res = head->val; 
        if(head->next == NULL){
            head = tail = NULL;
            return res;
        }   
        
        head = head->next;
        head->prev = NULL;        

        return res;
    }

    string erase_back(){
        if(head == NULL)
            return "error";
        
        string res = tail->val;
        if(head->next == NULL){
            head = tail = NULL;
            return res;
        }

        tail = tail->prev;
        tail->next = NULL;

        return res;
    }

    string front(){
        if(head == NULL)
            return "error";
        return head->val;
    }

    string back(){
        if(head == NULL)
            return "error";

        return tail->val;
    }

    void clear(){
        while(head != NULL){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    } 
};

int main(){
    DLL dll;

    string q;
    while(cin >> q){
        string data;

        if(q == "exit"){
            cout << "goodbye";
            return 0;
        }
        if(q == "clear"){
            dll.clear();
            cout << "ok";
        }
        if(q == "front"){
            cout << dll.front();
        }
        if(q == "back"){
            cout << dll.back();
        }
        if(q == "erase_front"){
            cout << dll.erase_front();
        }
        if(q == "erase_back"){
            cout << dll.erase_back();
        }
        if(q == "add_front"){
            cin >> data;
            dll.add_front(data);
            cout << "ok";
        }
        if(q == "add_back"){
            cin >> data;
            dll.add_back(data);
            cout << "ok";
        }

        cout << '\n';
    }
}