#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(nullptr)); //That ensures the robotomy result is different each run.

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

	RobotomyRequestForm r("Bender");

	boss.executeForm(r);
	return (0);
}
