#pragma once
#include <memory>

using std::shared_ptr;

template<typename T>
class Node
{
	public:
		Node(const T);
		Node(const T, const int);
		Node(const int);
		Node(const int, const shared_ptr<Node>&, const shared_ptr<Node>&);

		int get_count() const;
		T get_value() const;

		bool has_left() const;
		bool has_right() const;
		const shared_ptr<Node<T>>& get_left() const;
		const shared_ptr<Node<T>>& get_right() const;
		Node& operator ++ ();

	private:
		shared_ptr<Node<T>> left;
		shared_ptr<Node<T>> right;

		int count;
		T value;
};

