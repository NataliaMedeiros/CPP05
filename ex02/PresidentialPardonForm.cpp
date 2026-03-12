#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{

}
		PresidentialPardonForm(const PresidentialPardonForm& original);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
		~PresidentialPardonForm();
