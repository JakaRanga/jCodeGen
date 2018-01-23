//
// EPITECH PROJECT, 2018
// make gen
// File description:
// 
//

#include "AutoMk.hpp"

void	usage(int mod)
{
	if (mod == 1)
	{
		printf("\033[22;32m");
		std::cout << "\tUsage: ./jAutoMakefile [binary name] [files]" << std::endl;
	}
	if (mod == 2)
	{
		printf("\033[01;31m");
		std::cout << "\t/!\\ERROR! Your binary name is not correct!" << std::endl;
	}
	if (mod == 3)
	{
		printf("\033[01;31m");
		std::cout << "\t/!\\ ERROR! A Makefile is already created!" << std::endl;
	}
	printf("\033[22;32m");
	std::cout << "Made by Jeremy BOUTON (JakaRanga)" << std::endl;
	printf("\033[01;37m");
}

int	main(int ac, char **av)
{
	AutoMk *mk;

	mk = new AutoMk(ac, av);
	mk->sayHello();
	if (!mk->verifyParams())
		return (usage(mk->getMod()), 84);
	if (!mk->writeFile())
		return (usage(mk->getMod()), 84);
	else
		usage(0);
	return 0;
}
