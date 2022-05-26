#include "utils.h"

namespace utils {

int randomInt(int min, int max) {
  return rand() % (max - min) + min;
}

std::string randomString(int len) {
  std::string str = "";
  for (int i = 0; i < len; i++)
    str += (char)(rand() % 26 + 97);
  return str;
}

} // namespace utils

CSV::CSV(std::string filename) : filename(filename){};

void CSV::writeLine(std::string line, std::string end) {
  std::ofstream file;
  file.open(filename, std::ios_base::app);
  file << line << end;
  file.close();
}

void CSV::writeVector(std::vector<std::string> v) {
  std::string line = "";
  for (auto s : v)
    line += s + delimiter;
  writeLine(line, "\n");
}

std::vector<std::string> CSV::readRow(int row) {
  std::fstream file;
  file.open(filename, std::fstream::out);
  std::vector<std::string> result;
  std::string line;
  for (int i = 0; i <= row; i++) {
    std::getline(file, line);
  }
  std::stringstream ss(line);
  std::string item;
  while (std::getline(ss, item, delimiter[0])) {
    result.push_back(item);
  }
  return result;
}
std::vector<std::string> CSV::readColumn(int column, bool skipHeader) {
  std::fstream file;
  file.open(filename, std::fstream::out);
  std::vector<std::string> result;
  std::string line;
  if (skipHeader) {
    std::getline(file, line);
  }
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string item;
    for (int i = 0; i <= column; i++) {
      std::getline(ss, item, delimiter[0]);
    }
    result.push_back(item);
  }
  return result;
}

std::vector<std::vector<std::string>> CSV::readAll(bool skipHeader) {
  std::fstream file;
  file.open(filename, std::fstream::out);
  std::vector<std::vector<std::string>> result;
  std::string line = "";
  if (skipHeader) {
    std::getline(file, line);
  }
  int i = 3;
  while (!file.eof()) {
    file >> line;
    std::vector<std::string> lineSplit;
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, delimiter[0])) {
      lineSplit.push_back(item);
    }
    result.push_back(lineSplit);
  }
  file.close();
  return result;
}