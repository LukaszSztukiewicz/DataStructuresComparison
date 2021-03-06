#include "Student.h"

Student::Student(int index, std::string firstName, std::string lastName) : InsertData(index), firstName(firstName), lastName(lastName){};

Student::~Student(){

};

void Student::print() {
  std::cout << std::to_string(index) << " " << firstName << " " << lastName << '\n';
}

std::string Student::toString() {
  return std::to_string(index) + " " + firstName + " " + lastName;
}

std::string Student::toCSV() {
  return std::to_string(index) + "," + firstName + "," + lastName;
}

std::string Student::getFirstName() {
  return firstName;
}

std::string Student::getLastName() {
  return lastName;
}

bool Student::operator==(const Student &other) const {
  return index == other.index && firstName == other.firstName && lastName == other.lastName;
}

StudentsGenerator::StudentsGenerator() {
}

StudentsGenerator::~StudentsGenerator() {
  for (auto student : students)
    delete student;
}

void StudentsGenerator::generate(int n, int indexSize, int stringLen, bool newlist) {
  if (newlist) {
    for (auto student : students)
      delete student;
    students.clear();
  }
  for (int i = 0; i < n; i++) {
    students.push_back(new Student(utils::randomInt(std::pow(10, indexSize - 1), std::pow(10, indexSize)), utils::randomString(stringLen), utils::randomString(stringLen)));
  }
}

void StudentsGenerator::saveToCSV(std::string fileName) {
  CSV csv(fileName);
  for (int i = 0; i < students.size() - 1; i++) {
    csv.writeLine(students[i]->toCSV());
  }
  csv.writeLine(students[students.size() - 1]->toCSV());
}

void StudentsGenerator::loadFromCSV(std::string fileName) {
  CSV csv(fileName, false);
  std::vector<std::vector<std::string>> lines = {};

  lines = csv.readAll();
  for (auto line : lines) {
    students.push_back(new Student(std::stoi(line[0]), line[1], line[2]));
  }
}

void StudentsGenerator::print(bool indicesOnly, int limit) {
  for (int i = 0; i < students.size(); i++) {
    if (indicesOnly)
      std::cout << students[i]->getIndex() << '\n';
    else
      students[i]->print();
    if (limit != -1 && i == limit)
      break;
  }
}