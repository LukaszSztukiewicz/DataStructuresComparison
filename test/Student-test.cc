#include "Student.h"
#include "gtest/gtest.h"

// create tests for Student class
TEST(Student, Constructor) {
  Student *s1 = new Student(123456789, "John", "Doe");
  EXPECT_EQ(123456789, s1->getIndex());
  EXPECT_EQ("John", s1->getFirstName());
  EXPECT_EQ("Doe", s1->getLastName());
  EXPECT_EQ("123456789 John Doe", s1->toString());
  EXPECT_EQ("123456789,John,Doe", s1->toCSV());
  delete s1;
}

// create tests for StudnetsGenerator generate function
TEST(StudnetsGenerator, Generate) {
  StudnetsGenerator *sg = new StudnetsGenerator();
  sg->generate(10, 4, 10);
  EXPECT_EQ(10, sg->students.size());
  EXPECT_EQ(10, sg->students[0]->getLastName().length());
  EXPECT_EQ(10, sg->students[0]->getFirstName().length());
  EXPECT_GE(1, sg->students[0]->getIndex() / std::pow(10, 5));
};

// create tests for StudnetsGenerator saveToCSV function
TEST(StudnetsGenerator, SaveToCSV) {
  StudnetsGenerator *sg = new StudnetsGenerator();
  sg->generate(10, 4, 10);
  sg->saveToCSV("test.csv");
  StudnetsGenerator *sg2 = new StudnetsGenerator();
  sg2->loadFromCSV("test.csv");
  EXPECT_EQ(10, sg2->students.size());
  EXPECT_EQ(10, sg2->students[0]->getLastName().length());
  EXPECT_EQ(10, sg2->students[0]->getFirstName().length());
  EXPECT_GE(1, sg2->students[0]->getIndex() / std::pow(10, 5));
  EXPECT_EQ(sg->students[0]->getIndex(), sg2->students[0]->getIndex());
  EXPECT_EQ(sg->students[0]->getFirstName(), sg2->students[0]->getFirstName());
  EXPECT_EQ(sg->students[0]->getLastName(), sg2->students[0]->getLastName());
  int randomIndex = utils::randomInt(0, 9);
  EXPECT_EQ(sg->students[randomIndex]->getIndex(), sg2->students[randomIndex]->getIndex());
  EXPECT_EQ(sg->students[randomIndex]->getFirstName(), sg2->students[randomIndex]->getFirstName());
  EXPECT_EQ(sg->students[randomIndex]->getLastName(), sg2->students[randomIndex]->getLastName());
}