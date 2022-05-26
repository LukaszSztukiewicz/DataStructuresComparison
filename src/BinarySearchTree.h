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
  void insert(InsertData *data, bool withDuplicates = true);
  void remove(InsertData *data, bool compareIndexOnly = true);
  InsertData *search(InsertData *data, bool compareIndexOnly = true);
  void recursivePrint(BinarySearchTreeNode *root, bool *indicesOnly, BinarySearchTree::traversalOrder traversalOrder);
  void recursiveTraverseAndCallFunction(BinarySearchTreeNode *node, std::function<void *(InsertData *)> function, BinarySearchTree::traversalOrder traversalOrder);
  void print(bool indicesOnly);
};

#endif // BINARYSEARCHTREE_H