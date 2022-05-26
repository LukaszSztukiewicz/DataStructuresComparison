#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H

#include "DataStructure.h"
#include <iostream>
#include <string>
#include <vector>

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

class StudnetsGenerator {
private:
  std::vector<Student *> students;

public:
  StudnetsGenerator();
  ~StudnetsGenerator();
  void generate(int n, int indexSize, int stringLen, bool newlist = false);
  void saveToCSV(std::string filename);
  void loadFromCSV(std::string filename);
  void print(bool indicesOnly);
}

#endif // STUDENTCLASS_H
