#include "queue.h"


Node::Node(size_t num)
{
	this->data = num;

	this->previous_node = nullptr;
	this->next_node = nullptr;
}



Queue::Queue()
{
	this->begin_node = nullptr;
	this->end_node = nullptr;
}

Queue::~Queue()
{
	while (this->begin_node != nullptr)
	{
		pop();
	}
}



void Queue::push(size_t num)
{
	Node* new_node = new Node(num);

	if (this->end_node == nullptr && this->begin_node == nullptr)
	{
		this->begin_node = new_node;
		this->end_node = new_node;
	}

	else if (this->end_node != nullptr && this->begin_node != nullptr)
	{
		this->end_node->next_node = new_node;
		new_node->previous_node = this->end_node;
		this->end_node = new_node;
	}

	else
	{
		std::cerr << "ERROR" << std::endl;
	}
}

void Queue::pop()
{
	if (this->end_node == nullptr && this->begin_node == nullptr)
	{
		std::cerr << "ERROR: QUEUE IS EMPTY!" << std::endl;
		return;
	} 
	
	else if (this->end_node != nullptr && this->begin_node != nullptr)
	{
		Node* temp_node = this->begin_node->next_node;
		delete this->begin_node;
		this->begin_node = temp_node;


		// ÍÅ ÓÂÅÐÅÍ ÊÀÊ ÏÐÀÂÈËÜÍÎ ÍÀÏÈÑÀÒÜ: ÈËÈ ÊÀÊ ÂÛØÅ, ÈËÈ ÊÀÊ ÍÈÆÅ. ÎÁÀ ÂÀÐÈÀÍÒÀ ÐÀÁÎ×ÈÅ.
		// this->begin_node = this->begin_node->next_node;
	}
	
	else
	{
		std::cerr << "ERROR" << std::endl;
	}
}

void Queue::print()
{
	Node* temp = this->begin_node;

	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		temp = temp->next_node;
	}
}

