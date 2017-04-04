#pragma once
#include <algorithm>
#include <string>
#include <fstream>
#include <iterator>
#include <exception>
#include <vector>
#include <sstream>
#include "TransformUtils.h"

using namespace std;

class BinaryFileHelper
{
	public:
		static void write(const string&, const vector<unsigned char>&);
		static string read(const string&, const int = 1000);
		static streampos get_file_size(const string& filename);

	private:
		BinaryFileHelper();
};

