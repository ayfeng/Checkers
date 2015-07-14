#ifndef CHECKER_EXCEPTIONS_HPP
#define CHECKER_EXCEPTIONS_HPP

#include <exception>
#include <string>
using std::string;

namespace checkers {
    class InvalidMoveException: public std::exception {
        public:
            explicit InvalidMoveException(const string& message);
            virtual const char* what() const throw();
        private:
            string message;
    };
}
#endif
