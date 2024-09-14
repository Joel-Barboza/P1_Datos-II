//
// Created by joel-barboza on 13/09/24.
//

#ifndef MPOINTERBASE_H
#define MPOINTERBASE_H

class MPointerBase
{
protected:
    void* memoryAddress;
    int refCount;

public:
    MPointerBase() : memoryAddress(nullptr), refCount(1)
    {
    }

    void incrementRefCount() { refCount++; }
    void decrementRefCount() { refCount--; }
    int getRefCount() const { return refCount; }

    void* getMemoryAddress() const { return memoryAddress; }
};


#endif
