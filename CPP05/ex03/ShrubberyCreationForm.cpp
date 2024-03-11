#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): AForm("shrubbery creation", 145, 137), _target(target) {
	// std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& inst ): AForm(inst), _target(inst._target) {
	*this = inst;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){

}

std::string	ShrubberyCreationForm::getTarget() const{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (!getIsSigned())
		throw std::invalid_argument("Form isn't signed");
	if (executor.getGrade() > getSignGrade() || executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	std::string file = getTarget() + "_shrubbery";
	std::ofstream ofs(file);
	if (ofs.fail())
		throw std::invalid_argument(file + " permission denied");
	for (int i = 0; i < 3; i++) {
		ofs << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
		ofs << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
		ofs << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
		ofs << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
		ofs << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
		ofs << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
		ofs << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
		ofs << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
		ofs << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
		ofs << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
		ofs << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
		ofs << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
		ofs << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
		ofs << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
		ofs << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
		ofs << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
		ofs << "             {/{\\{\\{\\/}/}{\\{\\}/}" << std::endl;
		ofs << "              {){/ {\\/}{\\/} \\}\\}" << std::endl;
		ofs << "              (_)  \\.-'.-/" << std::endl;
		ofs << "          __...--- |'-.-'| --...__" << std::endl;
		ofs << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl;
		ofs << " -\"    ' .  . '    |.'-._| '  . .  '   jro" << std::endl;
		ofs << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
		ofs << "          ' ..     |'-_.-|" << std::endl;
		ofs << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
		ofs << "              .'   |'- .-|   '." << std::endl;
		ofs << "  ..-'   ' .  '.   `-._.-�   .'  '  - ." << std::endl;
		ofs << "   .-' '        '-._______.-'     '  ." << std::endl;
	}
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& inst ){
	this->_target = inst._target;
	return *this;
}
