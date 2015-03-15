//Filename: Node.hpp
//Author: Henry C. Nguyen
//Assignment: EECS 268 Lab 4
//Description: File contains methods of template class Node
//Date: 2-28-14
//Email: h724n828@ku.edu
// 

//Default Constructor
//Creates and initializes member variables
template<typename T>
Node<T>::Node()
{
	m_value = 0;
	m_previous = nullptr;
}

//Alternative Constructor
//Creates and initializes member variables accordingly to input parameters
template<typename T>
Node<T>::Node(T value, Node<T>* previous)
{
	m_value = value;
	m_previous = previous;
}

//Alternative Constructor
//Creates and initializes value member variable with value input parameter
//and then initializes m_previous with nullptr value
template<typename T>
Node<T>::Node(T value)
{
	m_value = 0;
	m_previous = nullptr;
}

//Set Methods
//===========
//Sets according member variable to input parameter of the same type T
template<typename T>
void Node<T>::setValue(T value)
{
	m_value = value;
}

template<typename T>
void Node<T>::setPrevious(Node<T>* previous)
{
	m_previous = previous;
}

//Get Methods
//===========
//Returns requested member variable as original member variable type
template<typename T>
T Node<T>::getValue()
{
	return m_value;
}

template<typename T>
Node<T>* Node<T>::getPrevious()
{
	return m_previous;
}
