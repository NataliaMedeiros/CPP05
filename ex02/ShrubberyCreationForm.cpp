#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "***ShrubberyCreationForm was created***" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original) : AForm(original), target(original.target)
{
	std::cout << "Cpy Constructor" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	(void)rhs;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "***ShrubberyCreationForm destroyed***" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream file((target + "_shrubbery").c_str());

	file <<
	"       _-_\n"
	"    /~~   ~~\\\n"
	" /~~         ~~\\\n"
	"{               }\n"
	" \\  _-     -_  /\n"
	"   ~  \\ //  ~\n"
	"_- -   | | _- _\n"
	"  _ -  | |   -_\n"
	"      // \\\n";
}
