#include "Bureaucrat.hpp"
#include "Form.hpp"

void	testDecrement(Bureaucrat &bureaucrat)
{
	std::cout << "*** " << bureaucrat.getName() << " was demoted **" << std::endl;
	std::cout << "Grade before demotion: " << bureaucrat.getGrade() << std::endl;
	try
	{
		bureaucrat.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Grade after demotion: " << bureaucrat.getGrade() << std::endl;
	std::cerr << std::endl;
}

void	testIncrement(Bureaucrat &bureaucrat)
{
	std::cout << "*** " <<  bureaucrat.getName() << " was promoted! **" << std::endl;
	std::cout << "Grade before promotion: " << bureaucrat.getGrade() << std::endl;
	try
	{
		bureaucrat.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Grade after promotion: " << bureaucrat.getGrade() << std::endl;
	std::cerr << std::endl;
}

void	testHighGrade()
{
	std::cout << "*** Creating a bureaucrat with a grade too high: ***" << std::endl;
	try
	{
		Bureaucrat smuck("BobHigh", -2);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error creating bureaucrat, " << e.what() << std::endl;
	}
	std::cerr << std::endl;
}
void	testLowGrade()
{
	std::cout << "*** Creating a bureaucrat with a grade too low: ***" << std::endl;
	try
	{
		Bureaucrat  smuck("BobLow", 160);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error creating bureaucrat, " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	// TODO -> check about try to inscribe twice on the same form
	// Creating bureaucrats and forms
	std::cout << "*** Creating bureaucrats and forms: ***" << std::endl;
	Bureaucrat	bob("Bob", 10);
	Bureaucrat alice("Alice", 2);
	Form		form1("Form1", 2, 1);
	Form form2("Form2", 1, 1);
	std::cout << std::endl;

	// Creating invalids form
	std::cout << "*** Creating a too low grade invalid form ***" << std::endl;
	try
	{
		Form	wrongForm("too low", 200, 200);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error creating form, " << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "*** Creating a too high grade invalid form ***" << std::endl;
	try
	{
		Form	wrongForm("too high", 0, 0);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error creating form, " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Attempt to sign with Bob (grade 10) → should fail for form1 and form2
	std::cout << "*** Attempt to sign with Bob (grade 10) → should fail for form1 and form2: ***" << std::endl;
	bob.signForm(form1);
	bob.signForm(form2);
	std::cout << std::endl;

	// Attempt to sign with Alice (grade 1) → should succeed for both forms
	std::cout << "*** Alice attempts to sign forms: ***" << std::endl;
	alice.signForm(form1);
	alice.signForm(form2);
	std::cout << std::endl;

	// Print form statuses using the operator<< overload
	std::cout << "*** Form statuses after signing attempts: ***" << std::endl;
	std::cout << form1;
	std::cout << form2;
	std::cout << std::endl;

	// Increment Bob's grade for him to be accepted on both forms:
	std::cout << "*** Increment Bob's grade for him to be accepted on both forms: ***" << std::endl;
	while (bob.getGrade() > 1)
		bob.incrementGrade();
	std::cout << "The current grade of Bob is: " << bob.getGrade() << std::endl;

	std::cout << std::endl;
	bob.signForm(form1);
	std::cout << std::endl;

	testIncrement(alice);
	testDecrement(bob);

	// Destructors being called
	std::cout << "*** Destructors being called: ***" << std::endl;
	return (0);;
}
