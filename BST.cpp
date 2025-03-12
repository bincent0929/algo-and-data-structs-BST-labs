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
    root = insertValue(root, val);
    // takes the value and root checks 
    // if it should go on the left or right
    // of the root
  }
}

std::shared_ptr<Node> BST::insertValue(std::shared_ptr<Node> n, int val){
  if (val < n->value) {
    if(n->left != nullptr) {
      n->left = insertValue(n->left, val);
      // if there's already a node, place it there
    }
    else {
      n->left = std::shared_ptr<Node>(new Node(val));
      // if there isn't a node, create a new node and place it there
    }
  }
  else if (val > n->value) {
    if(n->right != nullptr) {
      n->right = insertValue(n->right, val);
      // if there's already a node, place it there
    }
    else {
      n->right = std::shared_ptr<Node>(new Node(val));
      // if there isn't a node, create a new node and place it there
    }
  }
  // this is if n->value == val, ignore
  // basically if the value is already where it goes
  return n;
}

void BST::deleteValue(int val){
  
}

std::shared_ptr<Node> BST::deleteValue(std::shared_ptr<Node> n, int val){
  // if it has not children, return a nullptr or the pointer of its parent??
  // otherwise, you will want to look to it's right, then go to the left
  // and return the leftmost node (node with the smallest valueß)
  return nullptr;
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
  if (n != nullptr) {
    inOrder(n->left, order);
    order.push_back(n);
    inOrder(n->right, order);
    // I just had to change the fact that the driver was printing the values
    // using a vector instead of the preOrder function itself
    // so I just needed to push the values into the vector
  }
}

void BST::postOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
  // LRr
  if (n != nullptr) {
    postOrder(n->left, order);
    postOrder(n->right, order);
    order.push_back(n);
    // I just had to change the fact that the driver was printing the values
    // using a vector instead of the preOrder function itself
    // so I just needed to push the values into the vector
  }
}
