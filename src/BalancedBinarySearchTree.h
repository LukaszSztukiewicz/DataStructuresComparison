#ifndef BALANCEDBINARYSEARCHTREE_H
#define BALANCEDBINARYSEARCHTREE_H

#include "BinarySearchTree.h"

class BalancedBinarySearchTree : public BinarySearchTree {
private:
  void balance();

public:
  BalancedBinarySearchTree();
  ~BalancedBinarySearchTree();
  void insert(InsertData *data, bool withDuplicates);
  void remove(InsertData *data, bool byIndexOnly);
};

#endif // BALANCEDBINARYSEARCHTREE_H
