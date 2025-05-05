#include "BinarySearchTree.h"

// Конструктор копирования и деструктор
BinarySearchTree::~BinarySearchTree() {
  destroy(root);
}

// Рекурсивное удаление всех узлов
void BinarySearchTree::destroy(Node* node) {
  if (node != nullptr) {
    destroy(node->left);
    destroy(node->right);
    delete node;
  }
}

// Вставка нового элемента в дерево
void BinarySearchTree::insert(int key) {
  insertRecursive(root, key);
}

// Внутренняя рекурсивная функция вставки
void BinarySearchTree::insertRecursive(Node *&node, int key) {
  if (node == nullptr) {
    node = new Node(key);
  }
  else if (key < node->key) {
    insertRecursive(node->left, key);
  }
  else if (key > node->key) {
    insertRecursive(node->right, key);
  }
  // Если ключ равен существующему значению, игнорируем вставку
}

// Поиск элемента в дереве
bool BinarySearchTree::search(int key) {
  return search(root, key);
}

// Внутренняя рекурсивная функция поиска
bool BinarySearchTree::search(Node* node, int key) {
  if (node == nullptr) {
    return false;
  }
  else if (key < node->key) {
    return search(node->left, key);
  }
  else if (key > node->key) {
    return search(node->right, key);
  }
  else {
    return true;
  }
}

// Удаление элемента из дерева
void BinarySearchTree::remove(int key) {
  remove(root, key);
}

// Внутренняя рекурсивная функция удаления
void BinarySearchTree::remove(Node *&node, int key) {
  if (node == nullptr) {
    return;
  } else if (key < node->key) {
    remove(node->left, key);
  } else if (key > node->key) {
    remove(node->right, key);
  } else {  // Найден узел для удаления
    if (node->left == nullptr && node->right == nullptr) {
      delete node;
      node = nullptr;
    }
    else if (node->left == nullptr) {
      Node* temp = node;
      node = node->right;
      delete temp;
    }
    else if (node->right == nullptr) {
      Node* temp = node;
      node = node->left;
      delete temp;
    }
    else {
      Node* minNode = findMinNode(node->right);
      node->key = minNode->key;
      remove(node->right, minNode->key);
    }
  }
}

// Нахождение минимального узла в поддереве
Node* BinarySearchTree::findMinNode(Node* node) {
  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
}
