#include "DoublyLinkedList.h"
DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
}
void DoublyLinkedList::insertNodeAfter(Node* prevNode, Node* node)
{
	if (head == nullptr && tail == nullptr) //appending as head
	{
		head = node;
		tail = node;
		return;
	}
	if (prevNode->next == nullptr) 	//inserting at the end
	{
		prevNode->next = node;
		node->prev = prevNode;
		tail = node;
		return;
	}
	//inserting in between
	node->next = prevNode->next;
	node->prev = prevNode;
	prevNode->next->prev = node;
	prevNode->next = node;
}
void DoublyLinkedList::insertNodeBefore(Node* nextNode, Node* node)
{
	if (head == nullptr && tail == nullptr) //appending as head
	{
		head = node;
		tail = node;
		return;
	}
	if (nextNode->prev == nullptr) //inserting at the beginning
	{
		nextNode->prev = node;
		node->next = nextNode;
		head = node;
		return;
	}
	//inserting in between
	node->next = nextNode;
	node->prev = nextNode->prev;
	nextNode->prev->next = node;
	nextNode->prev = node;
}
void DoublyLinkedList::deleteNode(Node* node)
{
	if (node->next == nullptr && node->prev == nullptr) //deleting single node from list
	{
		head = nullptr;
		tail = nullptr;
		delete node;
		return;
	}
	if (node->next == nullptr) //deleting last node
	{
		node->prev->next = nullptr;
		tail = node->prev;
		delete node;
		return;
	}
	if (node->prev == nullptr) //deleting first node
	{
		node->next->prev = nullptr;
		head = node->next;
		delete node;
		return;
	}
	//deleting node in between
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete node;
}
void DoublyLinkedList::print(Node* node, bool ALL)
{
	if (node == nullptr)
		return;
	cout << node->data;
	if (ALL)
	{
		while (node->next != nullptr)
		{
			cout << " " << node->next->data;
			node = node->next;
		}
	}
	cout << endl;
}
DoublyLinkedList::~DoublyLinkedList()
{
	while (head != nullptr) //deallocating memory
	{
		deleteNode(head);
	}
}