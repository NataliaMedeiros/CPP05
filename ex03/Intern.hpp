#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other) = default; //check this default
		Intern& operator=(const Intern& other) = default;
		~Intern();

		AForm*	makeForm(const std::string &formName, const std::string &formTarget);
};

#endif
