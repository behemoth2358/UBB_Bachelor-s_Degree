#ifndef LIST_H
#define LIST_H

#include <iostream>

typedef int DataType;

struct node {
	DataType data;
	node* next; 
};

class List {

private:
	node* head;
	node* tail;
	void destroy(node* current);
	
public:
	List();
	List(const List& other);
	DataType getHead();
	bool isEmptyList();
	List subList();
	void push_back(DataType elem);
	void push_front(DataType elem);
	void printList();
	~List();
};

#endif
