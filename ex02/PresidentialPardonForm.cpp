#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "*** PresidentialPardonForm was created***" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original) : AForm(original), target(original.target)
{
	std::cout << "Cpy Constructor" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	(void)rhs;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "***PresidentialPardonForm destroyed***" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::cout << target
	<< " has been pardoned by Zaphod Beeblebrox"
	<< std::endl;
}
