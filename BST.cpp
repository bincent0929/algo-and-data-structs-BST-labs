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
    // creates a new root node and places the value there
  }
  else {
    insertValue(root, val);
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
      size += 1;
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
      size += 1;
      // if there isn't a node, create a new node and place it there
    }
  }
  return n;
}

void BST::deleteValue(int val){
  root = search(root, val);
  std::shared_ptr<Node> leftMostNode;
  
  if (root->right == nullptr && root->left == nullptr) {
    root = nullptr;
    size -= 1;
    // if the node has no children, it's set as null/deleted
  }
  else if (root->right != nullptr && root->left != nullptr) {
    // go to the right and then look for the leftmost node
    // save that node's value to the root, then delete the node
    leftMostNode = minimum(root->right);
    root->value = leftMostNode->value;

    if (leftMostNode->right == nullptr) {
      leftMostNode = nullptr;
      size -= 1;
    }
    else { // if leftMostNode->right != nullptr
      // update the node's value to the right's value
      // then delete the right
      // I need to recursively check through until
      // there are no more children
      deleteValue(leftMostNode->right, val);
    }
    // leftMost must be deleted
    // the right side must be checked
  }
  else {
    if (root->right == nullptr) {
      root->value = root->left->value;
      // delete left node
    }
    else { // if root->left == nullptr
      root->value = root->right->value;
      // delete right node
    }
  }
  
}

std::shared_ptr<Node> BST::deleteValue(std::shared_ptr<Node> n, int val){
  std::shared_ptr<Node> leftMostNode;

  if (n->right == nullptr && n->left == nullptr) {
    return nullptr;
  }
  else if (n->right != nullptr && n->left != nullptr) {
    leftMostNode = minimum(n->right);
    n->value = leftMostNode->value;

    if (leftMostNode->right == nullptr) {
      leftMostNode = nullptr;
      return nullptr;
    }
    else {
      deleteValue(leftMostNode->right, val);
    }
  }
  else {
    if (n->right == nullptr) {
      n->value = n->left->value;
      // delete left node
    }
    else { // if root->left == nullptr
      n->value = n->right->value;
      // delete right node
    }
  }
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
