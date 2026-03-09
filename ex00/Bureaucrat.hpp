#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& original);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		std::string getName() const;
		int			getGrade() const;
		void		setGrade(int newGrade);

		void		incrementGrade();
		void		decrementGrade();

		/* The subject says the exceptions must be catchable using try{} catch {}, and
			for this to work, the class must inherit from std::exception.
			The exceptions are nested inside Bureaucrat, because these
			exceptions belong to Bureaucrat and are used only for its errors.*/
		class GradeTooHighException : public std::exception
		{
			private:
				/* data */
			public:
				GradeTooHighException(/* args */);
				~GradeTooHighException();
			public:
				const char* what() const throw()
				{
					return "Grade too high";
				}
		};

		class GradeTooLowException
		{
			private:
				/* data */
			public:
				GradeTooLowException(/* args */);
				~GradeTooLowException();
			public:
				const char* what() const throw()
				{
					return "Grade too low";
				}
		};
};

#endif
