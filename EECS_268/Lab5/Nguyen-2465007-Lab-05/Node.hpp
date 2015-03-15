//Filename: Node.hpp
//Assignment: EECS 268 Lab 5
//Author: Henry C. Nguyen
//Description: File contains class method definitions for Node class
//Date: 3-7-14
//Email: h724n828@ku.edu
//

//Default Constructor
//Initializes class members
template<typename T>
Node<T>::Node() {
	m_value = 0;
	m_left = nullptr;
	m_right = nullptr;
}

//Get Method for m_left
template<typename T>
Node<T> * Node<T>::getLeft() {
	return m_left;
}

//Get Method for m_right
template<typename T>
Node<T> * Node<T>::getRight() {
	return m_right;
}

//Get Method for m_value
template<typename T>
T Node<T>::getValue() {
	return m_value;
}

//Set Method for m_left
template<typename T>
void Node<T>::setLeft(Node<T> * left) {
	m_left = left;
}

//Set Method for m_right
template<typename T>
void Node<T>::setRight(Node<T> * right) {
	m_right = right;
}

//Set Method for m_value
template<typename T>
void Node<T>::setValue(T value) {
	m_value = value;
}
