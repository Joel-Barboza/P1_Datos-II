//
// Created by joel-barboza on 21/08/24.
//

#include "MPtr_unittest.h"
#include "gtest/gtest.h"
#include "MPointer.h"

TEST(MPointers, StoreValue)
{
    MPointer<int> pointer = MPointer<int>::New();
    EXPECT_EQ(*pointer, 0); // nullptr
    *pointer = 2;
    EXPECT_EQ(*pointer, 2);
}

TEST(MPointers, OverwriteValue)
{
    MPointer<int> pointer = MPointer<int>::New();
    *pointer = 3;
    *pointer = 4;
    EXPECT_EQ(*pointer, 4);
}

TEST(MPointers, GetPointerValue)
{
    MPointer<int> pointer = MPointer<int>::New();
    *pointer = 5;
    int value = &pointer;
    EXPECT_EQ(value, 5);
}

TEST(MPointers, VerifyTypes)
{
    /*MPointer<int> pointer = MPointer<int>::New();
    MPointer<int> pointer2 = MPointer<int>::New();
    MPointer<int> pointer3 = MPointer<int>::New();
    *pointer = 5;
    pointer2 = pointer;
    pointer3 = 6;
    EXPECT_EQ(&*pointer2, &*pointer);
    EXPECT_EQ(*pointer3, 6);*/
}




