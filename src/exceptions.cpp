#include "exceptions.hpp"
#include <string>

namespace checkers {
    InvalidMoveException::InvalidMoveException(const string& message): message(message) {}

    const char* InvalidMoveException::what() const throw() {
        return message.c_str();
    }
}
