// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node(int val)
//     {
//         data = val;
//         next = NULL;
//     }
// };

// void insertAtHead(Node *&head, int val)
// {
//     Node *temp = new Node(val);
//     temp->next = head;
//     head = temp;
// }

// void insertAtTail(Node *&head, int val)
// {
//     Node *newNode = new Node(val);
//     if (head == NULL)
//     {
//         head = newNode;
//         return;
//     }
//     Node *temp = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = newNode;
// }

// void deleteAtHead(Node *&head)
// {
//     if (head == NULL)
//         return;
//     Node *temp = head;
//     head = head->next;
//     delete temp;
// }

// void deleteAtTail(Node *&head)
// {
//     if (head == NULL)
//         return;
//     if (head->next == NULL)
//     {
//         deleteAtHead(head);
//         return;
//     }
//     Node *temp = head;
//     while (temp->next->next != NULL)
//     {
//         temp = temp->next;
//     }
//     delete temp->next;
//     temp->next = NULL;
// }

// void deletion(Node *&head, int val)
// {
//     if (head == NULL)
//         return;
//     if (head->data == val)
//     {
//         deleteAtHead(head);
//         return;
//     }
//     Node *temp = head;
//     while (temp->next->data != val)
//     {
//         temp = temp->next;
//     }
//     if (temp->next == NULL)
//         return;
//     Node *delta = temp->next;
//     temp->next = temp->next->next;
//     delete delta;
// }
// void deleteByposition(Node *&head,int pos)
// {
//     if (head == NULL)
//         return;
//     if (pos==1)
//     {
//         deleteAtHead(head);
//         return;
//     }
//     Node *temp = head;
//     int count = 1;
//     while(temp!=NULL && count<pos-1)
//     {
//         temp = temp->next;
//         count++;
//     }
//     Node *delta = temp->next;
//     temp->next = temp->next->next;
//     delete delta;
// }
// void display(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main()
// {
//     Node *head = NULL;
//     insertAtHead(head, 10);
//     insertAtHead(head, 11);
//     insertAtTail(head, 13);
//     insertAtTail(head, 15);
//     insertAtTail(head, 16);
//     insertAtTail(head, 18);
//     insertAtHead(head, 20);
//     insertAtHead(head, 21);
//     deleteAtHead(head);
//     deleteAtTail(head);
//     deletion(head, 20);
//     deleteByposition(head,3);
//     display(head);
//     return 0;
// }



// Doubly Linked list


// #include <iostream>
// using namespace std;
// class Node
// {
//     public:
//     int data;
//     Node *next;
//     Node *prev;

//     Node(int val)
//     {
//         data = val;
//         next = NULL;
//         prev = NULL;
//     }
// };
// void insertAthead(Node *&head ,int val)
// {
//     Node *temp = new Node(val);
//     temp -> next = head;
//     if(head!=NULL)
//     {
//     head -> prev = temp;
//     }
//     head = temp;
// }
// void insertAttail(Node *&head,int val)
// {
//     Node *newNode = new Node(val);
//     Node *temp = head;
//     if(head==NULL)
//     {
//         insertAthead(head,val);
//     }
//     while(temp->next!=NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next= newNode;
//     newNode-> prev = temp;
// }
// void deleteAthead(Node *&head)
// {
//     if(head == NULL)
//     return;
//     Node *temp = head;
//     head = head->next;
//     if(head!=NULL)
//     {
//     head->prev = NULL;
//     }
//     delete temp;
// }
// void deleteAttail(Node *&head)
// {
//     if(head == NULL)
//     {
//         return;
//     }
//     if(head->next == NULL)
//     {
//         deleteAthead(head);
//         return;
//     }
//     Node *temp = head;
//     while(temp->next!=NULL)
//     {
//         temp = temp->next;
//     }
//     temp ->prev->next = NULL;
//     delete temp;
// }
// void display(Node *&head)
// {
//     Node *temp = head;
//     while(temp!=NULL)
//     {
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
// }
// int main()
// {
//     Node *head = NULL;
//     insertAthead(head,10);
//     insertAthead(head,11);
//     insertAthead(head,12);
//     insertAttail(head,15);
//     insertAttail(head,16);
//     insertAttail(head,17);
//     deleteAthead(head);
//     deleteAttail(head);
//     display(head);
// }


// Circular Linked List

// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node *next;

//     Node(int val) {
//         data = val;
//         next = NULL;
//     }
// };

// void insertAthead(Node *&head, int val) {
//     Node *newNode = new Node(val);
//     if (head == NULL) {
//         head = newNode;
//         newNode->next = head;
//         return;
//     }
//     Node *temp = head;
//     while (temp->next != head) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
//     newNode->next = head;
//     head = newNode;
// }

// void insertAttail(Node *&head, int val) {
//     Node *newNode = new Node(val);
//     if (head == NULL) {
//         head = newNode;
//         newNode->next = head;
//         return;
//     }
//     Node *temp = head;
//     while (temp->next != head) {
//         temp = temp->next;
//     }
//     temp->next = newNode;
//     newNode->next = head;
// }

