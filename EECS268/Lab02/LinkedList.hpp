/**
*	@file LinkedList.hpp
*	@author Robert Hümmer
*	@date 17.12.2016
*	@brief A implementation file for templated LinkedList class
*/
#include <iostream>
using namespace std;

template <typename T>
LinkedList<T>::LinkedList() :
	m_front(nullptr),
	m_length(0)
{}

template <typename T>
LinkedList<T>::~LinkedList()
{
	// delete all nodes in the list
	while( m_front != nullptr )
	{
		Node<T>* pCurNode = m_front;
		m_front = m_front->getNextNode();
		delete pCurNode;
	}
}	
	
template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return (m_length == 0 ? true : false);
}

template <typename T>
int LinkedList<T>::getLength() const
{
	return m_length;
}

template <typename T>
int LinkedList<T>::positionOf(T value) const
{
	// disadvantage of linked lists here compared to arrays with direct access
	// linear complexity O(n) = n for accessing a element at position ...
	int pos = 1;
	Node<T>* pCurNode = m_front;
	
	while( pCurNode != nullptr )
	{
		if( pCurNode->getValue() == value )
		{
			return pos;	// Node with value found in LL at Position pos
		}
		pCurNode = pCurNode->getNextNode();		
		++pos;
	}
	return 0;	// no Node with value found in LL
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* pCurNode = m_front;
	
	if( !isEmpty() )
	{
		// stop until pCurNode contains the last Node of the LL
		while( pCurNode->getNextNode() != nullptr )
		{
			pCurNode = pCurNode->getNextNode();
		}
	}
	
	Node<T>* newNode = new Node<T>(value);	// generate a new node with the value
	newNode->setNextNode( nullptr );	// adjust the pointer of the new node
	if( !isEmpty() )
		pCurNode->setNextNode( newNode );	// add the newly generated Node to the back of the LL
	else
		m_front = newNode;
	++m_length;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* newNode = new Node<T>(value);	// generate a new node with the value
	newNode->setNextNode( m_front );	// adjust the pointer of the new node
	m_front = newNode;	// add the newly generated node to the front of the LL
	++m_length;
} 

template <typename T>
bool LinkedList<T>::insert(int position, T value)
{
	if( position < 1 || position > m_length+1 ) 	
		throw runtime_error("Position Out of Bounds!");
		
	int pos = 1;
	Node<T>* pPrevNode = nullptr;
	Node<T>* pCurNode  = m_front;
		
	do
	{
		if( pos == position )
		{
			Node<T>* newNode = new Node<T>(value);
			newNode->setNextNode( pCurNode );
			
			if(position == 1)	// an erste Position einfuegen
				m_front = newNode;	// => m_front umhaengen
			else
				pPrevNode->setNextNode( newNode );
				
			++m_length;
			return true;
		}
		pPrevNode = pCurNode; 
		pCurNode  = pCurNode->getNextNode();		
		++pos;
		
	} while( pPrevNode != nullptr );
	
	return false;	// position not found
}	

template <typename T>
bool LinkedList<T>::removeBack()
{
	if( isEmpty() ) 	return false;	// in an empty list nothing can be removed
	Node<T>* pPrevNode = nullptr;
	Node<T>* pCurNode  = m_front;
	
	while( pCurNode->getNextNode() != nullptr )
	{
		pPrevNode = pCurNode;
		pCurNode = pCurNode->getNextNode();
	}	
	// after the loop pCurNode reached the end of LL
	
	if( pPrevNode != nullptr )	// equivalent to "if position != 1"
		pPrevNode->setNextNode( nullptr );
	else
		m_front = nullptr;
		
	delete pCurNode;
	--m_length;
	return true;
}
	
template <typename T>
bool LinkedList<T>::removeFront()
{
	if( isEmpty() ) 	return false;	// in an empty list nothing can be removed anymore
	Node<T>* pCurNode = m_front;
	m_front = m_front->getNextNode();
	delete pCurNode;
	--m_length;
	return true;
}

template <typename T>
bool LinkedList<T>::removeAt(int position)
{
	if( isEmpty() ) 	return false;	// in an empty list nothing can be removed
	int pos=1;
	Node<T>* pPrevNode = nullptr; 
	Node<T>* pCurNode  = m_front;
	
	while( pCurNode != nullptr )
	{
		if( pos == position )
		{
			if( pPrevNode != nullptr )	// equivalent to "if position != 1"
			{
				pPrevNode->setNextNode( pCurNode->getNextNode() );
			} else {
				m_front = m_front->getNextNode(); 
			}
			delete pCurNode;
			--m_length;
			break;
		}
		pPrevNode = pCurNode;
		pCurNode = pCurNode->getNextNode();
		++pos;
	}	
	// after the loop pCurNode reached the end of LL
	return true;	 
}

template <typename T>
void LinkedList<T>::setEntry(int position, T value)
{
	int pos = 1;
	Node<T>* pCurNode = m_front;
	
	while( pCurNode != nullptr )
	{
		if( pos == position )
		{
			pCurNode->setValue(value);
		}
		pCurNode = pCurNode->getNextNode();
		++pos;
	}
}


template <typename T>
T LinkedList<T>::getEntry( int position ) const
{
	int pos = 1;
	Node<T>* pCurNode = m_front;
	
	while( pCurNode != nullptr )
	{
		if( pos == position )
		{
			return pCurNode->getValue();
		}
		pCurNode = pCurNode->getNextNode();
		++pos;
	}
	throw runtime_error("Position not found!");
}
