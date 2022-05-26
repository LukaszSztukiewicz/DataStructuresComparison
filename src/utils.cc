#include "utils.h"

namespace utils {

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

template <typename T>
double measureTimeOfFunction(std::function<T *(int *, int)> f, int arr[], int n) {
  auto start_ch = std::chrono::high_resolution_clock::now();
  f(arr, n);
  auto end_ch          = std::chrono::high_resolution_clock::now();
  double time_taken_ch = std::chrono::duration_cast<std::chrono::nanoseconds>(end_ch - start_ch).count() * 1e-9;
  return time_taken_ch;
}

} // namespace utils

CSV::CSV(std::string filename) {
  this->filename = filename;
  this->file.open(filename, std::ofstream::out | std::ofstream::in | std::ofstream::trunc);
}
