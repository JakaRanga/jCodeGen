//
// EPITECH PROJECT, 2018
//  gen cpp
// File description:
// 
//

#include "ClassGenerator.hpp"

ClassGenerator::ClassGenerator(const std::string &name)
{
	this->Name = name;
	this->Head = getHpp();
	this->User = pickEnvName();
}

std::string		ClassGenerator::pickEnvName()
{
	std::string	name;

	name = std::getenv("USER");
	if (name[0] >= 'a' && name[0] <= 'z')
		name[0] -= 32;
	return name;
}

std::string		ClassGenerator::getUserName()
{
	return this->User;
}

std::string		ClassGenerator::getHpp()
{
	std::string	head = this->Name;;
	int		i = 0;

	while (head[i])
	{
		if (head[i] >= 'a' && head[i] <= 'z')
			head[i] -= 32;
		i++;
	}
	head += "_HPP_";
	return (head);
}

bool			ClassGenerator::fileExist()
{
	std::ifstream	fHpp(this->Name + ".hpp");
	std::ifstream	fCpp(this->Name + ".cpp");

	if (fHpp.is_open() || fCpp.is_open())
	{
		std::string	gLine;
		std::size_t	y;

		printf("\033[01;31m");
		std::cout << "Do you really want overwrite the existing class ["
			  << this->Name << "]?" << std::endl;
		printf("\033[01;37m");
		std::cout << "\t(N / y)" << std::endl;

		std::getline(std::cin, gLine);
		y = gLine.find("y");

		if (y == 0)
			return true;
		else
			return false;
	}
	return true;
}

std::ofstream			&ClassGenerator::putHeader(std::ofstream &pp, bool isCpp)
{
	pp << "//" << std::endl << "// EPITECH PROJECT, 2018" << std::endl
	   << "// " << this->Name << ((isCpp) ? ".cpp" : ".hpp") << std::endl
	   << "// File description:" << std::endl
	   << "//" << std::endl << "//" << std::endl << std::endl;;
	return pp;
}

bool			ClassGenerator::fileGen()
{
	
	std::ofstream	fHpp(this->Name + ".hpp");
	std::ofstream	fCpp(this->Name + ".cpp");

	if (!fHpp || !fCpp)
		return false;

	putHeader(fHpp, false);
	putHeader(fCpp, true);
	
	fHpp << "#ifndef " << this->Head << std::endl;
	fHpp << "# define " << this->Head << std::endl << std::endl;
	fHpp << "#include <iostream>" << std::endl << std::endl;
	fHpp << "class " << this->Name << std::endl;
	fHpp << "{" << std::endl << "public:" << std::endl;
	fHpp << "\t" << this->Name << "();" << std::endl << std::endl;
	fHpp << "\t~" << this->Name << "();" << std::endl << std::endl;
	fHpp << "private:" << std::endl;
	fHpp << "};" << std::endl << std::endl;
	fHpp << "#endif /* !" << this->Head << " */" << std::endl;

	fCpp << "#include \"" << this->Name << ".hpp\"" << std::endl << std::endl;
	fCpp << this->Name << "::" << this->Name << "()" << std::endl;
	fCpp << "{" << std::endl << "}" << std::endl << std::endl << std::endl;
	fCpp << this->Name << "::~" << this->Name << "()" << std::endl;
	fCpp << "{" << std::endl << "}";

	fHpp.close();
	fCpp.close();
	return true;
}

ClassGenerator::~ClassGenerator()
{
}
