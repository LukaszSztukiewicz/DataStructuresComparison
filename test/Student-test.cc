#include "Student.h"
#include "gtest/gtest.h"

// create tests for Student class
TEST(Student, Constructor) {
  Student *s1 = new Student(123456789, "John", "Doe");
  EXPECT_EQ(123456789, s1->getIndex());
  EXPECT_EQ("John", s1->getFirstName());
  EXPECT_EQ("Doe", s1->getLastName());
  EXPECT_EQ("John Doe", s1->toString());
  EXPECT_EQ("123456789,John,Doe", s1->toCSV());
  delete s1;
}

// create tests for StudnetsGenerator generate function
TEST(StudnetsGenerator, Generate) {
  StudnetsGenerator sg;
  sg.generate(10, 4, 10);
  EXPECT_EQ(10, sg.students.size());
  EXPECT_EQ(10, sg.students[0]->getLastName().length());
  EXPECT_EQ(10, sg.students[0]->getFirstName().length());
  EXPECT_L(1, sg.students[0]->getIndex() / std::pow(10, 5));
};
