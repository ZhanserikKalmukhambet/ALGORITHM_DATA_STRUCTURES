#include <iostream>

using namespace std; 

class Node  
{  
    public: 
    string data;  
    Node* next;  
};  
  
void removeDuplicates(Node* head)  
{  
	if(!head || !head->next)
        return;

    string cur_data = head->data;
    while(head->next != NULL){
        Node* temp = head->next;

        if(cur_data == temp->data){
            Node* node = temp;
            head->next = node->next;
            delete node;
        }
        else{
            head = head->next;
        }
        cur_data = head->data;
    }
}  

int getCount(Node* head)  
{  
    int cnt = 0;
    while(head != NULL){
        head = head->next;
        cnt++;
    }

    return cnt;
}  

void push(Node** head_ref, string new_data)  
{  

    Node* new_node = new Node(); 
              

    new_node->data = new_data;  
                  

    new_node->next = (*head_ref);      
          

    (*head_ref) = new_node;  
}  
 

void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<"\n";  
        node = node->next;  
    }  
}  

int main()  
{  
    int n;
    string s;
    cin>>n;
    Node* head = NULL;  
    for(int i =0;i<n;i++){
        cin>>s;
        push(&head,s);
    }
                                      
    removeDuplicates(head);  
    cout<<"All in all: "<<getCount(head);
  
    cout<<"\nStudents:\n";      
    printList(head);              
  
    return 0;  
}