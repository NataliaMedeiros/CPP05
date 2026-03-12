	#ifndef SHRUBBERYCREATIONFORM_HPP
	#define SHRUBBERYCREATIONFORM_HPP

	#include "AForm.hpp"
	#include "Bureaucrat.hpp"

	class ShrubberyCreationForm : AForm
	{
		private:
			const std::string	target;
		public:
			ShrubberyCreationForm(const std::string target);
			ShrubberyCreationForm(const ShrubberyCreationForm& original);
			ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
			~ShrubberyCreationForm();

			std::string	getTarget() const;
			void		execute() const override;//implement
	};

	#endif
