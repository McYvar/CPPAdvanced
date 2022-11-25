#pragma once
#include <cstddef>
#include <iostream>

// Template class for doubly linked list
template <typename T>
class Node
{
public:
    Node();
    Node(T value);
    virtual ~Node();
    Node(const Node<T>& other);
    Node(const Node<T>* other);
    Node<T>& operator=(const Node<T> &other);

    void InsertAfter(Node<T>*& node, T newValue);
    void InsertBefore(Node<T>*& node, T newValue);

    void PushBack(Node<T>*& head, T newValue);
    void PushFront(Node<T>*& head, T newValue);

    void DeleteAt(Node<T>** head, Node<T>* del);

    T GetValueAt(Node<T>* node);

    void Print(Node<T>* head);
    
    Node<T>* prev;
    Node<T>* next;

private:
    T value;
    bool initialized;
};

template <typename T>
Node<T>::Node()
{
    prev = NULL;
    next = NULL;
    value = NULL;
    initialized = false;
}

template <typename T>
Node<T>::Node(T newValue)
{
    prev = NULL;
    value = newValue;
    next = NULL;
    initialized = true;
}

template <typename T>
Node<T>::~Node()
=default;

template <typename T>
Node<T>::Node(const Node<T>& other)
{
    prev = other.prev;
    value = other.value;
    next = other.next;
    initialized = other.initialized;
}

template <typename T>
Node<T>& Node<T>::operator=(const Node<T>& other)
=default;

template <typename T>
void Node<T>::InsertAfter(Node<T>*& node, T newValue)
{
    if (!node) return;
    
    if (!initialized)
    {
        PushBack(node, newValue);
        return;
    }
    
    auto newNode = new Node<T>(newValue);

    if (node->next)
    {
        node->next->prev = newNode;
        newNode->next = node->next;
    }
    node->next = newNode;
    newNode->prev = node;
}

template <typename T>
void Node<T>::InsertBefore(Node<T>*& node, T newValue)
{
    if (!node) return;
    
    if (!initialized)
    {
        PushBack(node, newValue);
        return;
    }
    
    if (node->prev)
    {
        auto newNode = new Node<T>(newValue);
        auto temp = new Node<T>(*node);
        newNode->prev = node->prev;
        newNode->next = node;
        node->prev = newNode;
        temp->prev->next = newNode;
        delete temp;
    }
    else
    {
        auto newNode = new Node<T>(*node);
        newNode->next = node->next;
        newNode->prev = node;
        node->next = newNode;
        node->value = newValue;
    }
}

template <typename T>
void Node<T>::PushBack(Node<T>*& head, T newValue)
{
    if (!head) return;
    
    if (!initialized)
    {
        head->value = newValue;
        head->initialized = true;
        return;
    }

    auto pointer = head;
    
    while(pointer->next)
    {
        pointer = pointer->next;
    }

    InsertAfter(pointer, newValue);
}

template <typename T>
void Node<T>::PushFront(Node<T>*& head, T newValue)
{
    if (!head) return;
    
    if (!initialized)
    {
        PushBack(head, newValue);
        return;
    }
    InsertBefore(head, newValue);
}

template <typename T>
void Node<T>::DeleteAt(Node<T>** head, Node<T>* del)
{
    if (!*head || !del) return;

    if (*head == del && (*head)->next) *head = del->next;
    else if (*head == del)
    {
        (*head)->value = NULL;
        (*head)->initialized = false;
        return;
    }

    if (del->next) del->next->prev = del->prev;

    if (del->prev) del->prev->next = del->next;

    delete del;
}

template <typename T>
T Node<T>::GetValueAt(Node<T>* node)
{
    return node->value;
}

template <typename T>
void Node<T>::Print(Node<T>* head)
{
    auto temp = head;  
    while (temp)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
}
