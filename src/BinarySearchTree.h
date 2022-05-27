#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "DataStructure.h"
#include <functional>

class BinarySearchTreeNode {
public:
  BinarySearchTreeNode(InsertData *data);
  ~BinarySearchTreeNode();
  InsertData *data;
  BinarySearchTreeNode *left;
  BinarySearchTreeNode *right;
};

class BinarySearchTree : public DataStructure {
private:
  BinarySearchTreeNode *root;

public:
  enum traversalOrder {
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER,
  };
  BinarySearchTree();
  ~BinarySearchTree();
  void insert(InsertData *data);
  void remove(InsertData *data);
  InsertData *search(InsertData *data);
  void recursivePrint(BinarySearchTreeNode *root, bool *indicesOnly, BinarySearchTree::traversalOrder traversalOrder);
  void recursiveTraverseAndCallFunction(BinarySearchTreeNode *node, std::function<void *(InsertData *)> function, BinarySearchTree::traversalOrder traversalOrder);
  void print(bool indicesOnly) override;
};

#endif // BINARYSEARCHTREE_H