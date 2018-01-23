//
// EPITECH PROJECT, 2018
// class gen hpp
// File description:
// 
//

#ifndef CLASSGENERATOR_HPP_
# define CLASSGENERATOR_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class ClassGenerator
{
public:
	ClassGenerator(const std::string&);

	std::string	pickEnvName();
	
	std::string	getUserName();
	std::string	getHpp();

	std::ofstream		&putHeader(std::ofstream&, bool);
	
	bool		fileExist();
	bool		fileGen();

	~ClassGenerator();

private:
	std::string Name;
	std::string Head;
	std::string User;
};

#endif /* !CLASSGENERATOR_HPP_ */
