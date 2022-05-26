#include "StudentClass.h"

Student::Student(int index, std::string firstname, std::string lastname) : InsertData(index), firstname(firstname), lastname(lastname){};

Student::~Student(){};

void Student::print() {
  std::cout << std::to_string(index) << " " << firstname << " " << lastname << '\n';
}

std::string Student::toString() {
  return std::to_string(index) + " " + firstname + " " + lastname;
}

std::string Student::toCSV() {
  return std::to_string(index) + "," + firstname + "," + lastname;
}

std::string Student::getFirstname() {
  return firstname;
}

std::string Student::getLastname() {
  return lastname;
}

bool Student::operator==(const Student &other) const {
  return index == other.index && firstname == other.firstname && lastname == other.lastname;
}
