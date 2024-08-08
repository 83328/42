#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        const std::string _formName;
        bool _formSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

public:
    Form();
    Form(const std::string &name, int gradeToSign);
    Form(const Form &to_copy);
    Form &operator=(const Form &origin);
    ~Form();

    const std::string &getFormName() const;
    bool getFormSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("Error: Grade too high");
            }
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("Error: Grade too low");
            }
    };

    class FormAlreadySignedException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("Error: Form already signed");
            }
    };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif