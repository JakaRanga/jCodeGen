//
// EPITECH PROJECT, 2018
// AutoMk.hpp
// File description:
//
//

#ifndef AUTOMK_HPP_
# define AUTOMK_HPP_

#include <iostream>
#include <fstream>
#include <string>

class AutoMk
{
public:
	AutoMk(const int &ac, char **av);

	int		getMod();
	std::string	getUserName();
	
	void		sayHello();
	bool		verifyParams();

	bool		fileExist();
	std::ofstream	&putHeader(std::ofstream&);
	bool		writeFile();
	
	~AutoMk();

private:
	int	Ac;
	int	Mod;
	char	**Av;
	bool	isCpp;
};

#endif /* !AUTOMK_HPP_ */
