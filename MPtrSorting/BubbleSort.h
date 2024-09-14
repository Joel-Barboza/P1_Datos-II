//
// Created by joel-barboza on 30/08/24.
//

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "DoublyLinkedList.h"

template <typename T>
void bubbleSort(DoublyLinkedList<T>& list)
{
    int n = list.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*list.get(j) > *list.get(j + 1))
            {
                list.swap(list.get(j), list.get(j + 1));
            }
        }
    }
}


#endif
