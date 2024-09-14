//
// Created by joel-barboza on 21/08/24.
//

#include "gtest/gtest.h"
#include "MPointer.h"
#include "MPointerGC.h"

TEST(MPointerGC, SingletonInstance)
{
    MPointerGC& gc1 = MPointerGC::instance();
    MPointerGC& gc2 = MPointerGC::instance();
    EXPECT_EQ(&gc1, &gc2);
}

TEST(MPointerGC, SavePointer)
{
    MPointer<int> pointer = MPointer<int>::New();
    MPointerGC& gc = MPointerGC::instance();

    EXPECT_NO_THROW(gc.savePointer(&pointer));
}

TEST(MPointerGC, DeleteReference)
{
    MPointer<int> pointer = MPointer<int>::New();
    MPointerGC& gc = MPointerGC::instance();

    gc.savePointer(&pointer);
    gc.deleteReference(&pointer);

    EXPECT_NO_THROW(gc.deleteReference(&pointer));
}


TEST(MPointerGC, GenerateId)
{
    MPointerGC& gc = MPointerGC::instance();
    int id1 = gc.generateId();
    int id2 = gc.generateId();

    EXPECT_NE(id1, id2);
}
