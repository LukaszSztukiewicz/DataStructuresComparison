#ifndef BALANCEDBINARYSEARCHTREE_H
#define BALANCEDBINARYSEARCHTREE_H

#include "BinarySearchTree.h"
#include "DataStructure.h"

class BalancedBinarySearchTreeNode {
public:
  InsertData *data;
  int key;
  int height;
  BalancedBinarySearchTreeNode *left;
  BalancedBinarySearchTreeNode *right;
  BalancedBinarySearchTreeNode(InsertData *data);
  ~BalancedBinarySearchTreeNode();
};

namespace BBST {
int max(int a, int b);
int height(BalancedBinarySearchTreeNode *N);
BalancedBinarySearchTreeNode *newNode(int key, InsertData *data);
BalancedBinarySearchTreeNode *rightRotate(BalancedBinarySearchTreeNode *y);
BalancedBinarySearchTreeNode *leftRotate(BalancedBinarySearchTreeNode *x);
BalancedBinarySearchTreeNode *search(BalancedBinarySearchTreeNode *root, int key);
int getBalanceFactor(BalancedBinarySearchTreeNode *N);
BalancedBinarySearchTreeNode *insertNode(BalancedBinarySearchTreeNode *node, int key, InsertData *data);
BalancedBinarySearchTreeNode *nodeWithMimumValue(BalancedBinarySearchTreeNode *node);
BalancedBinarySearchTreeNode *deleteNode(BalancedBinarySearchTreeNode *root, int key);
void printTree(BalancedBinarySearchTreeNode *root, std::string indent, bool last);
} // namespace BBST

#endif // BALANCEDBINARYSEARCHTREE_H
