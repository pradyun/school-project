#ifndef SUDUKU_CONSTANTS_H
#define SUDUKU_CONSTANTS_H

#define DEBUG 0
#define SIZE 9

// Used to define the not-valid values
#define EMPTY 0
#define INVALID -1

#if DEBUG
#define LOG(s) std::cout << "    " << s << std::endl
#endif

#endif
