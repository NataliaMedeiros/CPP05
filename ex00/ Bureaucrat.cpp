#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		//include action
	if (grade > 150)
		//include action
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
	std::cout << "Bureaucrat named " << name << " was destroid" << std::endl;

}

std::string	Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::setGrade(int newGrade)
{
	grade = newGrade;
}

void	Bureaucrat::incrementGrade()
{
	if (grade >= 150)
		// go to exception
	grade++;
}

void	Bureaucrat::decrementGrade()
{

}
