#pragma once
#include "Node.h"
#include <queue>

// Template class for Queue
template <typename T>
class Queue
{
public:
	Queue();
	virtual ~Queue();
	Queue(const Queue &other);
	Queue& operator=(const Queue &other);

	void Put(T newValue);
	T Get();
	int Size();
	void Clear();
	void Print();
	std::vector<T> ToVector();

private:
	Node<T>* head;
	int size;
};

template <typename T>
Queue<T>::Queue()
{
	head = new Node<T>();
	size = 0;
}

template <typename T>
Queue<T>::~Queue()
{
    while(head)
    {
        const Node<T>* temp = head;
        head = temp->next;
        delete temp;
    }
}

template <typename T>
Queue<T>::Queue(const Queue& other)
{
	head = other.head;
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
= default;

template <typename T>
void Queue<T>::Put(T newValue)
{
	size++;
	head->PushBack(head, newValue);
}

template <typename T>
T Queue<T>::Get()
{
	if (size == 0) return NULL;
	size--;
	T temp = head->GetValueAt(head);
	head->DeleteAt(&head, head);
	return temp;
}

template <typename T>
int Queue<T>::Size()
{
	return size;
}

template <typename T>
void Queue<T>::Clear()
{
	while(head)
	{
		const Node<int>* temp = head;
		head = temp->next;
		delete temp;
	}

	head->value = NULL;
}

template <typename T>
void Queue<T>::Print()
{
	if (size == 0) return;
	head->Print(head);
	std::cout << std::endl;
}

template <typename T>
std::vector<T> Queue<T>::ToVector()
{
	std::vector<T> temp;
	int counter = 0;
	while (counter != size)
	{
		int i = 0;
		
		auto pointer = head;
		
		while(i != counter)
		{
			pointer = pointer->next;
			i++;
		}
		counter++;

		temp.push_back(head->GetValueAt(pointer));
	}
	return temp;
}