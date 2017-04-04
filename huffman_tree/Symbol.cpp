#include "Symbol.h"

Symbol::Symbol(const char c) 
	: Node(1), c(c)
{}

char Symbol::get() const
{
	return c;
}