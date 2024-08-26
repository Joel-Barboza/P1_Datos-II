#include "MPointer.h"

#include <iostream>

template <typename T>
MPointer<T> MPointer<T>::New()
{
    T* newPtr = new T(); // Reserva memoria para un objeto de tipo T
    return MPointer<T>(newPtr); // Retorna una instancia de MPointer
};

template class MPointer<int>;
template class MPointer<bool>;
template class MPointer<char>;
template class MPointer<long>;
template class MPointer<float>;
template class MPointer<double>;

void hello()
{
    std::cout << "Hello, from MPointer lib" << std::endl;
}
