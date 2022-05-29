#ifndef BALANCEDBINARYSEARCHTREE_H
#define BALANCEDBINARYSEARCHTREE_H

#include "BinarySearchTree.h"
#include "DataStructure.h"

class BalancedBinarySearchTreeNode : public DataStructure {
public:
  InsertData *data;
  int key;
  int height;
  BalancedBinarySearchTreeNode *left;
  BalancedBinarySearchTreeNode *right;
  BalancedBinarySearchTreeNode(InsertData *data);
  ~BalancedBinarySearchTreeNode();
};

#endif // BALANCEDBINARYSEARCHTREE_H