// void deleteAthead(Node *&head) {
//     if (head == NULL) {
//         return;
//     }
//     Node *temp = head;
//     if (head->next == head) {
//         delete head;
//         head = NULL;
//         return;
//     }
//     while (temp->next != head) {
//         temp = temp->next;
//     }
//     Node *delta = head;
//     temp->next = head->next;
//     head = head->next;
//     delete delta;
// }

// void deleteAttail(Node *&head) {
//     if (head == NULL) {
//         return;
//     }
//     if (head->next == head) {
//         delete head;
//         head = NULL;
//         return;
//     }
//     Node *temp = head;
//     while (temp->next->next != head) {
//         temp = temp->next;
//     }
//     Node *todel = temp->next;
//     temp->next = head;
//     delete todel;
// }

// void display(Node *&head) {
//     if (head == NULL) {
//         return;
//     }
//     Node *temp = head;
//     do {
//         cout << temp->data << " ";
//         temp = temp->next;
//     } while (temp != head);
//     cout << endl;
// }

// int main() {
//     Node *head = NULL;
//     insertAthead(head, 10);
//     insertAthead(head, 11);
//     insertAthead(head, 12);
//     insertAthead(head, 13);
//     insertAttail(head, 20);
//     deleteAthead(head);
//     deleteAttail(head);
//     display(head);
//     return 0;
// }



// Linked List Stack

// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node *next;
//     Node(int val) {
//         data = val;
//         next = NULL;
//     }
// };
// class Stack {
// public:
//     Node *top;
//     Stack() {
//         top = NULL;
//     }
//     void push(int val) {
//         Node *newNode = new Node(val);
//         newNode->next = top;
//         top = newNode;
//     }
//     void pop()
//     {
//         Node *temp = top;
//         top = top->next;
//         delete temp;
//     }
//     void display() {
//         Node *temp = top;
//         while (temp != NULL) {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
//     int peek()
//     {
//         return top->data;
//     }
// };

// int main() {
//     Stack s;
//     s.push(10);
//     s.push(11);
//     s.push(12);
//     s.display();
//     s.pop();
//     s.display();
//     cout<<s.peek();
//     return 0;
// }




// Doubly Linked List Stack
// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node *next;
//     Node *prev;
//     Node(int val) {
//         data = val;
//         next = NULL;
//         prev = NULL;
//     }
// };

// class Stack {
// public:
//     Node *top;
//     Stack() {
//         top = NULL;
//     }

//     void push(int val) {
//         Node *newNode = new Node(val);
//         newNode->next = top;
//         newNode->prev = NULL;
//         if (top != NULL) {
//             top->prev = newNode;
//         }
//         top = newNode;
//     }

//     void pop() {
//         if (top == NULL) {
//             return;
//         }
//         Node *temp = top;
//         top = top->next;
//         if (top != NULL) {
//             top->prev = NULL;
//         }
//         delete temp;
//     }

//     void display() {
//         Node *temp = top;
//         while (temp != NULL) {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     Stack s;
//     s.push(10);
//     s.push(11);
//     s.push(12);
//     s.push(13);
//     s.display();
//     s.pop();
//     s.display();
//     return 0;
// }

// Reverse Stack printing

// #include <iostream>
// using namespace std;
// #define SIZE 100
// char array[SIZE];
// int top = -1;
// void push(char value)
// {
//     if(top==SIZE-1)
//     {
//         cout<<"Stack overflow!!!"<<endl;
//         return;
//     }
//     else
//     {
//         top++;
//         array[top] = value;
//     }
// }
// char pop()
// {
//     if(top==-1)
//     {
//         cout<<"Stack empty!!"<<endl;
//     }
//     else{
//         return array[top--];
//     }
// }
// int main()
// {
//     string statement;
//     cout<<"Enter the statement ";
//     getline (cin, statement);
//     for(int i = 0; i<statement.length(); i++)
//     {
//         push(statement[i]);
//     }
//     cout<<"Displaying in reverse order...."<<endl;
//     while(top!=-1)
//     {
//         cout<<pop();
//     }
// }


// Queue using SIngle linked List

// #include <iostream>
// using namespace std;
// struct Node
// {
//     int data;
//     Node *next;
//     Node (int val)
//     {
//         data = val; 
//         next = NULL;
//     }
// };
// class Queue
// {
//     public:
//     Node *front;
//     Node *rear;
//     Queue()
//     {
//         front = NULL;
//         rear = NULL;
//     }
//     void enqueue(int val)
//     {
//         Node *newNode = new Node(val);
//         if (front==NULL)
//         {
//             front = rear = newNode;
//         }
//         rear -> next = newNode;
//         rear = newNode;
//     }
//     void dequeue()
//     {
//         Node *temp = front;
//         front = front->next;
//         delete temp;
//     }
//     int peek()
//     {
//         return front->data;
//     }
//     void display()
//     {
//         Node *temp = front;
//         while(temp!=rear)
//         {
//             cout<<temp->data<<" ";
//             temp = temp->next;
//         }
//     }
// };
// int main()
// {
//     Queue q;
//     q.enqueue(10);
//     q.enqueue(11);
//     q.enqueue(12);
//     q.enqueue(13);
//     q.display();
//     cout<<endl;
//     q.dequeue();
//     q.display();
//     cout<<q.peek();
// }


