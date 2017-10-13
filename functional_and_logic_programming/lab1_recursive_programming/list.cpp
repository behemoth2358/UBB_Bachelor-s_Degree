#include "list.h"

List::List() {
    head = new node;
    tail = new node;

    head->next = tail;
    tail->next = NULL;
}

List::~List() {
    destroy(head->next);
    delete head;
    delete tail;
}

DataType List::getHead() {
    return head->next->data;
}

void List::destroy(node* current) {
    if(current != tail) {
        destroy(current->next);
        delete current;
    }
}

List::List(const List& other) {
    head = new node;
    tail = new node;

    head->next = tail;
    tail->next = NULL; 

    for(node* it = other.head->next;it != NULL && it != other.tail; it = it->next) {
        node *new_tail = new node;
        new_tail->next = NULL;

        tail->data = it->data;
        tail->next = new_tail;

        tail = new_tail;
    }

}

bool List::isEmptyList() {
    return (head->next == tail);
}

List List::subList() {
    List res;

    for(node* it = head->next->next;it != NULL && it != tail; it = it->next) {
        res.push_back(it->data);
    }

    return res;
}

void List::push_back(DataType elem) {
    node *new_tail = new node;
    new_tail->next = NULL;

    tail->data = elem;
    tail->next = new_tail;

    tail = new_tail;
}

void List::printList() {
        node *it = head->next;

        while(it != NULL && it != tail) {
            std::cout << it->data << ' ';
            it = it->next;
        }

        std::cout << '\n';
    }

void List::push_front(DataType elem) {

    node *aux = new node;
    aux->data = elem;
    aux->next = head->next;
    head->next = aux;
}

