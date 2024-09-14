//
// Created by joel-barboza on 30/08/24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "MPointerBase.h"


class LinkedList
{
public:
    struct Node
    {
        MPointerBase* MPointerAddress = nullptr;
        Node* next = nullptr;
        int refCount;

        Node(MPointerBase* val) : MPointerAddress(val), next(nullptr), refCount(1)
        {
        }
    };

    LinkedList() : head(nullptr)
    {
    }

    void insert(MPointerBase* pointer)
    {
        Node* newNode = new Node(pointer);
        if (tail == head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
        }
        /*tail->next = newNode;
        tail = newNode;*/
    }

    void remove(MPointerBase* data)
    {
        Node** current = &head;
        while (*current)
        {
            if ((*current)->MPointerAddress == data)
            {
                Node* toDelete = *current;
                *current = (*current)->next;
                delete toDelete;
                return;
            }
            current = &(*current)->next;
        }
    }

    Node* find(const MPointerBase* pointer) const
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        Node* current = head;
        while (current)
        {
            if (current->MPointerAddress == pointer)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }



    void checkRefCount() const
    {
        if (head == nullptr) return;
        Node* current = head;
        while (current->next != nullptr)
        {
            if (current->next->refCount > 0)
            {
                const Node* toDelete = current->next;
                delete current->next->MPointerAddress;
                current->next = current->next->next;
                delete toDelete;
            };
            current = current->next;
        }
    };

    void printT() const
    {
        if (head == nullptr)
        {
            return;
        }
        Node* current = head;
        while (current)
        {
            std::cout << current << "--";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    Node* head = nullptr;
    Node* tail = nullptr;
};


#endif
