#include "Student.h"

Student::Student(int index, std::string firstName, std::string lastName) : InsertData(index), firstName(firstName), lastName(lastName){};

Student::~Student(){};

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

StudnetsGenerator::~StudnetsGenerator() {
  for (auto student : students)
    delete student;
}

void StudnetsGenerator::generate(int n, int indexSize, int stringLen, bool newlist) {
  if (newlist) {
    for (auto student : students)
      delete student;
    students.clear();
  }
  for (int i = 0; i < n; i++) {
    students.push_back(new Student(utils::randomInt(std::pow(10, indexSize), std::pow(10, indexSize + 1)), utils::randomString(stringLen), utils::randomString(stringLen)));
  }
}

void StudnetsGenerator::saveToCSV(std::string fileName) {
  CSV csv(fileName);
  for (auto student : students)
    csv.writeLine(student->toCSV());
}

void StudnetsGenerator::loadFromCSV(std::string fileName) {
  CSV csv(fileName);
  std::vector<std::vector<std::string>> lines = csv.readAll();
  for (auto line : lines) {
    students.push_back(new Student(std::stoi(line[0]), line[1], line[2]));
  }
}