#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern was created" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern was destroyed" << std::endl;
}

AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	const std::string forms[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (*creators[3])(const std::string&) = {
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](formTarget);
		}
	}
	std::cout << "Error: form \"" << formName << "\" does not exist" << std::endl;
	return nullptr;
}
