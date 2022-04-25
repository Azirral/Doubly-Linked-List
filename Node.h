#pragma once
#include <iostream>
using namespace std;
class Node 
{
public:
	unsigned long long int  data;
	Node* next;
	Node* prev;
	explicit Node(unsigned long long int data);
};