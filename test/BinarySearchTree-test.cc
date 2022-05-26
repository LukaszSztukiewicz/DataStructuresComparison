#include "BinarySearchTree.h"
#include "gtest/gtest.h"

// create tests for BinarySearchTree class remove inorder
TEST(BinarySearchTree, remove_inorder) {
  BinarySearchTree *tree = new BinarySearchTree();
  for (int i = 0; i < 10; i++) {
    tree->insert(new InsertData(i));
  }
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(i, tree->search(new InsertData(i))->getIndex());
  }
  for (int i = 0; i < 10; i++) {
    tree->remove(new InsertData(i));
  }
  EXPECT_EQ(nullptr, tree->search(new InsertData(0)));
}

// create tests for BinarySearchTree class remove inreverse
TEST(BinarySearchTree, remove_inreverse) {
  BinarySearchTree *tree = new BinarySearchTree();
  for (int i = 0; i < 10; i++) {
    tree->insert(new InsertData(i));
  }
  for (int i = 9; i >= 0; i--) {
    EXPECT_EQ(i, tree->search(new InsertData(i))->getIndex());
  }
  for (int i = 9; i >= 0; i--) {
    tree->remove(new InsertData(i));
  }
  EXPECT_EQ(nullptr, tree->search(new InsertData(0)));
}

// create tests for BinarySearchTree class remove inrandom
TEST(BinarySearchTree, remove_inrandom) {
  BinarySearchTree *tree = new BinarySearchTree();
  for (int i = 0; i < 10; i++) {
    tree->insert(new InsertData(i));
  }
  std::vector<int> indexes;
  for (int i = 0; i < 10; i++) {
    indexes.push_back(i);
  }
  std::random_shuffle(indexes.begin(), indexes.end());
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(indexes[i], tree->search(new InsertData(indexes[i]))->getIndex());
  }
  for (int i = 0; i < 10; i++) {
    tree->remove(new InsertData(indexes[i]));
  }
  EXPECT_EQ(nullptr, tree->search(new InsertData(0)));
}