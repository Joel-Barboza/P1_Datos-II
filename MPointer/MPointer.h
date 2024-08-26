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



    /*MPointer& operator=(auto& other)
    {
        if (typeid(other) == typeid(T))
        {
            std::cout << "Pointer assignment operator" << std::endl;
            return *this;
        }
        if (typeid(MPtr) == other) {
            std::cout << typeid(MPtr).name() << other <<std::endl;
            // delete MPtr;
            // MPtr = new T(*other.MPtr);
            //return *this;
        }

    }

    MPointer& operator=(T other)
    {
        std::cout << other << std::endl;
        return &other;
    }*/

private:
    T* MPtr; // Pointer to the actual data
};

void hello();
#endif //MPOINTER_LIBRARY_H
