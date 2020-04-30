//
// Created by jonathan_pc on 4/30/2020.
//

#ifndef INC_1_WET_NEW_DOUBLE_SIDED_LIST_H
#define INC_1_WET_NEW_DOUBLE_SIDED_LIST_H
#include <iostream>
using namespace std;

template<typename T>
class ListNode {

    ListNode *next;

    ListNode *prev;

    T data;
public:
//
//    ListNode(T data, ListNode *prev = nullptr, ListNode *next = nullptr) :
//            data(data), next(next), prev(prev) {
//    }
    void set_data(T data){
        this->data=data;
    }

    void set_next(ListNode* next) {

        this->next=next;
    }

    void set_prev(ListNode* prev) {


        this->prev =prev;
    }
    ListNode<T> *get_next() {
        if (this== nullptr)
            return nullptr;
        return this->next;

    }

    ListNode<T> *get_prev() {
        if (this== nullptr)
            return nullptr;
        return this->prev;

    }
    void print(){
        cout<<this->data<<"\n";
    }

    T get_data(){
        return this->data;
    }

    void operator= (ListNode<T>* node){
        this->next=node->next;
        this->prev=node->prev;
        this->data=node->data;
 }

    ListNode<T> copyNode(){
        ListNode<T>* new_node = new ListNode<T>;
        new_node->set_data(this->data);
        new_node->set_prev(this->prev);
        new_node->set_next(this->next);
        return *new_node;

    }



};
//---------------------------------------------

template<typename T>

class double_sided_list {

    ListNode<T>* first;

    ListNode<T>* last;

    int length;

    ListNode<T>* iterator;

public:

    double_sided_list():length(0), first(nullptr), last(nullptr), iterator(
            nullptr){};



    void addNode(T node_data){
        this->length=this->length+1;

        if(first==nullptr){
            first = new ListNode<T>;
            first->set_data(node_data);
            first->set_next(nullptr);
            first->set_prev(nullptr);
            last=first;
            iterator=first;
        }
        else{
            ListNode<T>* new_node = new ListNode<T>;
            new_node->set_data(node_data);
            new_node->set_prev(last);
            new_node->set_next(nullptr);
            last->set_next(new_node);
        }


    }

    T get_current(){
        if (this->iterator!=nullptr)
            return this->iterator->get_data();

    }
    T get_next(){
        if ((iterator!=nullptr)||(iterator->get_next()!=nullptr)) {
            iterator = iterator->get_next();
            return iterator->get_data();
        }
        return nullptr;

    }

    T get_first() {
        iterator = this->first;
        return iterator->get_data();
    }

    ListNode<T>* get_current_node(){
        return iterator;
    }



    void printList(){

        ListNode<T> *it = this->first;

        while (it!= nullptr)
        {
            T data = it->get_data();
            cout<<data<<"\n";
            it=it->get_next();

        }

    }

    ListNode<T>* add_node_after(ListNode<T> * node_to_add_after, T data){

        ListNode<T>* new_node=new ListNode<T>;
        new_node->set_prev(node_to_add_after);
        new_node->set_next(node_to_add_after->get_next());
        new_node->set_data(data);
        node_to_add_after->set_next(new_node);
        if(node_to_add_after->get_next()!= nullptr)
            node_to_add_after->get_next()->set_prev(new_node);
        return new_node;


    }



};

#endif //INC_1_WET_NEW_DOUBLE_SIDED_LIST_H
