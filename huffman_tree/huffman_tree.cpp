#include <iostream>
#include "HuffmanTree.h"
#include "TransformUtils.h"
#include "BinaryFileHelper.h"

using std::string;
using std::cin;
using std::cout;

int main()
{
	try
	{
		const auto input = "lorem.txt";
		const auto output = "lorem.bin";

		ifstream file(input);
		if (!file.is_open()) throw exception("Exception: Unable to open file.");

		stringstream stream;
		stream << file.rdbuf();
		file.close();

		const auto file_content = stream.str();
		const auto file_size = BinaryFileHelper::get_file_size(input);
		cout << "Before compression: " << file_size << " bytes" << endl;

		HuffmanTree huffman_tree(file_content);
		const auto encoded = huffman_tree.encode(file_content);
		const auto bytes = TransformUtils::transform_string_to_bytes(encoded);

		BinaryFileHelper::write(output, bytes);
		const auto after_size = BinaryFileHelper::get_file_size(output);
		const auto delta = file_size - after_size;

		cout << "After compression: " << after_size << " bytes" << endl;
		cout << "Delta: " << delta << " (" << static_cast<double>(delta) / file_size << ")" << endl;

 		const auto output_data = BinaryFileHelper::read(output);
		//cout << huffman_tree.decode(output_data);
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
	}
	cin.get();
    return 0;
}