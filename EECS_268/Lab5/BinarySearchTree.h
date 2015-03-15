//Filename: BinarySearchTree.h
//Assignment: EECS 268 Lab 5
//Author: Henry C. Nguyen
//Description: File contains header definitions for BinarySearchTree class
//Date: 3-7-14
//Email: h724n828@ku.edu
//
#include <iostream>
#include "Node.h"

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template<typename T>
class BinarySearchTree {
	private:
	//Class Members
	//=============
	//Pointer that points to the root of the binary tree
	Node<T>* m_root;

	//Private Methods
	//===============	
	//Creates a node and connects it to parameter subtree
	//@pre subtree is initialized
	//@post adds a node to binary tree according to subtree position
	//@return none
	void add(T value, Node<T>* subTree);
	
	//Recurse down subtree to delete in post-order traversal
	//@pre subtree is initialized
	//@post deletes subtree
	//@return none
	void deleteTree(Node<T>* subTree);	

	//Prints the binary tree with parameter as starting point
	//@pre parameter is same type, is not null, and is within the tree
	//@post prints binary tree according to parameter
	//@return none
	void printTree(Node<T>* subTree);
	
	//Prints binary tree in sorted fashion from parameter pointer
	//@pre parameter is same type, not null, and within the tree
	//@post prints binary tree in sorted fashion according to parameter
	//@return none
	void sortedPrint(Node<T>* subTree);

	//Returns searched pointer
	//@pre none
	//@post none
	//@return pointer of node or nullptr if node does not exist 
	//at address
	Node<T>* search(T value, Node<T>* subTree);

	public:
	//Public Methods
	//==============
	//Default Constructor
	//@pre none
	//@post Initializes class members
	//@return none
	BinarySearchTree();

	//Deconstructor
	//@pre none
	//@post Deletes all class members and class
	//@return none
	~BinarySearchTree();

	//Creates a node and connects it to m_root
	//@pre m_root is initialized
	//@post adds a node to binary tree connected to m_root
	//@return none
	void add(T value);
	
	//Prints the binary tree from m_root
	//@pre m_root is initialized
	//@post prints binary tree
	//@return none
	void printTree();
		
	//Prints binary tree in a sorted fashion from m_root
	//@pre m_root is initialized
	//@post prints binary tree in sorted fashion
	//@return none
	void sortedPrint();
	
	//Searches for a node within binary tree and returns as pointer
	//@pre parameter pointer exists within binary tree
	//@post none
	//@return pointer to node
	Node<T>* search(T value);
};

#include "BinarySearchTree.hpp"

#endif
