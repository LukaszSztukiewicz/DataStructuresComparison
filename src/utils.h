#ifndef UTILS_H
#define UTILS_H

#include <chrono>
#include <fstream>
#include <functional>
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
  std::ofstream file;
  std::string delimiter = ",";

public:
  CSV(std::string filename) {
    this->filename = filename;
    this->file.open(filename, std::ofstream::out | std::ofstream::in);
  }

  ~CSV() { this->file.close(); }

  void changeDelimiterTo(std::string delimiter) {
    this->delimiter = delimiter;
  }

  template <typename T>
  void writeVector(std::vector<T> v) {
    int sizeMinusOne = v.size() - 1;
    for (int i = 0; i < sizeMinusOne; i++) {
      file << v[i] << delimiter;
    }
    file << v[sizeMinusOne] << "\n";
  }

  template <typename T>
  void writeArray(T a[], int n) {
    int sizeMinusOne = n - 1;
    for (int i = 0; i < sizeMinusOne; i++) {
      file << a[i] << delimiter;
    }
    file << a[sizeMinusOne] << std::endl;
  }

  template <typename T>
  void writeWithDelimiter(T t) {
    file << t << delimiter;
  }

  template <typename T>
  void writeRaw(T t) {
    file << t;
  }
};

#endif // UTILS_H
