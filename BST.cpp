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

  return nullptr;
}

std::shared_ptr<Node> BST::search(std::shared_ptr<Node> n, int target){
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

  return nullptr;
}

std::shared_ptr<Node> BST::minimum(std::shared_ptr<Node> n){

  return nullptr;
}

std::shared_ptr<Node> BST::maximum(){
  
  return nullptr;
}

std::shared_ptr<Node> BST::maximum(std::shared_ptr<Node> n){

  return nullptr;
}

void BST::insertValue(int val){
  if (root == nullptr) {
    root = std::shared_ptr<Node>(new Node(val));
  }
  else {
    root = insertValue(root, val);
  }
}

std::shared_ptr<Node> BST::insertValue(std::shared_ptr<Node> n, int val){
  if (val < n->value) {
    if(n->left != nullptr) {
      n->left = insertValue(n->left, val);
    }
    else {
      n->left = std::shared_ptr<Node>(new Node(val));
    }
  }
  else if (val > n->value) {
    if(n->right != nullptr) {
      n->right = insertValue(n->left, val);
    }
    else {
      n->right = std::shared_ptr<Node>(new Node(val));
    }
  }
  // this is if n->value == val, ignore
  // have to look into what this means
  return n;
}

void BST::deleteValue(int val){

}

std::shared_ptr<Node> BST::deleteValue(std::shared_ptr<Node> n, int val){

  return nullptr;
}

bool BST::isBST(std::shared_ptr<Node> n){

  return false;
}

bool BST::isBST(std::shared_ptr<Node> n, int low, int high){
  if (n = nullptr) {
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
}

void BST::preOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
  if (n != nullptr) {
    cout << n->value;
    preOrder(n->left, order);
    preOrder(n->right, order);
    // I'm not really sure what I should put for left and right
    // I just put the order there because it's a parameter not sure why it's needed
  }
}

void BST::inOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){

}

void BST::postOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
  
}