// Doubly Linked list queue

// #include <iostream>
// using namespace std;
// struct Node
// {
//     int data;
//     Node *next;
//     Node *prev;
//     Node(int val)
//     {
//         data = val;
//         next = NULL;
//         prev = NULL;    
//     }
// };
// class Queue
// {
//     public:
//     Node *front;
//     Node *rear;
//     Queue()
//     {
//         front = NULL;
//         rear = NULL;
//     }
// void enqueue(int val)
// {
//     Node *newNode = new Node(val);
//     if(front == NULL)
//     {
//         front = rear = newNode;
//     }
//     rear->next = newNode;
//     rear = newNode;
//     rear -> prev = front;
// }
// void dequeue()
// {
//     Node *temp = front;
//     front = front ->next;
//     front ->prev = NULL;
//     delete temp;
// }
//     void display()
//     {
//         Node *temp = front;
//         while(temp!=rear)
//         {
//             cout<<temp->data<<" ";
//             temp = temp->next;
//         }
//     }
// };
// int main()
// {
//     Queue q;
//     q.enqueue(10);
//     q.enqueue(11);
//     q.enqueue(12);
//     q.enqueue(13);
//     q.display();
//     q.dequeue();
//     q.display();
// }


// Circular linked list queue

// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node *next;
//     Node *prev;
//     Node(int val) {
//         data = val;
//         next = NULL;
//         prev = NULL;
//     }
// };

// class CircularQueue {
// public:
//     Node *front;
//     Node *rear;
//     CircularQueue() {
//         front = NULL;
//         rear = NULL;
//     }

//     void enqueue(int val) {
//         Node *newNode = new Node(val);
//         if (front == NULL) {
//             front = rear = newNode;
//             newNode->next = front;
//             newNode->prev = front;
//         } else {
//             rear->next = newNode;
//             newNode->prev = rear;
//             newNode->next = front;
//             rear = newNode;
//             front->prev = rear;
//         }
//     }

//     void dequeue() {
//         if (front == NULL) return;
//         Node *temp = front;
//         if (front == rear) {
//             front = rear = NULL;
//         } else {
//             front = front->next;
//             rear->next = front;
//             front->prev = rear;
//         }
//         delete temp;
//     }

//     void display() {
//         if (front == NULL) return;
//         Node *temp = front;
//         do {
//             cout << temp->data << " ";
//             temp = temp->next;
//         } while (temp != front);
//         cout << endl;
//     }
// };

// int main() {
//     CircularQueue q;
//     q.enqueue(10);
//     q.enqueue(11);
//     q.enqueue(12);
//     q.enqueue(13);
//     q.display();
//     q.dequeue();
//     q.display();
//     return 0;
// }


// #include <iostream>
// #include <string>
// using namespace std;

// struct Node {
//     string name;
//     string phoneNumber;
//     string location;
//     Node* next;
    
//     Node(string n, string p, string l) : name(n), phoneNumber(p), location(l), next(NULL) {}
// };

// class PhoneBook {
// private:
//     Node* head;

// public:
//     PhoneBook() : head(NULL) {}

//     void addEntry(string name, string phoneNumber, string location) {
//         Node* newNode = new Node(name, phoneNumber, location);
//         if (head == NULL) {
//             head = newNode;
//         } else {
//             Node* temp = head;
//             while (temp->next != NULL) {
//                 temp = temp->next;
//             }
//             temp->next = newNode;
//         }
//     }

//     Node* searchByName(string name) {
//         Node* temp = head;
//         while (temp != NULL) {
//             if (temp->name == name) {
//                 return temp;
//             }
//             temp = temp->next;
//         }
//         return NULL;
//     }

//     void modifyPhoneNumber(string name, string newPhoneNumber) {
//         Node* contact = searchByName(name);
//         if (contact != NULL) {
//             contact->phoneNumber = newPhoneNumber;
//         }
//     }

//     void display() {
//         Node* temp = head;
//         while (temp != NULL) {
//             cout << "Name: " << temp->name << ", Phone: " << temp->phoneNumber << ", Location: " << temp->location << endl;
//             temp = temp->next;
//         }
//     }
// };

// int main() {
//     PhoneBook phonebook;
//     phonebook.addEntry("Dean", "5000", "NAB");
//     phonebook.addEntry("Prof A", "5001", "FCSE");
//     phonebook.addEntry("Prof B", "5002", "FEE");
//     phonebook.addEntry("Prof C", "5003", "FME");
//     phonebook.addEntry("Main Gate", "5555", "Entrance");

//     phonebook.display();

//     Node* foundContact = phonebook.searchByName("Prof A");
//     if (foundContact) {
//         cout << "Found: " << foundContact->name << ", Phone: " << foundContact->phoneNumber << endl;
//     }

//     phonebook.modifyPhoneNumber("Prof A", "6000");
//     phonebook.display();

//     return 0;
// }




