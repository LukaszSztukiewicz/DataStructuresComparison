#include "utils.h"
#include "gtest/gtest.h"

TEST(CSV, writeVector) {
  std::vector<int> v = {1, 2, 3, 4, 5};
  CSV csv("test.csv");
  csv.writeVector(v);
  std::ifstream file("test.csv");
  std::string line;
  std::getline(file, line);
  EXPECT_EQ(line, "1,2,3,4,5");
}