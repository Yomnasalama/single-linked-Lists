#include <iostream>

using namespace std;

class Mylinkedlist{
public:
    struct node
    {
        int data;
        node* next;
    };
    node* head;
    int i;
    Mylinkedlist(){
        head = NULL;
        i = 0;
    }

    void insert(int new_data) {
        node* new_node = new node();
        new_node->data = new_data;
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            node* curr = head;
            while (curr->next != NULL)
            curr = curr->next;
            curr->next = new_node;
        }
    }
//Print linked list in reversed order
void print(node* first)
{
    if (first == NULL)
        return;
    print(first->next);
    cout << first->data << " ";
}

// Insert element at position i in linked list
void insert_position(int new_data, int position) {
    node* new_node = new node();
    node* temp = new node();
    new_node->data = new_data;
    new_node->next = NULL;
    node* curr = head;
    node* previous = NULL;
    for(int i = 0; i < position; i++)
    {
        if(curr->next != NULL)
        {
            previous = curr;
            curr = curr->next;
        }
        else
        {
            cout <<"index isn't available" << endl;
            exit(0);
        }
    }
    temp = previous->next;
    previous->next = new_node;
    new_node->next = temp;
}

void print() {
    node* curr = head;
	while (curr != NULL) {
		cout << curr->data << ' ';
		curr = curr->next;
	}
	cout<<endl;
}

//Delete all elements in linked list by iterative/recursive way
void deleteRecursive(node* first)
{
    if (first == NULL)
        return;
    deleteRecursive(first->next);
}

void deleteIterative()	//function to destroy list
{
	node* temp;			//create temp pointer of type Node
	while (head != NULL)	//if first != null means the list isn't empty
	{
		temp = head; //make the temp refer to the first node
		head = head->next;	//and make first be the next element
	}
}

// Reverse linked list
void reverse()
{
    node* current = head;
    node *prev = NULL, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


int counterIterative(int value)
{
    node* current = head;
    int i = 0;
    while (current != NULL) {
        if (current->data == value)
            i++;
        current = current->next;
    }
    return i;
}

int counterRecursive(node* head, int value)
{
    if (head == NULL)
        return i;
    if (head->data == value)
        i++;
    return counterRecursive(head->next, value);
}

    void removeduplicate(){
        node* curr1 = head;
        node* curr2;
        node* dup;
        while(curr1 != NULL && curr1->next != NULL){
            curr2 = curr1;
            while(curr2 -> next != NULL){
                if(curr1->data == curr2->next->data){
                    dup = curr2->next;
                    curr2->next = curr2->next->next;
                    delete(dup);
                }
                else{
                    curr2 = curr2->next;
                }
            }
            curr1 = curr1->next;
        }
    }
// Union of two unsorted linked list
Mylinkedlist unionOfUnsortedLists(Mylinkedlist obj2)
    {
        node* current = head;
        Mylinkedlist obj3;
        while (current->next != NULL) {
                current = current->next;
        }
        current->next = obj2.head;
        obj3.head = head;
        obj3.removeduplicate();
        return obj3;
    }


};

//Intersection of two sorted linked list
Mylinkedlist Intersection(Mylinkedlist obj, Mylinkedlist obj2)
{
    Mylinkedlist obj3;
    while (obj.head != NULL && obj2.head != NULL) {
        if (obj.head->data == obj2.head->data) {
            obj3.insert(obj.head->data);
            obj.head = obj.head->next;
            obj2.head = obj2.head->next;
        }
        else if (obj.head->data < obj2.head->data)
            obj.head = obj.head->next;
        else
            obj2.head = obj2.head->next;
    }
    return obj3;
}

int main()
{
    Mylinkedlist obj;
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.print(obj.head);
    cout<<endl;

    obj.insert_position(7,2);
    obj.print();

    obj.reverse();
    obj.print();

    obj.deleteRecursive(obj.head);
    obj.print();
    //obj.deleteIterative();
    //obj.print();

    Mylinkedlist obj2;
    obj2.insert(1);
    obj2.insert(2);
    obj2.insert(3);
    obj2.insert(4);
    obj2.insert(1);
    obj2.print();
    cout << obj2.counterIterative(1);
    cout<<endl;


    Mylinkedlist obj3, obj4, obj5;
    obj3.insert(1);
    obj3.insert(2);
    obj3.insert(3);
    obj3.insert(4);
    obj3.insert(5);

    obj4.insert(3);
    obj4.insert(4);
    obj4.insert(5);
    obj4.insert(6);
    obj4.insert(7);
    obj5 = Intersection(obj3,obj4);
    obj5.print();

    obj5 = obj3.unionOfUnsortedLists(obj4);
    obj5.print();

}
