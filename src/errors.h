#ifndef _SUDOKU_ERRORS_H_
#define _SUDOKU_ERRORS_H_ 1

// Thrown on Invalid input
class InvalidInputError: public std::exception {

    /*
    virtual const char* what() const throw() {
        return "";
    }
    */
};

#endif
