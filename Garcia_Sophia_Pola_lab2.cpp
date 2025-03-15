#include <iostream>
using namespace std;

typedef struct Node{
    string songName;
    Node *link;
} Node;

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;
    
    cout << "My Playlist:" << endl;
    while(temp != NULL){
        cout << temp->songName << "->" << endl;
        if (temp->link == NULL){
            cout << "NULL" << endl;
        }
        
        temp = temp->link;
    }
}

Node *CreateNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;
    
    return newNode;
}

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = CreateNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;
    
    while(temp->link !=NULL){
        temp = temp->link;
    }
    // MAGIINSERT NG NEW NODE SA END
    Node *newNode = CreateNode(data);
    temp->link = newNode;
    
    cout << "A new node has been inserted at the end \n" <<endl;
    return head;
}

Node *insertAtBeginning(string data, Node *head){
    Node *newNode = CreateNode(data);
    newNode->link = head;
    
    head = newNode;
    
    cout << "A new node has been inserted at the beginning \n" << endl;
    
    return head;
}

string InsertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;
    
    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such song exist, please try again later.";
        }
        
        temp = temp->link;
    }
    Node *newNode = CreateNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    

    return "A new node has been added after " + after + "\n";
}

string deleteAtEnd(Node *head){
    if(head == NULL){
        return"The linked list is empty \n";
    }
    
    if(head->link == NULL){
        delete head;
        return "The head has been deleted \n";
    }
    
    Node *temp = new Node;
    temp = head;
    
    while(temp->link->link != NULL){
        temp = temp->link;
    }
    
    temp->link = NULL;
    
    return "A node has been deleted at the end \n";
}

Node *deleteFromBeginning(Node *head){
    if(head == NULL){
        cout << "The linked list is empty \n" <<endl;
        return NULL;
    }
    
    if(head->link == NULL){
        delete head;
    }
    
    head = head->link;
    
    cout<<"A node has been delete from the beginning \n" << endl;
    
    return head;
}

Node *deleteFromGivenNode(string givenNode, Node *head){
    if(head == NULL){
        cout << "The linked list is empty. \n" << endl;
        return NULL;
    }
    
    if(head->songName.compare(givenNode) == 0){
        head = deleteFromBeginning(head);
        cout << "The Node" + givenNode + " has been deleted. \n" << endl;
        return head;
    }
    
    Node *temp = new Node;
    Node *next = new Node;
    temp = head;
    next = temp->link;
    
    while(next->songName.compare(givenNode) != 0){
        if(temp == NULL){
            cout << "No such node exist. \n" <<endl;
            return head;
        }
        next = next->link;
        temp = temp->link;
    }
    
    temp->link = next->link;
    cout << "The Node " + givenNode + " has been deleted. \n" << endl;
    return head;
}

int main(){

    Node *head = CreateNode("Sanctuary by Joji");
   
    head = insertAtEnd("Lover is A Day by Cuco", head);
    head = insertAtEnd("One Life by Justin Bieber", head);
    head = insertAtEnd("Tibok by Earl Agustin", head);
    
    head = insertAtBeginning("Gone, Gone, Gone by Phillip Phillips", head);
    head = insertAtBeginning("Good Days by Sza", head);
    head = insertAtBeginning("Cherry Waves by Deftones", head);
    head = insertAtBeginning("My Own Summer by Deftones", head);
    
    cout << InsertAfter("My Own Summer by Deftones", "Isa lang by Arthur Nery", head) <<endl;
    cout << InsertAfter("Isa lang by Arthur Nery", "Ikaw lang by Nobita", head) <<endl;
    cout << InsertAfter("Ikaw lang by Nobita", "Pag-ibig by Yeng Constantino", head) <<endl;
    
    cout << deleteAtEnd(head) <<endl;
    head = deleteFromBeginning(head);
    head = deleteFromGivenNode("Good Days by Sza",head);

     // Figure 6 din
    traverse(head);
    
    return 0;
}