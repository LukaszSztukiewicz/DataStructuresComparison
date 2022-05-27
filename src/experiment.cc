#include "experiment.h"

namespace experiment {

void generateDatasets(StudnetsGenerator *generator, int numberOfDatasets, int initialNumber, int step, int indexSize, int stringLength, std::string inputFolder) {
  for (int i = 0; i < numberOfDatasets; i++) {
    generator->generate(initialNumber + i * step, indexSize, stringLength, true);
    generator->saveToCSV(inputFolder + "students_" + std::to_string(initialNumber + i * step) + ".csv");
  }
}

double measureTimeOfOperation(DataStructure *dataStructure, StudnetsGenerator *students, std::string inputFolder, experiment::measuredOperation operation) {
  auto start_ch = std::chrono::high_resolution_clock::now();
  switch (operation) {
  case experiment::measuredOperation::INSERT:
    for (auto student : students->students) {
      dataStructure->insert(student, true);
    }
    break;
  case experiment::measuredOperation::REMOVE:
    for (auto student : students->students) {
      dataStructure->remove(student, true);
    }
    break;
  case experiment::measuredOperation::SEARCH:
    for (auto student : students->students) {
      dataStructure->search(student, true);
    }
    break;
  }
  auto end_ch          = std::chrono::high_resolution_clock::now();
  double time_taken_ch = std::chrono::duration_cast<std::chrono::nanoseconds>(end_ch - start_ch).count() * 1e-9;
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

  StudnetsGenerator *students = new StudnetsGenerator();
  experiment::generateDatasets(students, numberOfDatasets, initialNumber, step, indexSize, stringLength, inputFolder);

  double time_taken_ch;
  for (auto insertMode : {experiment::INSERT}) {

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
        // LOG

        time_taken_ch = experiment::measureTimeOfOperation(dataStructure, students, inputFolder, insertMode);
        std::cout << "measureing " << dataStructure->getSelfName() << " with " << students->students.size() << " students"
                  << "time taken " << time_taken_ch << std::endl;
        csv.writeLine(",", "");
        csv.writeLine(std::to_string(time_taken_ch), "");
      }
      csv.writeLine("");
    }
  }
  return 0;
}
