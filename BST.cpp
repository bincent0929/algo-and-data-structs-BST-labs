// Lab 3 - BST_skeleton.cpp - rename it to BST.cpp
// Author: *** YOUR NAME HERE ***

#include<iostream>
#include <vector>
#include <limits.h>
#include "BST.h"

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

  return nullptr;
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
}

std::shared_ptr<Node> BST::insertValue(std::shared_ptr<Node> n, int val){

  return nullptr;
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

}

void BST::inOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){

}

void BST::postOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order){
  
}
