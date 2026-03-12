#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat named " << name << " was created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& original) : name(original.name), grade (original.grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		grade = rhs.grade;
	}
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat named " << name << " was destroyed" << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& object)
{
	os << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
	return (os);
}
