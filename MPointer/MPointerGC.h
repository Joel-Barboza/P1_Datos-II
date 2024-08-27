//
// Created by joel-barboza on 26/08/24.
//

#ifndef MPOINTERGC_H
#define MPOINTERGC_H
#include "MPointer.h"

class MPointerGC
{
public:
    static MPointerGC& instance();

private:
    MPointerGC();
    ~MPointerGC();
    MPointerGC(const MPointerGC&);
    MPointerGC& operator=(const MPointerGC&);
};

#endif //MPOINTERGC_H
