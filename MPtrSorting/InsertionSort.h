//
// Created by joel-barboza on 11/09/24.
//

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H


template <typename T>
void insertionSort(DoublyLinkedList<T>& list, const int n)
{
    T key;
    for (int i = 1; i < n; i++)
    {
        key = *list.get(i);
        int j = i - 1;

        while (j >= 0 && *list.get(j) > key)
        {
            list.get(j + 1) = *list.get(j);
            j = j - 1;
        }
        list.get(j + 1) = key;
    }
}


#endif
