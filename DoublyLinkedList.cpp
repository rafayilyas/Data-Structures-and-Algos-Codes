#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data; 
    Node* next; 
    Node* prev; 
  
    // Constructor to initialize Node with data
    Node(int data) : data(data), next(nullptr),
  	prev(nullptr) {}
};

// Function to traverse the doubly linked list 
// in forward direction
void forwardTraversal(Node* head) {
  
    // Start traversal from the head of the list
    Node* curr = head;

    // Continue until current node is not null
    // (end of list)
    while (curr != nullptr) {
      
        // Output data of the current node
        cout << curr->data << " ";

        // Move to the next node
        curr = curr->next;
    }

    // Print newline after traversal
    cout << endl;
}

// Function to traverse the doubly linked list 
// in backward direction
void backwardTraversal(Node* tail) {
  
    // Start traversal from the tail of the list
    Node* curr = tail;

    // Continue until current node is not null 
    // (end of list)
    while (curr != nullptr) {
      
        // Output data of the current node
        cout << curr->data << " ";

        // Move to the previous node
        curr = curr->prev;
    }

    // Print newline after traversal
    cout << endl;
}

int main() {
  
    // Sample usage of the doubly linked list and 
    // traversal functions
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    cout << "Forward Traversal:" << endl;
    forwardTraversal(head);

    cout << "Backward Traversal:" << endl;
    backwardTraversal(third);

    return 0;
}




#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    
    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Function to find the length of the doubly linked list
int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    
    // Traverse through the list until reaching the end
    while (temp != nullptr) {
        length++;            // Increment length for each node
        temp = temp->next;   // Move to the next node
    }
    
    return length;
}

// Function to insert a node at the end of the list
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    
    if (head == nullptr) {
        head = newNode;   // If the list is empty, the new node becomes the head
        return;
    }

    Node* temp = head;
    
    // Traverse to the end of the list
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;  // Link the last node to the new node
    newNode->prev = temp;  // Link the new node back to the last node
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Inserting nodes into the list
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    // Print the list
    cout << "Doubly Linked List: ";
    printList(head);

    // Find and print the length of the list
    int length = getLength(head);
    cout << "Length of the list: " << length << endl;

    return 0;
}



#include <iostream>
using namespace std;

// Node structure for a doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor to initialize the node
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Function to insert a new node at the head of the doubly linked list
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);  // Create a new node

    if (head == nullptr) {  // If the list is empty
        head = newNode;     // The new node becomes the head
        return;
    }

    // Update the links to insert the new node at the head
    newNode->next = head;   // New node points to the current head
    head->prev = newNode;   // The current head's previous points to the new node
    head = newNode;         // The new node becomes the new head
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;  // Initialize the list as empty

    // Inserting nodes at the head of the list
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);

    // Print the list
    cout << "Doubly Linked List: ";
    printList(head);

    return 0;
}


#include <iostream>
using namespace std;

// Node structure for a doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Function to insert a new node at the head
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {  // If the list is empty
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Function to insert a new node at the tail
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {  // If the list is empty
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete the node at the head
void deleteAtHead(Node*& head) {
    if (head == nullptr) {  // If the list is empty
        cout << "List is empty, nothing to delete at the head!" << endl;
        return;
    }

    Node* temp = head;   // Store the current head
    head = head->next;   // Move the head to the next node

    if (head != nullptr) {
        head->prev = nullptr;  // Set the new head's previous to nullptr
    }

    delete temp;  // Delete the old head node
}

// Function to delete the node at the tail
void deleteAtTail(Node*& head) {
    if (head == nullptr) {  // If the list is empty
        cout << "List is empty, nothing to delete at the tail!" << endl;
        return;
    }

    if (head->next == nullptr) {  // If there is only one node
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    // Traverse to the last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;  // Remove the last node from the list
    delete temp;                 // Delete the tail node
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Inserting elements
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    // Print the list
    cout << "Doubly Linked List: ";
    printList(head);

    // Deleting the head node
    deleteAtHead(head);
    cout << "After deleting head: ";
    printList(head);

    // Deleting the tail node
    deleteAtTail(head);
    cout << "After deleting tail: ";
    printList(head);

    return 0;
}
