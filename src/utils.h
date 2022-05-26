#ifndef UTILS_H
#define UTILS_H

#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>

namespace utils {
void printArray(int arr[], int n);
template <typename T>
double measureTimeOfFunction(std::function<T *(int *, int)> f, int arr[], int n);

} // namespace utils

class CSV {
private:
  std::string filename;
  std::fstream file;
  std::string delimiter = ",";

public:
  CSV(std::string filename);
  ~CSV() { this->file.close(); }
  void changeDelimiterTo(std::string delimiter) { this->delimiter = delimiter; }

  template <typename T>
  void writeVector(std::vector<T> v) {
    file.clear();
    file.seekp(0, std::ios::end);
    int sizeMinusOne = v.size() - 1;
    for (int i = 0; i < sizeMinusOne; i++) {
      file << v[i] << delimiter;
    }
    file << v[sizeMinusOne] << "\n";
  }

  template <typename T>
  void writeArray(T a[], int n) {
    file.clear();
    file.seekp(0, std::ios::end);
    int sizeMinusOne = n - 1;
    for (int i = 0; i < sizeMinusOne; i++) {
      file << a[i] << delimiter;
    }
    file << a[sizeMinusOne] << std::endl;
  }

  template <typename T>
  void writeWithDelimiter(T t) {
    file.clear();
    file.seekp(0, std::ios::end);
    file << t << delimiter;
  }

  template <typename T>
  void writeRaw(T t) {
    file.clear();
    file.seekp(0, std::ios::end);
    file << t;
  }

  std::vector<std::vector<std::string>> readAll(bool skipHeader = false) {
    file.clear();
    file.seekg(0, std::ios::beg);

    std::vector<std::vector<std::string>> result;
    std::string line;
    if (skipHeader) {
      std::getline(file, line);
    }
    while (std::getline(file, line)) {
      std::vector<std::string> lineSplit;
      std::stringstream ss(line);
      std::string item;
      while (std::getline(ss, item, delimiter[0])) {
        lineSplit.push_back(item);
      }
      result.push_back(lineSplit);
    }
    return result;
  }

  std::vector<std::string> readColumn(int column, bool skipHeader) {
    file.clear();
    file.seekg(0, std::ios::beg);
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

  std::vector<std::string> readRow(int row) {
    file.clear();
    file.seekg(0, std::ios::beg);
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
};

#endif // UTILS_H
