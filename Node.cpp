#pragma once
#include "Node.h"
Node::Node(unsigned long long int data)
{
	this->data = data;
	next = nullptr;
	prev = nullptr;
}