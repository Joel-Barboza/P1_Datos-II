#include <iostream>
#include <MPointer.h>

#include "BubbleSort.h"
#include "DoublyLinkedList.h"
#include "InsertionSort.h"
#include "QuickSort.h"

int main()
{
    DoublyLinkedList<int> list;

    for (int i = 0; i < 15; i++)
    {
        list.append(rand() % 1000);
    }

    std::cout << "Lista antes de ordenar: ";
    list.print();

    bubbleSort(list);
    quickSort(list, 0, list.size() - 1);
    insertionSort(list, list.size());
    std::cout << "Lista después de ordenar: ";
    list.print();


    return 0;
}
