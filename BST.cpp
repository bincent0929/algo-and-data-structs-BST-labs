// Lab 3 - BST_skeleton.cpp - rename it to BST.cpp
// Author: *** YOUR NAME HERE ***

#include<iostream>
#include <vector>
#include <limits.h>
#include "BST.h"

using namespace std;

// ***do not change the headers***

// you solutions go here
// remember that you do not need to implement all of them
// follow the document to see which ones you need to implement

BST::BST(){
}

BST::~BST(){}

std::shared_ptr<Node> BST::search(int target){
  if (root == nullptr) {
    return nullptr;
    // if there's no root value
  }
  else if (root->value == target) {
    return root;
    // if the root is the desired value
  }
  else if (root->value > target) {
    return search(root->left, target);
    // if the root is greater than the target
    // goes to search the left
  }
  else { // if n->value < target
    return search(root->right, target);
    // if the root is less than the target
    // goes to search the right
  }
}

std::shared_ptr<Node> BST::search(std::shared_ptr<Node> n, int target){
  // same stuff as the driver function, 
  // but searches down the given node
  if (n == nullptr) {
    return nullptr;
  }
  else if (n->value == target) {
    return n;
  }
  else if (n->value > target) {
    return search(n->left, target);
  }
  else { // if n->value < target
    return search(n->right, target);
  }
}

std::shared_ptr<Node> BST::minimum(){
  return minimum(root);
}

std::shared_ptr<Node> BST::minimum(std::shared_ptr<Node> n){
  // so it looks like I'll want to do the in order sort, then do a search
  // for the value in the first index and get the pointer from that
  std::vector<std::shared_ptr<Node>> order;
  inOrder(n, order);
  return order[0];
}

std::shared_ptr<Node> BST::maximum(){
  return maximum(root);
}

std::shared_ptr<Node> BST::maximum(std::shared_ptr<Node> n){
  std::vector<std::shared_ptr<Node>> order;
  inOrder(n, order);
  return order[order.size() - 1];
}
// so it looks like I'll want to do the in order sort, then do a search
  // for the value in the final index and get the pointer from that
void BST::insertValue(int val){
  if (root == nullptr) {
    root = std::shared_ptr<Node>(new Node(val));
    size += 1;
    // creates a new root node and places the value there
  }
  else {
    std::shared_ptr<Node> newValueNode = insertValue(root, val);

    if (newValueNode != nullptr) {
      size += 1;
    }
    // takes the value and root checks 
    // if it should go on the left or right
    // of the root
  }
}

std::shared_ptr<Node> BST::insertValue(std::shared_ptr<Node> n, int val){
  if (val < n->value) {
    if(n->left != nullptr) {
      return insertValue(n->left, val);
      // if there is already a value to the left
      // recursively called the function with the left value
    }
    else {
      n->left = std::shared_ptr<Node>(new Node(val));
      return n->left;
      // if there's no value to the left, place the value
      // in a new node there
    }
  }
  else if (val > n->value) {
    if(n->right != nullptr) {
      return insertValue(n->right, val);
      // 
    }
    else {
      n->right = std::shared_ptr<Node>(new Node(val));
      return n->right;
      // if there isn't a node, create a new node and place it there
    }
  }
  return nullptr;
  // if the value was already in a node
}

void BST::deleteValue(int val){
  root = deleteValue(root, val);
}

std::shared_ptr<Node> BST::deleteValue(std::shared_ptr<Node> n, int val){
  if (n == nullptr) {
    return n;
  }

  if (val < n->value) {
    n->left = deleteValue(n->left, val);
  }
  else if (val > n->value) {
    n->right = deleteValue(n->right, val);
  }
  else {
    if (n->left == nullptr) {
      // only right child present
      std::shared_ptr<Node> temp = n->right;
      n = nullptr;
      size--;
      return temp;
    }
    
    if (n->right == nullptr) {
      // only left child present
      std::shared_ptr<Node> temp = n->left;
      n = nullptr;
      size--;
      return temp;
    }

    // two children present
    std::shared_ptr<Node> temp = minimum(n->right);
    n->value = temp->value;
    n->right = deleteValue(n->right, temp->value);
  }
  return n;
}

bool BST::isBST(std::shared_ptr<Node> n){
  return isBST(n, 0, 10000);
  // 0 and 10000 are just numbers that are low and higher than
  // any value that's inserted by the tests
}

bool BST::isBST(std::shared_ptr<Node> n, int low, int high){
  if (n == nullptr) {
    return true;
    // if there are no values
  }
  if (n->value < low || n->value > high) {
    return false;
    // if the value is smaller than the lowest
    // or larger than the highest value
  }
  return isBST(n->left, low, n->value) && 
  isBST(n->right, n->value, high);
  // otherwise it will keep checking the rest of the values
  // to the right and left of the current value
}

void BST::preOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
  // rLR
  if (n != nullptr) {
    order.push_back(n);
    preOrder(n->left, order);
    preOrder(n->right, order);
    // I just had to change the fact that the driver was printing the values
    // using a vector instead of the preOrder function itself
    // so I just needed to push the values into the vector
  }
}

void BST::inOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
  // LrR
  // from root check if the left is null
  // if it isn't add the pointer of the left
  if (n != nullptr) {
    inOrder(n->left, order);
    order.push_back(n);
    inOrder(n->right, order);
  }
}

void BST::postOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
  // LRr
  if (n != nullptr) {
    postOrder(n->left, order);
    postOrder(n->right, order);
    order.push_back(n);
  }
}
