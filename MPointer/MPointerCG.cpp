//
// Created by joel-barboza on 26/08/24.
//

#include "MPointer.h"
#include "MPointerGC.h"

MPointerGC& MPointerGC::instance()
{
    static MPointerGC instance_;
    return instance_;
}

MPointerGC::MPointerGC() = default;

MPointerGC::~MPointerGC() = default;

MPointerGC::MPointerGC(const MPointerGC&) = default;

MPointerGC& MPointerGC::operator=(const MPointerGC&) { return *this; }



