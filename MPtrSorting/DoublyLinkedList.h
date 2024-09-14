//
// Created by joel-barboza on 30/08/24.
//

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "MPointer.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class DoublyLinkedList
{
public:
    struct Node
    {
        MPointer<T> data;
        Node* prev;
        Node* next;

        Node(T value) : data(MPointer<T>::New()), prev(nullptr), next(nullptr)
        {
            *data = value;
        }
    };

    DoublyLinkedList() : head(nullptr), tail(nullptr), listSize(0)
    {
    }

    void append(T value)
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++listSize;
    }

    MPointer<T>& get(int index)
    {
        Node* current = head;
        int count = 0;

        while (current != nullptr && count < index)
        {
            current = current->next;
            count++;
        }

        if (current != nullptr)
        {
            return current->data;
        }

        throw std::out_of_range("Index out of range");
    }

    void swap(MPointer<T>& a, MPointer<T>& b)
    {
        T temp = *a;
        *a = *b;
        *b = temp;
    }

    void print() const
    {
        Node* current = head;
        while (current)
        {
            std::cout << *current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to clean up nodes
    ~DoublyLinkedList()
    {
        Node* current = head;
        while (current)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Get the size of the list
    int size() const
    {
        return listSize;
    }

    Node* getHead() const
    {
        return head;
    }

private:
    Node* head;
    Node* tail;
    int listSize;
};

#endif
