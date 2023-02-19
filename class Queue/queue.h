#pragma once
#include <iostream>
#include <stdarg.h> // для работы конструктора с переменным количеством параметров - Queue(unsigned long long int count, ...);


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

	Queue(const Queue& queue); // copy constructor
	Queue(Queue&& queue) noexcept; // move constructor
	Queue(Node* node);
	Queue(unsigned long long int count, ...);

	~Queue() = default;

private:
	Node* begin_node;
	Node* end_node;

public:
	void push(size_t num);
	void pop();

	void print() const;

	bool comparing(unsigned long long int num);

	Node* copy_in(Queue& queue_copy) const;
	Node* operator+(Queue& queue) const;
	Node* operator*(Queue& queue) const;

};


