// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "header.hpp"

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}

TEST(Example, first_test) {
SharedPtr <int> ptr;
int* tmp=ptr.get();
EXPECT_EQ(tmp, nullptr);
}

TEST(Example, second_test) {
  int *points = new int (24);

  SharedPtr <int> ptr(points);
  int* tmp=ptr.get();
  EXPECT_EQ(tmp, points);
}

TEST(Example, third_test) {
  int *points = nullptr;

  SharedPtr <int> ptr(points);
  int* tmp=ptr.get();
  EXPECT_EQ(tmp, nullptr);
}

TEST(Example, fourth_test) {
  int *points = new int (227);
  SharedPtr <int> ptr(points);
  SharedPtr <int> ptr2 = ptr;
  EXPECT_EQ(ptr.get(), points);
}

TEST(Example, fifth_test) {
  int *points = new int (227);
  SharedPtr <int> ptr(points);
  SharedPtr <int> ptr2 = ptr;
  bool is_pointer = ptr2;
  EXPECT_EQ(is_pointer, true);
}

class Test_class
{
 public:
  int x;
};

TEST(Example, sixth_test) {
  auto test_class_ptr = new Test_class;
  test_class_ptr ->x=227;
  SharedPtr <Test_class> ptr(test_class_ptr);
  EXPECT_EQ(ptr->x, test_class_ptr->x);
}

TEST(Example, seventh_test) {
  int *points = new int (227);
  SharedPtr <int> ptr(points);
  SharedPtr <int> ptr2;
  SharedPtr <int> ptr3=ptr2=ptr;
  EXPECT_EQ(ptr3.get(), ptr.get());
}

TEST(Example, eight_test) {
  int *points = new int (227);
  SharedPtr <int> ptr(points);
  SharedPtr <int> ptr2=ptr;
  SharedPtr <int> ptr3(std::move(ptr));
  EXPECT_EQ(ptr3.use_count(), 2);
}
