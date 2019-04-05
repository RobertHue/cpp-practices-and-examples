#include "Queue.h"
#include <iostream>

template<typename T>
Queue<T>::Queue()
{
	m_front = nullptr;
	m_size = 0;
}

template<typename T>
Queue<T>::~Queue()
{
	while(!isEmpty())
	{
		dequeue();	
	}
}

template<typename T>
bool Queue<T>::isEmpty() const
{
	std::cout << size() << std::endl;
	if(size() > 0)
	{
		return 0;
	}
	return 1;
}

template<typename T>
void Queue<T>::enqueue(const T newEntry)
{
	if(m_front != nullptr)
	{
		Node<T>* temp = m_front;
		while(temp->getPrevious() != nullptr)
		{
			temp = temp->getPrevious();
		}
		Node<T>* newNode = new Node<T>();
		newNode->setValue(newEntry);
		newNode->setPrevious(nullptr);
		temp->setPrevious(newNode);
		++m_size;
	}
	else
	{
		Node<T>* newNode = new Node<T>();
		newNode->setValue(newEntry);
		newNode->setPrevious(nullptr);
		m_front = newNode;
		++m_size;
	}	
}

template<typename T>
T Queue<T>::dequeue() throw(PreconditionViolationException)
{
	if(m_front != nullptr)
	{
		Node<T>* temp = m_front->getPrevious();
		delete m_front;
		--m_size;
		m_front = temp;
		if(m_front != nullptr)
		{
			return m_front->getValue();
		}
	}
	else
	{
		throw (PreconditionViolationException("Dequeue attempted on an empty stack"));	
	}
}

template<typename  T>
T Queue<T>::peekFront() const throw(PreconditionViolationException)
{
	if(m_front != nullptr)
	{
		return m_front->getValue();
	}
	else
	{
		throw (PreconditionViolationException("Peek attempted on an empty stack"));
	}
}

template<typename T>
int Queue<T>::size() const
{
	return m_size;
}
