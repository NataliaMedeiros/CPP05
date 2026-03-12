#include "Bureaucrat.hpp"

void	testDecrement(Bureaucrat &bob)
{
	std::cout << "** Bob was demoted **" << std::endl;
	std::cout << "Grade before demotion: " << bob.getGrade() << std::endl;
	try
	{
		bob.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Grade after demotion: " << bob.getGrade() << std::endl;
	std::cerr << std::endl;
}

void	testIncrement(Bureaucrat &bob)
{
	std::cout << "** Bob was promoted! **" << std::endl;
	std::cout << "Grade before promotion: " << bob.getGrade() << std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Grade after promotion: " << bob.getGrade() << std::endl;
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
	// Creating a bureaucrat
	std::cout << "*** Creating a bureaucrat: ***" << std::endl;
	Bureaucrat  bob("Bob", 69);
	std::cout << std::endl;

	testIncrement(bob);
	testDecrement(bob);
	testLowGrade();
	testHighGrade();

	//Try to promote a bureaucrat too high
	std::cout << "*** Try to promote a bureaucrat too high: ***" << std::endl;
	while (bob.getGrade() > 1)
	{
		bob.incrementGrade();
	}
	std::cout << "Grade before promotion's try: " << bob.getGrade() << std::endl;
	try
	{
		bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Grade after promotion's try: " << bob.getGrade() << std::endl;
	std::cerr << std::endl;

	//Try to demote a bureaucrat too low
	std::cout << "*** Try to demote a bureaucrat too low: ***" << std::endl;
	while (bob.getGrade() < 150)
	{
		bob.decrementGrade();
	}
	std::cout << "Grade before try to demote: " << bob.getGrade() << std::endl;
	try
	{
		bob.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Grade after try to demote: " << bob.getGrade() << std::endl;
	std::cerr << std::endl;

    // test implemention of the insertion operator overload
    std::cout <<"*** Test implemention of the insertion operator overload: ***" << std::endl;
    std::cout << bob << std::endl;
    std::cout << std::endl;

    std::cout << "** Bob is murdered **" << std::endl;
    return (0);
}
