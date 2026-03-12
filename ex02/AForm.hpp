#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	private:
		std::string const	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExecute;
	public:
		AForm(const std::string name, int sign, int execute);
		AForm(const AForm& original);
		AForm& operator=(const AForm& rhs);
		virtual ~AForm();

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeSign() const;
		int			getGradeExecute() const;

		void			beSigned(const Bureaucrat& b);
		virtual void	execute(Bureaucrat const & executor) const = 0;

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
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Form is not signed";
				}
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& object);

#endif
