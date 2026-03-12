#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, int sign, int execute) : name(name), isSigned(false), gradeSign(sign), gradeExecute(execute)
{
	if (gradeSign < 1 || gradeExecute < 1)
		throw GradeTooHighException();
	else if (gradeSign > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	std::cout << "An unsigned form was created" << std::endl;
}
AForm::AForm(const AForm& original) : name(original.name), isSigned(original.isSigned), gradeSign(original.gradeSign), gradeExecute(original.gradeExecute)
{
	std::cout << "Copy form was created" << std::endl;
}
AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
		isSigned = rhs.isSigned;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Form was destroyed" << std::endl;
}

std::string	AForm::getName() const
{
	return(name);
}

bool	AForm::getSigned() const
{
	return (isSigned);
}

int	AForm::getGradeSign() const
{
	return (gradeSign);
}

int	AForm::getGradeExecute() const
{
	return (gradeExecute);
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > gradeSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& object)
{
	os << "Form: " << object.getName() <<
	", requires grade " << object.getGradeSign() <<
	" to sign and grade " << object.getGradeExecute() <<
	" to execute. It's currently " << (object.getSigned() ? "signed" : "unsigned") << std::endl;
	return (os);
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned)
		throw FormNotSignedException();

	if (executor.getGrade() > gradeExecute)
		throw GradeTooLowException();
}

