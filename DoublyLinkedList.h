#pragma once
#include "Node.h"
class DoublyLinkedList {
public:
	Node* head;
	Node* tail;
	DoublyLinkedList();
	void insertNodeAfter(Node* prevNode, Node* node);
	void insertNodeBefore(Node* nextNode, Node* node);
	void deleteNode(Node* node);
	static void print(Node* node, bool ALL);
	~DoublyLinkedList();
};

