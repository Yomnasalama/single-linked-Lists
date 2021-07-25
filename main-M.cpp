#include <bits/stdc++.h>

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

void insert_end(int new_data){
    node* new_node = new node();
    new_node->data = new_data;
    if(head == NULL){
        head = new_node;
    }
    else{
        node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = new_node;
        new_node->next = NULL;
    }
}

void delete_node(node* prev_node){
    if(prev_node == NULL || prev_node->next == NULL)
        return;
    node* temp_node = prev_node->next;
    prev_node->next = temp_node->next;
    delete(temp_node);
}

void delete_begin(){
    if(head == NULL)
        return;
    node* temp_node = head;
    if(head->next == NULL){
        delete(temp_node);
        head = NULL;
    }
    else{
        head = head->next;
        delete(temp_node);
    }
}

void delete_end(){
    if(head == NULL)
        return;
    node* curr = head;
    node* prev = NULL;
    while(curr->next != NULL){
        prev = curr;
        curr = curr->next;
    }
    if(prev == NULL){
        delete(curr);
        head = NULL;
    }
    else{
        prev->next = curr->next;
        delete(curr);
    }
}

void print_linked_list(){
    node* curr = head;
    while(curr != NULL){
        cout<<curr->data<<' ';
        curr = curr->next;
    }
    cout<<endl;
}

//Count number of nodes in linked list by iterative/recursive way
int count_nodes(){
    if(head == NULL){
        return 0;
    }
    node* curr = head;
    int nodes = 1;
    while(curr->next != NULL){
        curr = curr->next;
        nodes++;
    }
    return nodes;
}

//Print element at middle of linked list
void print_middle(){
    if(head == NULL){
        return;
    }
    int total = count_nodes();
    int limit;
    if(total % 2 == 0){
        limit = total / 2;
    }
    else{
        limit = (total + 1) / 2;
    }
    node* curr = head;
    int nodes = 1;
    while(nodes < limit){
        curr = curr->next;
        nodes++;
    }
    cout<<"Middle Node : "<<curr->data<<endl;
}

//Delete element at position i in linked list
void delete_node_at_idx(int idx){
    if(head == NULL){
        return;
    }
    if(idx == 0){
        delete_begin();
    }
    else if(idx == count_nodes()-1){
        delete_end();
    }
    else{
        node* curr = head;
        node* prev = NULL;
        int i = 0;
        while(i<idx){
            prev = curr;
            curr = curr->next;
            i+=1;
        }
        delete_node(prev);
    }
}

//Check if linked list has loop or not
bool loop_list(){

    node* curr_top = head;
    while(curr_top->next != NULL){
        node* curr = curr_top->next;
        while(curr != NULL){
            if(curr == curr_top){
                return true;
            }
            curr = curr->next;
        }
        curr_top = curr_top->next;
    }
    return false;
}


//Remove duplication of nodes in sorted linked list
void remove_duplicates(){
    node* curr_top = head;
    while(curr_top->next != NULL){
        node* curr = head;
        node* prev = NULL;
        bool found = false;
        while(curr->next != NULL){
            if(curr->data == curr_top->data){
                if(found == true){
                    delete_node(prev);
                    curr = prev->next;
                    continue;
                }
                else{
                    found = true;
                }
            }
            prev = curr;
            curr = curr->next;
        }
        curr_top = curr_top->next;
    }
}

int get_node_data_at_idx(int idx){
    if(head == NULL){
        return INT_MAX;
    }
    if(idx == 0){
        return head->data;
    }
    node* curr = head;
    int i = 0;
    while(i<idx){
        curr = curr->next;
        i+=1;
    }
    return curr->data;
}
//Check if linked list is palindrome or not
bool is_palindrome(){
    int total = count_nodes();
    int limit = count_nodes()/2;
    bool palind = true;
    for(int i = 0 ; i < limit ; i++){
        if(get_node_data_at_idx(i) == get_node_data_at_idx(total - (i + 1))){
            continue;
        }
        else{
            palind = false;
            return palind;
        }
    }
    return palind;
}



};


int main()
{
    Mylinkedlist obj;
    obj.insert_end(1);
    obj.insert_end(2);
    obj.insert_end(3);
    obj.insert_end(4);
    obj.insert_end(5);
    cout<<obj.count_nodes();
    cout<<endl;

    obj.print_middle();

    obj.delete_node_at_idx(4);
    obj.print_linked_list();

    cout<<obj.loop_list();
    cout<<endl;

    Mylinkedlist obj2;
    obj2.insert_end(1);
    obj2.insert_end(1);
    obj2.insert_end(3);
    obj2.insert_end(4);
    obj2.insert_end(4);
    obj2.insert_end(5);
    obj2.remove_duplicates();
    obj2.print_linked_list();

    Mylinkedlist obj3;
    obj3.insert_end(1);
    obj3.insert_end(2);
    obj3.insert_end(3);
    obj3.insert_end(2);
    obj3.insert_end(1);
    cout<<obj3.is_palindrome();

}
