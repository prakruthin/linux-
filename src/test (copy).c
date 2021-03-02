#include "mystring.h"
#include "myutils.h"
#include "bitmask.h"
#include <gtest/gtest.h>

 

TEST(mystring, stringlenTest) {

    EXPECT_EQ(6, Mystrlen("hello"));
    EXPECT_EQ(7, Mystrlen("bamboo"));
    EXPECT_EQ(6, Mystrlen("\0"));

}

TEST(mystring, MystrcpyTest) {

    EXPECT_STREQ("world", Mystrcpy("hello","world"));
    EXPECT_STREQ("programming", Mystrcpy("C","programming"));

}

TEST(mystring, MystrcatTest) {

    EXPECT_STREQ("helloworld", Mystrcat("hello","world"));
    EXPECT_STREQ("Cprogramming", Mystrcat("C","programming"));

}

TEST(mystring, MystrcmpTest) {

    EXPECT_EQ(1, Mystrcmp("hello","work"));
    EXPECT_EQ(-1, Mystrcmp("bamboo","grey"));
    EXPECT_EQ(0, Mystrcmp("book","book"));

}


 

 

int main1(int argc, char **argv)

{

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();

}