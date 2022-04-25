#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "DoublyLinkedList.h"
#define MAX_ITERATORS 10
#define MAX_CHAR 11 //unsigned long long int plus 1 <- maximal input 
using namespace std;
void setToNullptr(Node** iterators);
void setToZero(char* command);
void readInput(char* command, Node** selected, Node** iterators, DoublyLinkedList* List);
void initializeIterator(char* command, Node** iterators, DoublyLinkedList* List);
void moveIteratorForward(char* command, Node** iterators, DoublyLinkedList* List);
void moveIteratorBackwards(char* command, Node** iterators, DoublyLinkedList* List);
void addBefore(char* command, Node** iterators, DoublyLinkedList* List);
void addAfter(char* command, Node** iterators, DoublyLinkedList* List);
void removeElement(char* command, Node** iterators, DoublyLinkedList* List);
void printList(char* command, Node** iterators, DoublyLinkedList* List);
int main()
{
	DoublyLinkedList* List = new DoublyLinkedList();
	Node* iterators[MAX_ITERATORS];
	setToNullptr(iterators);
	char command[MAX_CHAR];
	setToZero(command);
	while (true)
	{
		
		scanf_s("%s", command, MAX_CHAR);
		if (feof(stdin) != 0)
		{
			break;
		}


		if (command[0] == 'i')
		{
			initializeIterator(command, iterators, List);
		}


		if (command[0] == '+')
		{
			moveIteratorForward(command, iterators, List);
		}


		if (command[0] == '-')
		{
			moveIteratorBackwards(command, iterators, List);
		}


		if (command[0] == '.')
		{
			addBefore(command, iterators, List);
		}


		if (command[0] == 'A')
		{
			addAfter(command, iterators, List);
		}


		if (command[0] == 'P')
		{
			printList(command, iterators, List);
		}


		if (command[0] == 'R')
		{
			removeElement(command, iterators, List);
		}
	}
	delete List;
	return 0;
}

void setToNullptr(Node** iterators)    
{
	for (int i = 0; i < MAX_ITERATORS; i++)
	{
		iterators[i] = nullptr;
	}
}

void setToZero(char* command)
{
	for (int i = 0; i < MAX_CHAR; i++)
	{
		command[i] = '0';
	}
}

void readInput(char* command, Node** selected, Node** iterators, DoublyLinkedList* List)
{
	int position;

	if (command[0] == 'B')
	{
		*selected = List->head;						//pointer to the beginning of list
	}
	else if (command[0] == 'E')
	{
		*selected = List->tail;						//pointer to the end of list
	}
	else
	{
		position = command[0] - '0';
		*selected = iterators[position];				//pointer to exact node
	}
}

void initializeIterator(char* command, Node** iterators, DoublyLinkedList* List)
{
	int position;
	Node* selected = nullptr;
	int index = 0;

	scanf_s("%s", command, MAX_CHAR);
	index = command[0] - '0';

	scanf_s("%s", command, MAX_CHAR);
	if (command[0] == 'B')				//initializing iterator at the beginning of list
	{
		selected = List->head;
	}
	else if (command[0] == 'E')			//initializing iterator at the end of list
	{
		selected = List->tail;
	}
	else
	{
		position = command[0] - '0';

		if (List->head != nullptr)
		{
			selected = iterators[position];		//initializing at the specific field
		}
		else
		{
			selected = nullptr;
		}
	}
	iterators[index] = selected;
}

void moveIteratorForward(char* command, Node** iterators, DoublyLinkedList* List)
{
	int position;

	scanf_s("%s", command, MAX_CHAR);
	position = command[0] - '0';

	if (iterators[position] != nullptr && iterators[position]->next != nullptr)
	{
		iterators[position] = iterators[position]->next;		//moving iterator to the next node
	}
	else
	{
		iterators[position] = List->tail;						//appending iterator at the end of list if goes outside of range	
	}
}

void moveIteratorBackwards(char* command, Node** iterators, DoublyLinkedList* List)
{
	int position;

	scanf_s("%s", command, MAX_CHAR);
	position = command[0] - '0';

	if (iterators[position] != nullptr && iterators[position]->prev != nullptr)
	{
		iterators[position] = iterators[position]->prev;	//moving iterator to the previous node
	}
	else
	{
		iterators[position] = List->head;					//appending iterator at the beginning of list goes outside of range
	}
}

void addBefore(char* command, Node** iterators, DoublyLinkedList* List)
{
	unsigned long long int substance = 0;
	Node* selected = nullptr;

	scanf_s("%s", command, MAX_CHAR);
	readInput(command, &selected, iterators, List);

	scanf_s("%s", command, MAX_CHAR);
	sscanf_s(command, "%llu", &substance);

	Node* node = new Node(substance);
	List->insertNodeBefore(selected, node);
}

void addAfter(char* command, Node** iterators, DoublyLinkedList* List)
{
	unsigned long long int substance = 0;
	Node* selected = nullptr;

	scanf_s("%s", command, MAX_CHAR);
	readInput(command, &selected, iterators, List);

	scanf_s("%s", command, MAX_CHAR);
	sscanf_s(command, "%llu", &substance);

	Node* node = new Node(substance);
	List->insertNodeAfter(selected, node);
}

void removeElement(char* command, Node** iterators, DoublyLinkedList* List)
{
	Node* selected = nullptr;
	scanf_s("%s", command, MAX_CHAR);

	readInput(command, &selected, iterators, List);
	for (int i = 0; i < MAX_ITERATORS; i++)
	{
		if (selected == iterators[i])
		{
			if (selected->next == nullptr)
			{
				iterators[i] = iterators[i]->prev;
			}
			else
			{
				iterators[i] = iterators[i]->next;
			}
		}
	}
	if (selected != nullptr)
	{
		List->deleteNode(selected);
	}
}

void printList(char* command, Node** iterators, DoublyLinkedList* List)
{
	scanf_s("%s", command, MAX_CHAR);
	if (command[0] == 'A')
	{
		List->print(List->head, true);
	}
	else
	{
		int position = command[0] - '0';
		List->print(iterators[position], false);
	}
}