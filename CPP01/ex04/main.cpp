#include <iostream>
#include <fstream>
#include <string>

int main ( int argc, char *argv[] )
{
	if (argc != 4)
		return 1;
	std::string file = argv[1];
	std::ifstream ifs(file);
	if (ifs.fail())
	{
		std::cout << file + " not found" << std::endl;
		return 1;
	}
	file += ".replace";
	std::ofstream ofs(file);
	if (ifs.fail())
	{
		std::cout << file + " permission denied" << std::endl;
		return 1;
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string line;
	std::string s4;
	std::size_t i = 0;
	while (std::getline(ifs, line))
	{
		if (s1 != s2 && s1.length())
		{
			i = line.find(s1);
			while (i!=std::string::npos)
			{
				s4 = line.substr(0, i);
				s4 += s2;
				s4 += line.substr(i + s1.length());
				line = s4;
				i = line.find(s1);
			}
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
}
