//
// Created by joel-barboza on 11/09/24.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "DoublyLinkedList.h"

template <typename T>
int partition(DoublyLinkedList<T> &list, int low, int high) {


    int pivot = *list.get(high);

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {


        if (*list.get(j) <= pivot) {
            i++;
            list.swap(list.get(i), list.get(j));
        }
    }


    list.swap(list.get(i + 1), list.get(high));


    return (i + 1);
}

template <typename T>
void quickSort(DoublyLinkedList<T> &list, int low, int high) {


    if (low < high) {


        int pi = partition(list, low, high);

        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

#endif //QUICKSORT_H
