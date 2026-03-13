#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	AForm* form;

	std::cout << "=== Test 1: Shrubbery Creation Form ===" << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "Home");
	if (form)
	{
		std::cout << "Form created: " << form->getName() << std::endl;
		delete form;
	}

	std::cout << "\n=== Test 2: Robotomy Request Form ===" << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form)
	{
		std::cout << "Form created: " << form->getName() << std::endl;
		delete form;
	}

	std::cout << "\n=== Test 3: Presidential Pardon Form ===" << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "Alice");
	if (form)
	{
		std::cout << "Form created: " << form->getName() << std::endl;
		delete form;
	}

	std::cout << "\n=== Test 4: Invalid Form ===" << std::endl;
	form = someRandomIntern.makeForm("invalid form", "Nobody");
	if (form)
		delete form;

	return (0);
}
