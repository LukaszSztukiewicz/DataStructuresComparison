#include "BalancedBinarySearchTree.h"

BalancedBinarySearchTreeNode::BalancedBinarySearchTreeNode(InsertData *data) : data(data), key(data->getIndex()), height(1), left(nullptr), right(nullptr){};

namespace BBST {

int max(int a, int b) {
  return (a > b) ? a : b;
}

int height(BalancedBinarySearchTreeNode *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

BalancedBinarySearchTreeNode *newNode(int key, InsertData *data) {
  BalancedBinarySearchTreeNode *node = new BalancedBinarySearchTreeNode(data);
  node->key                          = key;
  node->left                         = NULL;
  node->right                        = NULL;
  node->height                       = 1;
  return (node);
}

BalancedBinarySearchTreeNode *rightRotate(BalancedBinarySearchTreeNode *y) {
  BalancedBinarySearchTreeNode *x  = y->left;
  BalancedBinarySearchTreeNode *T2 = x->right;
  x->right                         = y;
  y->left                          = T2;
  y->height                        = max(height(y->left), height(y->right)) + 1;
  x->height                        = max(height(x->left), height(x->right)) + 1;
  return x;
}

// Rotate left
BalancedBinarySearchTreeNode *leftRotate(BalancedBinarySearchTreeNode *x) {
  BalancedBinarySearchTreeNode *y  = x->right;
  BalancedBinarySearchTreeNode *T2 = y->left;
  y->left                          = x;
  x->right                         = T2;
  x->height                        = max(height(x->left), height(x->right)) + 1;
  y->height                        = max(height(y->left), height(y->right)) + 1;
  return y;
}

BalancedBinarySearchTreeNode *search(BalancedBinarySearchTreeNode *root, int key) {
  if (root == NULL || root->key == key)
    return root;
  if (root->key > key)
    return search(root->left, key);
  return search(root->right, key);
}

// Get the balance factor of each node
int getBalanceFactor(BalancedBinarySearchTreeNode *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
         height(N->right);
}

// Insert a node
BalancedBinarySearchTreeNode *insertNode(BalancedBinarySearchTreeNode *node, int key, InsertData *data) {
  // Find the correct postion and insert the node
  if (node == NULL)
    return (newNode(key, data));
  if (key < node->key)
    node->left = insertNode(node->left, key, data);
  else if (key > node->key)
    node->right = insertNode(node->right, key, data);
  else
    return node;

  // Update the balance factor of each node and
  // balance the tree
  node->height      = 1 + max(height(node->left),
                              height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

// BalancedBinarySearchTreeNode with minimum value
BalancedBinarySearchTreeNode *nodeWithMimumValue(BalancedBinarySearchTreeNode *node) {
  BalancedBinarySearchTreeNode *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Delete a node
BalancedBinarySearchTreeNode *deleteNode(BalancedBinarySearchTreeNode *root, int key) {
  // Find the node and delete it
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if ((root->left == NULL) ||
        (root->right == NULL)) {
      BalancedBinarySearchTreeNode *temp = root->left ? root->left : root->right;
      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      BalancedBinarySearchTreeNode *temp = nodeWithMimumValue(root->right);
      root->key                          = temp->key;
      root->right                        = deleteNode(root->right,
                                                      temp->key);
    }
  }

  if (root == NULL)
    return root;

  // Update the balance factor of each node and
  // balance the tree
  root->height      = 1 + max(height(root->left),
                              height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

// Print the tree
void printTree(BalancedBinarySearchTreeNode *root, std::string indent, bool last) {
  if (root != nullptr) {
    std::cout << indent;
    if (last) {
      std::cout << "R----";
      indent += "   ";
    } else {
      std::cout << "L----";
      indent += "|  ";
    }
    std::cout << root->key << std::endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}
} // namespace BBST
