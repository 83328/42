#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &to_copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &original);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const &executor) const;
};

#endif
