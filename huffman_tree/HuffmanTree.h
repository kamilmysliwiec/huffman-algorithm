#pragma once
#include <memory>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include "Node.h"

using namespace std;

typedef Node<char> Symbol;
typedef shared_ptr<Symbol> SymbolPtr;

class HuffmanTree
{
	public:
		HuffmanTree(const string&);
			
		string encode(const string&) const;
		string decode(const string&) const;

	private:
		void init(const string&);
		void create_binary_tree(vector<SymbolPtr>&);
		void create_hash_table(map<char, SymbolPtr>);

		map<char, SymbolPtr> create_dictionary(const string&) const;
		vector<SymbolPtr> move_to_vector(map<char, SymbolPtr>&) const;
		string find_path(Symbol&, const char&, bool&, const string& = "");
		char find_symbol(Symbol&, const char * const, unsigned long&) const;

		SymbolPtr binary_tree;
		map<char, string> hash_table;
};

