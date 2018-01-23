//
// EPITECH PROJECT, 2018
// classgen main
// File description:
// 
//

#include "ClassGenerator.hpp"

void	usage(int mode)
{
	printf("\033[01;31m");
	if (mode == 0)
	{
		std::cout << "You have to pass the Class Name to create .cpp/.hpp files!";
		std::cout << std::endl;
		std::cout << "Usage :" << std::endl;
		std::cout << "\t./jClassGen [Class Name]" << std::endl;
	}
	else if (mode == 1)
	{
		std::cout << "/!\\ ERROR! .hpp and .cpp files can't be created!";
		std::cout << std::endl;
	}
	printf("\033[01;37m");
	std::cout << "\tMade by JakaRanga." << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc <= 1 || argc >= 3)
		return (usage(0), 84);
	
	ClassGenerator cGen(argv[1]);

	if (!cGen.fileExist())
		return (usage(1), 84);
	if (!cGen.fileGen())
		return (usage(1), 84);
	printf("\033[22;32m");
	std::cout << "It's done my brudda, " << cGen.getUserName() << "!" << std::endl
		  << "Good luck writting your code!" << std::endl;
	printf("\033[01;37m");
	std::cout << "\tMade by JakaRanga." << std::endl;
	return 0;
}
