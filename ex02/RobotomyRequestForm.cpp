#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "*** RobotomyRequestForm was created***" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original) : AForm(original), target(target)
{
	std::cout << "Cpy Constructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	(void)rhs;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "***RobotomyRequestForm destroyed***" << std::endl;
}
