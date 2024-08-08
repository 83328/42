#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

		public:
			RobotomyRequestForm();
			RobotomyRequestForm(std::string target);
			RobotomyRequestForm(const RobotomyRequestForm &to_copy);
			RobotomyRequestForm &operator=(const RobotomyRequestForm &original);
			~RobotomyRequestForm();

			void execute(Bureaucrat const &executor) const;
};

#endif
