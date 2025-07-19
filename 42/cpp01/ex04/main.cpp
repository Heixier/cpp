#include <iostream>
#include <fstream>

static void write_replaced_to_file(std::ofstream& outfile, const std::string line, const std::string& find, const std::string& replace)
{
	std::string::size_type	read_index = 0;
	std::string::size_type	match = 0;

	if (find.empty())
	{
		outfile << line << '\n';
		return ;
	}
	while ((match = line.find(find, read_index)) != std::string::npos)
	{
		outfile << line.substr(read_index, match - read_index);
		outfile << replace;
		read_index = match + find.length();
	}
	outfile << line.substr(read_index) << '\n';
}

int main(int argc, char **argv)
{
	std::ifstream infile;
	std::ofstream outfile;
	std::string ifilename;
	std::string ofilename;

	if (argc != 4)
		return std::cout << "Invalid number of arguments!\n", 1;

	ifilename = argv[1];
	ofilename = ifilename + ".replace";
	infile.open(ifilename.c_str(), std::ios::in);
	if (!infile.is_open())
		return std::cout << "Error reading '" << ifilename << "'!\n", 1;
	
	outfile.open(ofilename.c_str(), std::ios::out);
	if (!outfile.is_open())
		return std::cout << "Error creating/writing to output file!\n", 1;
	
	std::string line;
	while (getline(infile, line))
		write_replaced_to_file(outfile, line, argv[2], argv[3]);
	infile.close();
	outfile.close();

	return (0);
}