#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, int sign, int execute) : name(name), isSigned(false), gradeSign(sign), gradeExecute(execute)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	std::cout << "An unsigned form was created" << std::endl;
}
Form::Form(const Form& original) : name(original.name), isSigned(original.isSigned), gradeSign(original.gradeSign), gradeExecute(original.gradeExecute)
{
	std::cout << "Copy form was created" << std::endl;
}
Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		isSigned = rhs.isSigned;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form was destroyed" << std::endl;
}

std::string	Form::getName() const
{
	return(name);
}

bool	Form::getSigned() const
{
	return (isSigned);
}

int	Form::getGradeSign() const
{
	return (gradeSign);
}

int	Form::getGradeExecute() const
{
	return (gradeExecute);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& object)
{
	os << "Form: " << object.getName() <<
	", requires grade " << object.getGradeSign() <<
	" to sign and grade " << object.getGradeExecute() <<
	" to execute. It's currently " << (object.getSigned() ? "signed" : "unsigned") << std::endl;
	return (os);
}

