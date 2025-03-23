```cpp
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int new_data){
        data = new_data;
        next = nullptr;
    }
};

Node* insertAtBeginning(Node* head, int new_data){
    Node* new_node = new Node(new_data); //creates node with data

    new_node->next = head;  //makes the next of new node point to current head

    return new_node;
}

Node* deleteBeginning(Node* head){
    if (head == nullptr) //checks if list is empty
    return nullptr;

    Node* temp = head;
    head = head->next;

    delete temp;

    return head;
}

void displayList(Node* head){
    Node* curr = head;
    while (curr != nullptr){
        cout<<" "<<curr->data;
        curr = curr->next;
    }
    cout<<endl;
}

int main(){
    Node* head = new Node(8);
    head->next = new Node(11);
    head->next->next = new Node(15);
    head->next->next->next = new Node(3);

    cout<< "Origial Linked List:";
    displayList(head);

    cout<<"When Node is added at the front";
    int data = 1;

    head = insertAtBeginning(head, data);

    displayList(head);

    cout<<"When front Node is removed";
    head = deleteBeginning(head);
    displayList(head);

}
```
video: https://youtu.be/dZoraDwMTyY
