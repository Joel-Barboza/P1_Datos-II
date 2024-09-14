#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <pthread.h>
#include <unistd.h>
#include "LinkedList.h"


class MPointerGC
{
public:
    static MPointerGC& instance()
    {
        static MPointerGC instance;
        return instance;
    }


    void savePointer(MPointerBase* ptr)
    {
        pthread_mutex_lock(&gcMutex);
        pointers.insert(ptr);
        pthread_mutex_unlock(&gcMutex);
    }


    void deleteReference(const MPointerBase* ptr)
    {
        pthread_mutex_lock(&gcMutex);
        if (pointers.find(ptr) != nullptr)
        {
            --pointers.find(ptr)->refCount;
        }
        pthread_mutex_unlock(&gcMutex);
    }


    void incrementMPtrRefs(const MPointerBase* ptr) const
    {
        pointers.find(ptr)->refCount++;
    }


    int generateId()
    {
        return ID++;
    }

private:
    int ID = 0;

    MPointerGC() : running(true)
    {
        pthread_mutex_init(&gcMutex, nullptr);
        pthread_create(&gcThread, nullptr, &MPointerGC::run, this);
    }


    ~MPointerGC()
    {
        running = false;
        pthread_join(gcThread, nullptr);
        pthread_mutex_destroy(&gcMutex);
    }


    MPointerGC(const MPointerGC&) = delete;
    MPointerGC& operator=(const MPointerGC&) = delete;


    static void* run(void* arg)
    {
        MPointerGC* gc = static_cast<MPointerGC*>(arg);
        while (gc->running)
        {
            pthread_mutex_lock(&gc->gcMutex);

            gc->pointers.checkRefCount();

            pthread_mutex_unlock(&gc->gcMutex);
            sleep(1);
        }
        return nullptr;
    }


    LinkedList pointers;
    pthread_mutex_t gcMutex;

    pthread_t gcThread;
    bool running;
};

#endif
