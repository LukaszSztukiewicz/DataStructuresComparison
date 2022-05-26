#include "DataStructure.h"

InsertData::InsertData(int index) : index(index){};

void InsertData::print() {
  std::cout << index << '\n';
}

int InsertData::getIndex() {
  return index;
}

std::string InsertData::toString() {
  return std::to_string(index);
}

bool InsertData::operator==(const InsertData &other) const {
  return index == other.index;
}