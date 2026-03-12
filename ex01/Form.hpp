#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	private:
		std::string const	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExecute;
	public:
		Form(const std::string name, int sign, int execute);
		Form(const Form& original);
		Form& operator=(const Form& rhs);
		~Form();

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExecute() const;

		void		beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade is too High");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Grade is too Low");
				}
		};
};

std::ostream& operator<<(std::ostream& os, const Form& object);

#endif
