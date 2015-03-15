#include "Queue.h"

template<typename T>
Queue<T>::~Queue()
{

}

template<typename T>
virtual bool Queue<T>::isEmpty()
{
}

template<typename T>
virtual void Queue<T>::enqueue(const T  newEntry)
{

}

template<typename T>
virtual T Queue<T>::dequeue() throw(PreconditionViolationException) = 0;
{

}

template<typename T>
virtual T Queue<T>::peekFront() const throw(PreconditionViolationException) = 0;
{
	
}

template<typename T>
virtual int Queue<T>::size() const = 0;
{

}
