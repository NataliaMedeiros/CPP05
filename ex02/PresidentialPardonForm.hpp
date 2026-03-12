#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& original);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
		~PresidentialPardonForm();

		void execute() const override; //implement
};

#endif

