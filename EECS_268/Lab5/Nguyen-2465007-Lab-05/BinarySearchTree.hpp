//Filename: BinarySearchTree.hpp
//Assignment: EECS 268 Lab 5
//Author: Henry C. Nguyen
//Description: File contains class definitions for
//BinarySearchTree class methods
//Date: 3-16-14
//Email: h724n828@ku.edu
//
#include "BinarySearchTree.h"

//Default Constructor
template<typename T>
BinarySearchTree<T>::BinarySearchTree() {
	m_root = nullptr;
}

//Default Destructor
template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {	
	deleteTree(m_root);
}

//Determines add() course of action accordingly to status of m_root
template<typename T>
void BinarySearchTree<T>::add(T value) {
	if(m_root != nullptr)
	{
		add(value, m_root);
	}
	else
	{
		Node<T>* newNode = new Node<T>();
		newNode->setValue(value);
		m_root = newNode;
	}
}

//Recursively locates valid position to create node and store input value
template<typename T>
void BinarySearchTree<T>::add(T value, Node<T>* subTree){
	if(value < subTree->getValue())
	{
		//Checks pointer ahead to confirm existence
		if(subTree->getLeft() != nullptr)
		{
			add(value, subTree->getLeft());	//Recurse Left	
		}
		else
		{
			//Adds new node left of subtree
			Node<T>* newNode = new Node<T>();
			newNode->setValue(value);
			subTree->setLeft(newNode);
		}
	}
	else
	{
		//Checks pointer ahead to confirm existence
		if(subTree->getRight() != nullptr)
		{
			add(value, subTree->getRight());//Recurse Right
		}
		else
		{
			//Adds new node right of subtree
			Node<T>* newNode = new Node<T>();
			newNode->setValue(value);
			subTree->setRight(newNode);
		}
	}
}

//Determines printTree course of action according to m_root status
template<typename T>
void BinarySearchTree<T>::printTree() {
	if(m_root != nullptr)
	{
		printTree(m_root);	//Recurse if m_root exists		
	}
	else
	{
		std::cout << "Tree empty" << std::endl;
	}
}

//Prints the tree and traverses recursively in pre-order
template<typename T>
void BinarySearchTree<T>::printTree(Node<T>* subTree) {
	if(subTree != nullptr)
	{
		//Print, recurse left, then recurse right
		std::cout << subTree->getValue() << std::endl;
		printTree(subTree->getLeft());
		printTree(subTree->getRight());
	}
}

//Determines sortedPrint course of action according to m_root status
template<typename T>
void BinarySearchTree<T>::sortedPrint() {
	if(m_root != nullptr)
	{
		sortedPrint(m_root);	//Recurse if m_root exists
	}
	else
	{
		std::cout << "Tree empty" << std::endl;
	}
}

//Pritns the tree and traverses recursively in-order
template<typename T>
void BinarySearchTree<T>::sortedPrint(Node<T>* subTree) {
	if(subTree != nullptr)				//End sub-recursion if nullptr
	{	
		//Print, recurse left, then recurse right
		sortedPrint(subTree->getLeft());
		std::cout << subTree->getValue() << std::endl;
		sortedPrint(subTree->getRight());
	}
}

template<typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subTree) {
	if(subTree != nullptr)
	{
		//Recurse left, then recurse right, then delete current subTree
		deleteTree(subTree->getLeft());
		deleteTree(subTree->getRight());
		delete subTree;
	}
}

//Begins the search recursion at tree root
template<typename T>
Node<T>* BinarySearchTree<T>::search(T value) {
	search(value, m_root);
}

//**NOTE: FIND PROPER MINIMAL LOCATION TO RETURN NULLPTR
template<typename T>
Node<T>* BinarySearchTree<T>::search(T value, Node<T>* subTree) {
	if(subTree != nullptr)
	{	//Returns the address of matching subtree otherwise continue searching for requested value
		if(value == subTree->getValue())
		{
			return subTree;
		}
		else
		{
			if(value < subTree->getValue() && subTree->getLeft() != nullptr)
			{
				search(value, subTree->getLeft());
			}
			else if(value >= subTree->getValue() && subTree->getRight() != nullptr)
			{
				search(value, subTree->getRight());
			}
			else
			{
				return nullptr;	//Returns nullptr address if value cannot be found within the binary tree
			}
		}		
	}
}
