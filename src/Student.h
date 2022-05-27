#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H

#include "DataStructure.h"
#include "utils.h"
#include <iostream>
#include <string>
#include <vector>

class Student : public InsertData {
private:
  std::string firstName;
  std::string lastName;

public:
  Student(int index, std::string firstName, std::string lastName);
  ~Student();
  void print();
  std::string toString();
  std::string toCSV();
  std::string getFirstName();
  std::string getLastName();

  bool operator==(const Student &other) const;
};

class StudentsGenerator {

public:
  std::vector<Student *> students;
  StudentsGenerator();
  ~StudentsGenerator();
  void generate(int n, int indexSize, int stringLen, bool newlist = false);
  void saveToCSV(std::string fileName);
  void loadFromCSV(std::string fileName);
  void print(bool indicesOnly, int limit = -1);
};

#endif // STUDENTCLASS_H
