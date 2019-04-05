/**
*	@file Node.h
*	@author Robert Hümmer
*	@date 17.12.2016
*	@brief A header file for templated Node class
*/
#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
private:
	Node<T>* m_nextNode;
	T m_value;
	
public:
	Node() = delete;	// prevents the generation of compiler-generated default constructor
	
	/** @pre the value is a valid T.
	*   @post An Node with the provided value is created.
	*/
	Node(T value) : m_value(value)
	{}
	
	/** @pre None.
	*   @post Deletes node
	*/
	~Node()
	{
		m_nextNode = nullptr;
	}
	
	/** @pre	None
	 *  @post	The pointer m_nextNode is overriden by the provided pointer to nextNode
	 */
	void setNextNode(Node<T>* nextNode)
	{
		m_nextNode = nextNode;
	}
	
	/** @pre	None
	 *  @post	None
	 *  @return The pointer to the next Node in the LinkedList
	 */
	Node<T>* getNextNode() const
	{
		return m_nextNode;
	}
	
	/** @pre	None
	 *  @post	The m_value is overriden by the provided value
	 */
	void setValue(T value)
	{
		m_value = value;
	}
	
	/** @pre	None
	 *  @post	None
	 *  @return The entry of the Node
	 */
	T getValue() const
	{
		return m_value;
	}
};

#endif
