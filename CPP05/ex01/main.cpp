#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Form form("papelipoupi 1", 1, 2);
		Bureaucrat bureaucrat("allo", 1);
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form form("papelipoupi 2", 5, 2);
		Bureaucrat bureaucrat("allo", 15);
		// form.beSigned(bureaucrat);
		bureaucrat.signForm(form);
		std::cout << form << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}