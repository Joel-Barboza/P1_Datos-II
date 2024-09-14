#ifndef MPOINTER_LIBRARY_H
#define MPOINTER_LIBRARY_H

#include <iostream>

#include "MPointerBase.h"
#include "MPointerGC.h"


template <typename T>
class MPointer : public MPointerBase
{
public:
    static MPointer<T> New()
    {
        T* newPtr = new T();
        auto* mp = new MPointer<T>(newPtr);
        int id = MPointerGC::instance().generateId();
        mp->MPtrId = id;

        MPointerGC::instance().savePointer(mp);
        return *mp;
    }

    ~MPointer()
    {
        if (MPtr)
        {
            MPointerGC::instance().deleteReference(this);
        }
    }

    T& operator*()
    {
        return *MPtr;
    }

    MPointer& operator=(const MPointer<T>* RValue)
    {
        if (this != &RValue)
        {
            if (MPtr)
            {
                MPointerGC::instance().deleteReference(this);
            }
            MPtr = RValue.MPtr;
            MPtrId = RValue.MPtrId;
            MPointerGC::instance().incrementMPtrRefs(RValue);
        }

        return RValue;
    }


    MPointer& operator=(T RValue)
    {
        if (MPtr)
        {
            *MPtr = RValue;
        }
        return *this;
    }

private:
    explicit MPointer(T* newPtr)
    {
        MPtr = newPtr;
        MPtrId = MPointerGC::instance().generateId();
    }

    T* MPtr = nullptr;
    int MPtrId = -1;
};

#endif // MPOINTER_LIBRARY_H
