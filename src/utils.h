#ifndef UTILS_H
#define UTILS_H

#include <chrono>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>

namespace utils {
int randomInt(int min, int max);
std::string randomString(int len);
} // namespace utils

class CSV {
private:
  std::string filename;
  std::string delimiter = ",";

public:
  CSV(std::string filename, bool createNewFile = true);
  void clear();
  void changeDelimiterTo(std::string delimiter) { this->delimiter = delimiter; }
  void writeVector(std::vector<std::string> v);
  void writeLine(std::string line, std::string end = "\n", bool append = false);

  std::vector<std::vector<std::string>> readAll(bool skipHeader = false);
  std::vector<std::string> readColumn(int column, bool skipHeader);
  std::vector<std::string> readRow(int row);
};

#endif // UTILS_H
