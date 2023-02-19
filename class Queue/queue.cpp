#include "queue.h"


Node::Node(size_t num)
{
	this->data = num;

	this->previous_node = nullptr;
	this->next_node = nullptr;
}



Queue::Queue()
{
	//std::cerr << "DEFAULT CONSTRUCTOR" << std::endl;

	this->begin_node = nullptr;
	this->end_node = nullptr;
}


Queue::Queue(const Queue& queue)
{
	//std::cerr << "COPY" << std::endl;

	try
	{
		if (queue.begin_node == nullptr && this->end_node == nullptr)
		{
			this->begin_node = nullptr;
			this->end_node = nullptr;

			throw "ERROR: COPIED QUEUE IS EMPTY!";
		}

		Node* temp_node = queue.begin_node;
		while (temp_node != nullptr)
		{
			this->push(temp_node->data);
			temp_node = temp_node->next_node;
		}
	}

	catch (const char* error_str)
	{
		std::cerr << error_str << std::endl;
	}
}


Queue::Queue(Queue&& queue) noexcept
{
	//std::cerr << "MOVE" << std::endl;

	this->begin_node = queue.begin_node;
	this->end_node = queue.end_node;

	queue.begin_node = nullptr;
	queue.end_node = nullptr;
}


Queue::Queue(Node* node)
{
	this->begin_node = node;
	this->end_node = node->next_node;

	node = nullptr;
}


Queue::Queue(unsigned long long int count, ...)
{
	va_list list = nullptr;
	va_start(list, count);
	for (size_t i = 0; i < count; ++i)
	{
		this->push(va_arg(list, int));
	}
	va_end(list);
}



//Queue::~Queue()
//{
//	//std::cerr << "DESTRUCTOR" << std::endl;
//
//	while (this->begin_node != nullptr)
//	{
//		pop();
//	}
//}




void Queue::push(size_t num)
{
	try
	{
		if (this->end_node == nullptr && this->begin_node == nullptr)
		{
			Node* new_node = new Node(num);

			this->begin_node = new_node;
			this->end_node = new_node;
		}

		else if (this->end_node != nullptr && this->begin_node != nullptr)
		{
			Node* new_node = new Node(num);

			this->end_node->next_node = new_node;
			new_node->previous_node = this->end_node;
			this->end_node = new_node;
		}

		else
		{
			delete this;
			throw "ERROR: QUEUE IS BROKEN";
		}
	}

	catch (const char* error_str)
	{
		std::cerr << error_str << std::endl;
	}
}


void Queue::pop()
{
	try
	{

		if (this->end_node != nullptr && this->begin_node != nullptr)
		{
			Node* temp_node = this->begin_node->next_node;
			delete this->begin_node;
			this->begin_node = temp_node;

			// this->begin_node = this->begin_node->next_node; // or
		}

		else if (this->end_node == nullptr && this->begin_node == nullptr)
		{
			throw "ERROR: COPIED QUEUE IS EMPTY!";
		} 

		else
		{
			delete this;
			throw "ERROR: QUEUE IS BROKEN";
		}
	}

	catch (const char* error_str)
	{
		std::cerr << error_str << std::endl;
	}
}



void Queue::print() const
{
	Node* temp_node = this->begin_node;

	while (temp_node != nullptr)
	{
		std::cout << temp_node->data << " ";
		temp_node = temp_node->next_node;
	}
	std::cout << std::endl;
}



bool Queue::comparing(unsigned long long int num)
{
	Node* temp_node = this->begin_node;
	while (temp_node != nullptr)
	{
		if (temp_node->data == num)
		{
			return true;
		}
		temp_node = temp_node->next_node;
	}
	return false;
}




Node* Queue::copy_in(Queue& queue_copy) const
{
	try
	{
		if (!(this->begin_node != nullptr && this->end_node != nullptr))
		{
			throw "ERROR: COPIED QUEUE IS EMPTY!";
		}

		Node* temp_node = this->begin_node;
		while (temp_node != nullptr)
		{
			queue_copy.push(temp_node->data);
			temp_node = temp_node->next_node;
		}

		return queue_copy.begin_node;
	}

	catch (const char* error_str)
	{
		std::cerr << error_str << std::endl;
		return nullptr;
	}
}



Node* Queue::operator+(Queue& queue) const
{
	Queue addition_stack = *this;

	Node* temp_node = queue.begin_node;
	while (temp_node != nullptr)
	{
		addition_stack.push(temp_node->data);
		temp_node = temp_node->next_node;
	}

	//addition_stack.print();

	return addition_stack.begin_node;
}


Node* Queue::operator*(Queue& queue) const
{
	Queue intersection_stack;

	Node* temp_node = this->begin_node;
	while (temp_node != nullptr)
	{
		if (queue.comparing(temp_node->data) == true)
		{
			intersection_stack.push(temp_node->data);
		}
		temp_node = temp_node->next_node;
	}

	//intersection_stack.print();

	return intersection_stack.begin_node;
}
