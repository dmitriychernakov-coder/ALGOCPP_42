#pragma once
#include<iostream>
struct Node
{
	Node(int _data)
	{
		data = _data;
		next_ptr = nullptr;
	}
	int data;
	Node* next_ptr;
	Node* prev_ptr;
};

class List
{
public:
	List();
	~List();
	bool is_empty()
	{
		return first_ptr == nullptr;
	}
	void insert_back(int _value)
	{
		Node* new_node = new Node(_value);
		if (is_empty())
		{
			first_ptr = last_ptr = new_node;
		}
		else
		{
			last_ptr->next_ptr = new_node;
			last_ptr = new_node;
		}
	}
	void insert_front(int _value)
	{
		Node* new_node = new Node(_value);
		new_node->next_ptr = first_ptr;
		first_ptr = new_node;
	}
	void print()
	{
		Node* print_ptr = first_ptr;
		while (print_ptr != nullptr)
		{
			std::cout << print_ptr->data << " ";
			print_ptr = print_ptr->next_ptr;
		}
	}
	bool find(int value)
	{
		if (is_empty())
		{
			return false;
		}
		Node* find_ptr = first_ptr;
		while (find_ptr != nullptr)
		{
			if (find_ptr->data == value)
			{
				return true;
			}
			find_ptr = find_ptr->next_ptr;
		}
		return false;
	}

private:
	Node* first_ptr = nullptr;
	Node* last_ptr = nullptr;
};

List::List()
{
	first_ptr = last_ptr = nullptr;
}

List::~List()
{
	Node* current_ptr = first_ptr; 
	Node* delete_ptr;
	while (current_ptr != nullptr)
	{
		delete_ptr = current_ptr;
		current_ptr = current_ptr->next_ptr;
		delete delete_ptr;
	}
}
