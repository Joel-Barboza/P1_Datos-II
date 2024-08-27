#ifndef MPOINTER_LIBRARY_H
#define MPOINTER_LIBRARY_H
#include <iostream>

template <typename T>
class MPointer
{
public:
    MPointer(T* ptr = nullptr) : MPtr(ptr)
    {
    }

    static MPointer<T> New();

    ~MPointer()
    {
        // delete MPtr;
    }


    T& operator*()
    {
        return *MPtr;
    }

    T operator&()
    {
        return *MPtr;
    }


    MPointer<T>& operator=(const MPointer& RValue)
    {
        MPtr = RValue.MPtr;
        return *this;
    }


    MPointer<T>& operator=(T RValue)
    {
        *MPtr = RValue;
        return *this;
    }

private:
    T* MPtr; // Pointer to the actual data
};


#endif //MPOINTER_LIBRARY_H
