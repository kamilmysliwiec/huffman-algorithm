#pragma once
#include "Node.h"

class Symbol : public Node
{
	public:
		Symbol(const char);

		char get() const;

	private:
		char c;
};
