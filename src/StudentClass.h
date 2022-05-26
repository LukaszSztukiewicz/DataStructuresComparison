#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H

#include "DataStructure.h"
#include <iostream>
#include <string>

class Student : public InsertData {
private:
  std::string firstname;
  std::string lastname;

public:
  Student(int index, std::string firstname, std::string lastname);
  ~Student();
  void print();
  std::string toString();
  std::string toCSV();
  std::string getFirstname();
  std::string getLastname();

  bool operator==(const Student &other) const;
};

#endif // STUDENTCLASS_H
