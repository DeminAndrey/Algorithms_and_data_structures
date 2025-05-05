#pragma once


// Структура узла дерева
struct Node {
  int key;
  Node* left = nullptr;
  Node* right = nullptr;

  Node(int k) : key(k) {}
};

class BinarySearchTree {
  Node* root = nullptr;

public:
  BinarySearchTree() = default;
  ~BinarySearchTree();

  void insert(int key);        // Вставка элемента
  bool search(int key);        // Поиск элемента
  void remove(int key);        // Удаление элемента

private:
  // Вспомогательные функции для работы с узлами
  void insertRecursive(Node*& node, int key);
  bool search(Node* node, int key);
  void remove(Node*& node, int key);
  Node* findMinNode(Node* node);
  void destroy(Node* node);
};
