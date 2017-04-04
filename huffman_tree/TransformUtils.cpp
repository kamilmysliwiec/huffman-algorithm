#include "TransformUtils.h"
#include <chrono>
#include <iostream>

TransformUtils::TransformUtils() {}

vector<unsigned char> TransformUtils::transform_string_to_bytes(const string& data)
{
	const short byte_size = 8;
	const char * const buffer_ptr = data.c_str();

	vector<unsigned char> bytes_code;
	for (auto pos = 0; pos / 8 < data.size() / byte_size; pos += 8)
	{
		unsigned byte = 0x00;
		for (auto b = 0; b < byte_size; ++b)
		{
			byte <<= 1;
			if (*(buffer_ptr + b + pos) == '1') byte |= 0x01;
		}
		bytes_code.push_back(byte);
	}
	return bytes_code;
}

string TransformUtils::transform_byte_to_string(const unsigned char& byte)
{
	bitset<8> byte_str(byte);
	return byte_str.to_string();
}