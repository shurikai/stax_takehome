//
// Created by Jason Chestnut on 12/28/24.
//

#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(LLTest, ComputesLength) {
    LinkedList *test_list = new LinkedList("hello");
    EXPECT_EQ(test_list->size(), 5);
    delete test_list;

    test_list = new LinkedList("");
    EXPECT_EQ(test_list->size(), 0);
    delete test_list;
}

TEST(LLTest, HandlesStrings) {
    LinkedList *test_list = new LinkedList("hello");
    EXPECT_EQ(test_list->get_string(), "hello");
    delete test_list;
}

TEST(LLTest, HasIterator) {
    LinkedList *test_list = new LinkedList("hello");
    std::string test_string = "";
    for (auto iter = test_list->begin(); iter != test_list->end(); ++iter) {
        test_string += *iter;
    }

    EXPECT_EQ(test_string, "hello");
}

TEST(LLTest, CanUseIndexOperator) {
    LinkedList test_list("hello");

    EXPECT_EQ(test_list[0], 'h');
    EXPECT_EQ(test_list[1], 'e');
    EXPECT_EQ(test_list[2], 'l');
    EXPECT_EQ(test_list[3], 'l');
    EXPECT_EQ(test_list[4], 'o');
}
