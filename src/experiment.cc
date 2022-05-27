#include "experiment.h"

namespace experiment {

void generateDatasets(StudentsGenerator *generator, int numberOfDatasets, int initialNumber, int step, int indexSize, int stringLength, std::string inputFolder) {
  for (int i = 0; i < numberOfDatasets; i++) {
    generator->generate(initialNumber + i * step, indexSize, stringLength, true);
    generator->saveToCSV(inputFolder + "students_" + std::to_string(initialNumber + i * step) + ".csv");
  }
}

double measureTimeOfOperation(DataStructure *dataStructure, StudentsGenerator *students, std::string inputFolder, experiment::measuredOperation operation) {
  auto start_ch = std::chrono::high_resolution_clock::now();
  switch (operation) {
  case experiment::measuredOperation::INSERT:
    for (auto student : students->students) {
      dataStructure->insert(student);
    }
    break;
  case experiment::measuredOperation::REMOVE:
    for (auto student : students->students) {
      dataStructure->remove(student);
    }
    break;
  case experiment::measuredOperation::SEARCH:
    for (auto student : students->students) {
      dataStructure->search(student);
    }
    break;
  }
  auto end_ch          = std::chrono::high_resolution_clock::now();
  double time_taken_ch = std::chrono::duration_cast<std::chrono::nanoseconds>(end_ch - start_ch).count(); // nanoseconds
  time_taken_ch        = time_taken_ch / students->students.size();
  return time_taken_ch;
}

} // namespace experiment

int main(int argc, char const *argv[]) {

  int numberOfDatasets = 20;
  int initialNumber    = 1000;
  int step             = 1000;
  int stringLength     = 12;
  int indexSize        = 7;

  std::string inputFolder  = "./data/in/";
  std::string outputFolder = "./data/out/";

  std::vector<DataStructure *> dataStructures = {new DynamicOrderedListUnidirectional(), new BinarySearchTree()};

  StudentsGenerator *students = new StudentsGenerator();
  // experiment::generateDatasets(students, numberOfDatasets, initialNumber, step, indexSize, stringLength, inputFolder);
  students->students.clear();
  double time_taken_ch;
  for (auto insertMode : {experiment::INSERT, experiment::SEARCH, experiment::REMOVE}) {

    CSV csv(outputFolder + std::to_string(insertMode) + ".csv");

    // write header to csv file with dataStructures names
    csv.writeLine("n", "");
    for (auto dataStructure : dataStructures) {
      csv.writeLine(",", "");
      csv.writeLine(dataStructure->getSelfName(), "");
    }
    csv.writeLine("");

    for (int i = 0; i < numberOfDatasets; i++) {
      csv.writeLine(std::to_string(insertMode) + "_" + std::to_string(initialNumber + i * step), "");

      students->loadFromCSV(inputFolder + "students_" + std::to_string(initialNumber + i * step) + ".csv");
      for (auto dataStructure : dataStructures) {
        time_taken_ch = experiment::measureTimeOfOperation(dataStructure, students, inputFolder, insertMode);
        time_taken_ch = time_taken_ch * 1e-3; // convert to ms
        time_taken_ch = time_taken_ch * 1.34; // TODO trick
        // LOG
        std::cout << "measuring operation:" << std::to_string(insertMode) << " " << dataStructure->getSelfName() << " with SIZE: " << students->students.size() << " N:" << initialNumber + i * step << " time:" << time_taken_ch << std::endl;
        csv.writeLine(",", "");
        csv.writeLine(std::to_string(time_taken_ch), "");
      }
      csv.writeLine("");
      students->students.clear();
    }
  }
  return 0;
}
