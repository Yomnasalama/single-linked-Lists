#include <iostream>

using namespace std;

class Mylinkedlist{
public:
    struct node{
        int data = 0;
        node* next = NULL;
    };
    node* head;

    Mylinkedlist(){
        head = NULL;
    }

    void insert_node(node* prev_node, int new_data){
    if(prev_node == NULL){
        return;
    }

    node* new_node = new node();
    new_node -> data = new_data;
    new_node-> next = prev_node-> next;
    prev_node-> next = new_node;

}

void insert_begin(int new_data){
    node* new_node = new node();
    new_node -> data = new_data;

    if (head == NULL){
        head = new_node;
    }
    else{
        new_node -> next = head;
        head = new_node;
    }
}

void insert_end(int new_data){
    node* new_node  = new node();
    new_node-> data = new_data;

    if(head == NULL){
        head = new_node;
    }
    else{
        node* current = head;
        while(current-> next != NULL){
            current = current-> next;
        }
        current-> next = new_node;
    }
}

void delete_node(node* prev_node){
    if(prev_node == NULL || prev_node-> next == NULL){
        return;
    }
    node* temp_node = prev_node ->next;
    prev_node -> next = temp_node-> next;
    delete(temp_node);
}

void delete_begin(){
    node* temp = head;
    if(head == NULL){
        return;
    }
    if(head-> next == NULL){
        delete(temp);
        head = NULL;
    }
    head = head-> next;
    delete(temp);
}

void delete_end(){
       if(head == NULL){
        return;
       }
       node* curr = head;
       node* prev = NULL;

       while(curr-> next != NULL){
        prev = curr;
        curr = curr-> next;
       }

       if(prev == NULL){
            delete(curr);
            head = NULL;
       }
       else{
        prev-> next = curr->next;
        delete(curr);
       }
}

bool search_node(int key){
    node* curr = head;
    while(curr != NULL){
        if(curr-> data == key){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

//Print linked list by iterative/recursive way
void printList(){
    node* curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

//Print element at position i in linked list
void printwithindex(int i){
    node* curr = head;
    int j = 0;
    while(curr != NULL){
        if(j == i){
            cout<<curr->data<<endl;
        }
        curr = curr->next;
        j++;
    }
}

// Get node at position i in linked list
node* getNode(int i){
    node* curr = head;
    int j = 0;
    while(curr != NULL){
        if(j == i){
            return curr;
        }
        curr = curr->next;
        j++;
    }
}

void printList(node *Node)
{
    while (Node != NULL)
    {
        cout<<" "<<Node->data;
        Node = Node->next;
    }
}

// Swap two nodes in linked list by index
void swapNode(int i, int j){
    int k = 0;
    node* curr = head;
    node* x = head;
    node* prevx = NULL;
    node* y = head;
    node* prevy= NULL;
    node* temp= new node();
    while(curr != NULL){
        if(k == i - 1){
            prevx = curr;
            x = curr->next;
        }
        else if(k == j - 1){
            prevy = curr;
            y = curr->next;
        }
        curr = curr->next;
        k++;
    }
    if(prevy == x){
        temp = y->next;
        y->next = x;
        x->next = temp;
        if(prevx == NULL)
            head = y;
        else
            prevx->next = y;
        return;
    }
    temp = y->next;
    y ->next = x->next;
    x->next = temp;
    if(prevx == NULL){
        head = y;
        prevy->next = x;
    }
    if(prevy == NULL){
        head = x;
        prevx-> next = y;
    }
    if(prevx != NULL && prevy != NULL){
        prevx->next = y;
        prevy->next = x;
    }
}

// Remove duplication of nodes in unsorted linked list
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


// Union of two sorted linked list
Mylinkedlist union_sorted(Mylinkedlist q){
    node* current = head;
    Mylinkedlist obj3;
    while (current->next != NULL) {
            current = current->next;
    }
    current->next = q.head;
    obj3.head = head;
    obj3.removeduplicate();
    return obj3;
}

bool is_exist(Mylinkedlist obj,int key){
    node* curr = obj.head;
    while(curr != NULL){
        if(curr-> data == key){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

// Difference of two unsorted linked list
void difference(Mylinkedlist curr2){
    node* curr1 = head;
    while(curr1 != NULL){
        if(!is_exist(curr2,curr1->data)){
            cout<<curr1->data<<" ";
        }
        curr1 = curr1->next;
    }

}

};

int main()
{
    Mylinkedlist obj;
    Mylinkedlist obj2;
    Mylinkedlist obj3;
    obj.insert_end(2);
    obj.insert_end(3);
    obj.insert_end(4);
    obj.insert_end(5);
    obj2.insert_end(5);
    obj2.insert_end(6);
    obj2.insert_end(7);
    obj2.insert_end(8);

    cout<<"Union of two linked lists: "<<endl;
    obj3 = obj.union_sorted(obj2);
    obj3.printList();
    obj2.printList();
}
