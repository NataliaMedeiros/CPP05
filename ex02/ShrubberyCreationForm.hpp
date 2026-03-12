	#ifndef SHRUBBERYCREATIONFORM_HPP
	#define SHRUBBERYCREATIONFORM_HPP

	#include "AForm.hpp"
	#include "Bureaucrat.hpp"
	#include <fstream>

	class ShrubberyCreationForm : public AForm
	{
		private:
			const std::string	target;
		public:
			ShrubberyCreationForm(const std::string target);
			ShrubberyCreationForm(const ShrubberyCreationForm& original);
			ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
			~ShrubberyCreationForm();

			std::string	getTarget() const;
			void	execute(Bureaucrat const & executor) const override;
	};

	#endif
