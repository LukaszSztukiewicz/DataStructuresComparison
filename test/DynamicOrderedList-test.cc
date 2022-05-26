#include "DynamicOrderedList.h"
#include "gtest/gtest.h"

TEST(DynamicOrderedListUnidirectional, remove_inorder) {
  DynamicOrderedListUnidirectional *list = new DynamicOrderedListUnidirectional();
  for (int i = 0; i < 10; i++) {
    list->insert(new InsertData(i));
  }
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(i, list->search(new InsertData(i))->getIndex());
  }
  for (int i = 0; i < 10; i++) {
    list->remove(new InsertData(i));
  }
  EXPECT_EQ(nullptr, list->search(new InsertData(0)));
}

TEST(DynamicOrderedListUnidirectional, remove_inreverse) {
  DynamicOrderedListUnidirectional *list = new DynamicOrderedListUnidirectional();
  for (int i = 0; i < 10; i++) {
    list->insert(new InsertData(i));
  }
  for (int i = 9; i >= 0; i--) {
    EXPECT_EQ(i, list->search(new InsertData(i))->getIndex());
  }
  for (int i = 9; i >= 0; i--) {
    list->remove(new InsertData(i));
  }
  EXPECT_EQ(nullptr, list->search(new InsertData(0)));
}

TEST(DynamicOrderedListUnidirectional, remove_inrandom) {
  DynamicOrderedListUnidirectional *list = new DynamicOrderedListUnidirectional();
  for (int i = 0; i < 10; i++) {
    list->insert(new InsertData(i));
  }
  std::vector<int> indexes;
  for (int i = 0; i < 10; i++) {
    indexes.push_back(i);
  }
  std::random_shuffle(indexes.begin(), indexes.end());
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(indexes[i], list->search(new InsertData(indexes[i]))->getIndex());
  }
  for (int i = 0; i < 10; i++) {
    list->remove(new InsertData(indexes[i]));
  }
  EXPECT_EQ(nullptr, list->search(new InsertData(0)));
}
