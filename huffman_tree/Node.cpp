#include "Node.h"

template<typename T>
Node<T>::Node(const int count)
	: left(nullptr), right(nullptr), count(count)
{}

template<typename T>
Node<T>::Node(const T value)
	: left(nullptr), right(nullptr), count(1), value(value)
{}

template<typename T>
Node<T>::Node(const T value, const int count) 
	: left(nullptr), right(nullptr), count(count), value(value)
{}

template<typename T>
Node<T>::Node(const int count, const shared_ptr<Node>& left, const shared_ptr<Node>& right)
	: left(left), right(right), count(count)
{}

template<typename T>
int Node<T>::get_count() const
{
	return count;
}

template<typename T>
T Node<T>::get_value() const
{
	return value;
}

template<typename T>
bool Node<T>::has_left() const
{
	return left != nullptr;
}

template<typename T>
bool Node<T>::has_right() const
{
	return right != nullptr;
}

template<typename T>
const shared_ptr<Node<T>>& Node<T>::get_left() const
{
	return left;
}

template<typename T>
const shared_ptr<Node<T>>& Node<T>::get_right() const
{
	return right;
}

template<typename T>
Node<T>& Node<T>::operator ++()
{
	++count;
	return *this;
}

template class Node<char>;