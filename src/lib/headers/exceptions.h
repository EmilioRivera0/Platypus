#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

// necessary includes -------->
#include <exception>

// exception declaration -------->
namespace exc {
// 1. Incorrect File Name
struct FileName : std::exception{
  const char * what() const noexcept {
    return "1. Incorrect File Name.\n";
  }
};
// 2. File Not Opened
struct FileNotOpened : std::exception{
  const char * what() const noexcept {
    return "2. File Not Opened.\n";
  }
};
}
#endif // !EXCEPTIONS_H
