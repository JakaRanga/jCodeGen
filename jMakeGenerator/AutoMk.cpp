//
// EPITECH PROJECT, 2018
// AutoMk.cpp
// File description:
//
//

#include "AutoMk.hpp"

AutoMk::AutoMk(const int &ac, char **av)
{
	this->Ac = ac;
	this->Av = av;
	this->Mod = 0;
	this->isCpp = true;
}

int		AutoMk::getMod()
{
	return this->Mod;
}

std::string	AutoMk::getUserName()
{
	std::string	name;

	name = std::getenv("USER");
	if (name[0] >= 'a' && name[0] <= 'z')
		name[0] -= 32;
	return name;
}

void		AutoMk::sayHello()
{
	printf("\033[01;36m");
	std::cout << "Hello " << this->getUserName() << "!" << std::endl;
	printf("\033[01;37m");
}

bool		AutoMk::verifyParams()
{
	int		i = 0;
	
	if (this->Ac < 3)
		return ((this->Mod = 1), false);
	while (this->Av[1][i++])
		if (this->Av[1][i] == '.')
			return ((this->Mod = 2), false);
	for (i = 2; this->Av[i]; i++)
	{
		std::string	str(this->Av[i]);
		if (str.find(".cpp") == std::string::npos)
			this->isCpp = false;
		else
			this->isCpp = true;
	}
	return true;
}

bool		AutoMk::fileExist()
{
	std::ifstream	tmp("Makefile");

	if (tmp.is_open())
	{
		std::string     gLine;
		std::size_t     y;

		printf("\033[01;31m");
		std::cout << "Do you really want overwrite the existing Makefile?"
			  << std::endl;
		printf("\033[01;37m");
		std::cout << "\t(N / y)" << std::endl;

		std::getline(std::cin, gLine);
		y = gLine.find("y");

		if (y == 0)
			return (false);
		else
			return ((this->Mod = 3), true);
	}
	tmp.close();
	return false;
}

std::ofstream	&AutoMk::putHeader(std::ofstream &mk)
{
	mk << "##" << std::endl << "## EPITECH PROJECT, 2018" << std::endl
           << "## Makefile" << std::endl
           << "## File description:" << std::endl
           << "##" << std::endl << "##" << std::endl << std::endl;
							
	return mk;
}

bool		AutoMk::writeFile()
{
	if (this->fileExist())
		return false;
	
	std::ofstream	mk("Makefile");

	this->putHeader(mk);

	mk << "SRCS\t=\t" << this->Av[2] << "\t\\" << std::endl;
	for (int i = 3; this->Av[i]; i++)
	{
		mk << "\t\t" << this->Av[i]
		   << ((this->Av[i + 1] != NULL) ? "\t\\" : "") << std::endl;
	}
	mk << std::endl << "OBJS\t=\t$(SRCS:" << ((this->isCpp) ? ".cpp" : ".c") << "=.o)"
	   << std::endl << std::endl << "NAME\t=\t" << this->Av[1] << std::endl
	   << std::endl << "CC\t=\t" << ((this->isCpp) ? "g++" : "gcc") << std::endl
	   << std::endl << "LDFLAGS\t=\t-W -Wall -Wextra -Werror" << std::endl
	   << std::endl << "$(NAME):\t$(OBJS)" << std::endl << "\t\t"
	   << "$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)" << std::endl
	   << std::endl << "all:\t\t$(NAME)" << std::endl
	   << std::endl << "re:\t\tfclean all" << std::endl
	   << std::endl << "clean:" << std::endl << "\t\trm -f $(OBJS)" << std::endl
	   << std::endl << "fclean:\t\tclean" << std::endl << "\t\trm -f $(NAME)"
	   << std::endl << std::endl << ".PHONY:\t\tall clean fclean re";

	mk.close();
	printf("\033[22;32m");
	std::cout << "\tYour Makefile have been generated!" << std::endl;
	printf("\033[01;37m");
	return true;
}

AutoMk::~AutoMk()
{
}
