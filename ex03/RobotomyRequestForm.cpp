#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "*** RobotomyRequestForm was created***" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original) : AForm(original), target(original.target)
{
	std::cout << "Cpy Constructor" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "***RobotomyRequestForm destroyed***" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor); // it's important to check the conditions 
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
