#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void createInitialList() {
        insertAtEnd(10);
        insertAtEnd(20);
        insertAtEnd(30);
        cout << "Initial list created:\n";
        display();
    }

    void insertAtBeg(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at beginning:\n";
        display();
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newNode;
        }
        cout << "Inserted " << val << " at end:\n";
        display();
    }

    void insertAfter(int target, int val) {
        Node* ptr = head;
        while (ptr != NULL && ptr->data != target)
            ptr = ptr->next;

        if (ptr == NULL) {
            cout << "Target node " << target << " not found.\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = ptr->next;
        ptr->next = newNode;
        cout << "Inserted " << val << " after " << target << ":\n";
        display();
    }

    void insertBefore(int target, int val) {
        if (head == NULL) return;

        if (head->data == target) {
            insertAtBeg(val);
            return;
        }

        Node* prev = NULL;
        Node* ptr = head;
        while (ptr != NULL && ptr->data != target) {
            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr == NULL) {
            cout << "Target node " << target << " not found.\n";
            return;
        }

        Node* newNode = new Node(val);
        prev->next = newNode;
        newNode->next = ptr;
        cout << "Inserted " << val << " before " << target << ":\n";
        display();
    }

    void insertAtPosition(int pos, int val) {
        if (pos <= 0) {
            cout << "Invalid position.\n";
            return;
        }

        if (pos == 1) {
            insertAtBeg(val);
            return;
        }

        Node* ptr = head;
        for (int i = 1; ptr != NULL && i < pos - 1; i++)
            ptr = ptr->next;

        if (ptr == NULL) {
            cout << "Position " << pos << " out of range.\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = ptr->next;
        ptr->next = newNode;
        cout << "Inserted " << val << " at position " << pos << ":\n";
        display();
    }

    void display() {
        Node* ptr = head;
        cout << "List: ";
        while (ptr != NULL) {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL\n\n";
    }
};

int main() {
    LinkedList list;

    list.createInitialList();       // 10 -> 20 -> 30
    list.insertAtBeg(5);            // 5 at beginning
    list.insertAtEnd(40);           // 40 at end
    list.insertAfter(20, 25);       // 25 after 20
    list.insertBefore(10, 7);       // 7 before 10
    list.insertAtPosition(4, 15);   // 15 at position 4

    return 0;
}



/*#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class linkedlist {
    node* head;

public:
    linkedlist() {
        head = NULL;
    }

    void createinitiallist() {
        insertatend(10);
        insertatend(20);
        insertatend(30);
        cout << "Initial list created:\n";
        display();
    }

    void insertatbeg(int val) {
        node* newnode = new node(val);
        newnode->next = head;
        head = newnode;

        cout << "After insertion at beginning (" << val << "):\n";
        display();
    }

    void insertatend(int val) {
        node* newnode = new node(val);

        if (head == NULL) {
            head = newnode;
        } else {
            node* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }

        cout << "After insertion at end (" << val << "):\n";
        display();
    }
    
    
    void insertafter(int target,int val)
    {
    	node* ptr =head;
    	while(ptr!=NULL && ptr->data!=target)
    	ptr = ptr->next;
    	if(ptr==NULL)
    	{
    		cout<<"Target node" <<target<<"not found.\n";
    		return;
		}
    	
    	
   node* newnode =new node(val);
   newnode->next=ptr->next;
   ptr->next=newnode;
   cout<<"after insertiion of "<<val <<"after "<<target<"\n"; 	
    }
    	
void insertbefore(int target, int val)
{
	if(head==NULL )
	return;
	
	if(head->data==target)
	{
		insertatbeg(val);
		return;
	}

node* prev =NULL;
node* ptr= head;
while(ptr!=NULL && ptr->data != target)
{
	prev=ptr;
	ptr=ptr->next;
}

if(ptr==NULL)
{
	cout<<"target node"<<target<<"not found.\n";
	return;
}
node* newnode = new node(val);
prev->next=newnode;
newnode->next=ptr;
cout << "After insertion of " << val << " before " << target << "\n";
}


void insert_at_nth_pos(int pos,int val)
{
	if(pos <=0)
	{
		cout<<"invalid position\n";
		return;
	}
if(pos==1)
{
	insertatbeg(val);
	return;
}
node* ptr=head;
for (int i = 1; ptr != NULL && i < pos - 1; i++)
ptr=ptr->next;
if(ptr==NULL)
{
	cout<<"position"<<pos<<"out of range\n";
	return;
}
node* newnode=new node(val);
newnode->next=ptr->next;
ptr->next=newnode;
cout << "After insertion of " << val << " at position " << pos << "\n";
}


    void display() {
        node* ptr = head;
        cout << "List: ";
        while (ptr != NULL) {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    linkedlist list;

    list.createinitiallist();  // Creates 10 -> 20 -> 30
    list.insertatbeg(5);  
	list.insertatend(40);
	list.insertafter(20,25);
	list.insertbefore(10,7);
	list.insert_at_nth_pos(4,15);
	cout<<"final list after all insertions:\n";
	
	
	     // Inserts 5 at beginning
    list.display();            // Final display (optional since already printed after each insert)

    return 0;
}*/

