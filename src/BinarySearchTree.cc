#include "BinarySearchTree.h"

BinarySearchTreeNode::BinarySearchTreeNode(InsertData *data) : data(data), left(nullptr), right(nullptr){};

BinarySearchTreeNode::~BinarySearchTreeNode() {
  delete data;
  delete left;
  delete right;
};

BinarySearchTree::BinarySearchTree() : root(nullptr){};

BinarySearchTree::~BinarySearchTree() {
  delete root;
};

void BinarySearchTree::remove(InsertData *data, bool compareIndexOnly) {
  BinarySearchTreeNode *current  = root;
  BinarySearchTreeNode *previous = nullptr;
  bool isEqual;
  while (current != nullptr) {
    if (compareIndexOnly) {
      isEqual = current->data->getIndex() == data->getIndex();
    } else {
      isEqual = (*current->data) == *data;
    }
    if (isEqual) {
      if (current->data->getIndex() == data->getIndex()) {
        if (previous == nullptr) {
          root = current->left;
        } else {
          if (previous->left == current) {
            previous->left = current->left;
          } else {
            previous->right = current->left;
          }
        }
        delete current;
        return;
      }
    }
    previous = current;
    current  = current->left;
  }
}

InsertData *BinarySearchTree::search(InsertData *data, bool compareIndexOnly) {
  BinarySearchTreeNode *current = root;
  while (current != nullptr) {
    if (compareIndexOnly) {
      if (current->data->getIndex() == data->getIndex()) {
        return current->data;
      }
    } else {
      if (*current->data == *data) {
        return current->data;
      }
    }
    if (current->data->getIndex() > data->getIndex()) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return nullptr;
}

void BinarySearchTree::insert(InsertData *data, bool withDuplicates) {
  BinarySearchTreeNode *newItem;
  newItem->data  = data;
  newItem->left  = nullptr;
  newItem->right = nullptr;
  if (root == nullptr) {
    root = newItem;
  } else {
    BinarySearchTreeNode *current = root;
    while (current != nullptr) {
      if (current->data->getIndex() > data->getIndex()) {
        if (current->left == nullptr) {
          current->left = newItem;
          return;
        } else {
          current = current->left;
        }
      } else {
        if (current->right == nullptr) {
          current->right = newItem;
          return;
        } else {
          current = current->right;
        }
      }
    }
  }
}

void BinarySearchTree::recursivePrint(BinarySearchTreeNode *node, bool *indicesOnly, BinarySearchTree::traversalOrder traversalOrder) {
  {
    if (node == nullptr) {
      return;
    }
    switch (traversalOrder) {
    case BinarySearchTree::traversalOrder::PRE_ORDER:
      if (*indicesOnly) {
        std::cout << node->data->getIndex() << " ";
      } else {
        std::cout << node->data->toString() << "\n";
      }
      recursivePrint(node->left, indicesOnly, traversalOrder);
      recursivePrint(node->right, indicesOnly, traversalOrder);
      break;
    case BinarySearchTree::traversalOrder::IN_ORDER:
      recursivePrint(node->left, indicesOnly, traversalOrder);
      if (*indicesOnly) {
        std::cout << node->data->getIndex() << " ";
      } else {
        std::cout << node->data->toString() << "\n";
      }
      recursivePrint(node->right, indicesOnly, traversalOrder);
      break;
    case BinarySearchTree::traversalOrder::POST_ORDER:
      recursivePrint(node->left, indicesOnly, traversalOrder);
      recursivePrint(node->right, indicesOnly, traversalOrder);
      if (*indicesOnly) {
        std::cout << node->data->getIndex() << " ";
      } else {
        std::cout << node->data->toString() << "\n";
      }
      break;
    }
  }
}

void BinarySearchTree::recursiveTraverseAndCallFunction(BinarySearchTreeNode *node, std::function<void *(InsertData *)> function, BinarySearchTree::traversalOrder traversalOrder) {
  if (node == nullptr) {
    return;
  }
  switch (traversalOrder) {
  case BinarySearchTree::traversalOrder::PRE_ORDER:
    function(node->data);
    recursiveTraverseAndCallFunction(node->left, function, traversalOrder);
    recursiveTraverseAndCallFunction(node->right, function, traversalOrder);
    break;
  case BinarySearchTree::traversalOrder::IN_ORDER:
    recursiveTraverseAndCallFunction(node->left, function, traversalOrder);
    function(node->data);
    recursiveTraverseAndCallFunction(node->right, function, traversalOrder);
    break;
  case BinarySearchTree::traversalOrder::POST_ORDER:
    recursiveTraverseAndCallFunction(node->left, function, traversalOrder);
    recursiveTraverseAndCallFunction(node->right, function, traversalOrder);
    function(node->data);
    break;
  }
}

void BinarySearchTree::print(bool indicesOnly) {
  recursivePrint(root, &indicesOnly, BinarySearchTree::traversalOrder::IN_ORDER);
}