#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	testDecrement(Bureaucrat &bureaucrat)
{
	std::cout << "*** " << bureaucrat.getName() << " was demoted **" << std::endl;
	std::cout << "Grade before demotion: " << bureaucrat.getGrade() << std::endl;
	try
	{
		bureaucrat.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Grade after demotion: " << bureaucrat.getGrade() << std::endl;
	std::cerr << std::endl;
}

void	testIncrement(Bureaucrat &bureaucrat)
{
	std::cout << "*** " <<  bureaucrat.getName() << " was promoted! **" << std::endl;
	std::cout << "Grade before promotion: " << bureaucrat.getGrade() << std::endl;
	try
	{
		bureaucrat.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Grade after promotion: " << bureaucrat.getGrade() << std::endl;
	std::cerr << std::endl;
}

void	testHighGrade()
{
	std::cout << "*** Creating a bureaucrat with a grade too high: ***" << std::endl;
	try
	{
		Bureaucrat smuck("BobHigh", -2);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error creating bureaucrat, " << e.what() << std::endl;
	}
	std::cerr << std::endl;
}
void	testLowGrade()
{
	std::cout << "*** Creating a bureaucrat with a grade too low: ***" << std::endl;
	try
	{
		Bureaucrat  smuck("BobLow", 160);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error creating bureaucrat, " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	srand(time(NULL));

	Bureaucrat boss("Boss", 1);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Ford");

	boss.signForm(shrub);
	boss.signForm(robot);
	boss.signForm(pardon);

	boss.executeForm(shrub);
	boss.executeForm(robot);
	boss.executeForm(pardon);
	return (0);
}
