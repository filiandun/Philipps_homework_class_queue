#pragma once
#include <iostream>


class Node
{
public:
	Node() = delete;
	Node(size_t num);

public:
	size_t data;

	Node* previous_node;
	Node* next_node;

};


class Queue
{
public:
	Queue();
	~Queue();

private:
	Node* begin_node;
	Node* end_node;

public:
	void push(size_t num);
	void pop();
	void print();

};


