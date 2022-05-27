#include "experiment.h"

namespace experiment {

void generateDatasets(StudnetsGenerator *generator, int numberOfDatasets, int initialNumber, int step, int indexSize, int stringLength, std::string inputFolder) {
  for (int i = 0; i < numberOfDatasets; i++) {
    generator->generate(initialNumber + i * step, indexSize, stringLength, true);
    generator->saveToCSV(inputFolder + "students_" + std::to_string(initialNumber + i * step) + ".csv");
  }
}

void measureTimeofOperation(DataStructure *dataStructure, std::string operation, int numberOfDatasets, int initialNumber, int step, int indexSize, int stringLength, std::string inputFolder) {
  auto start_ch = std::chrono::high_resolution_clock::now();
  f(arr, n);
  auto end_ch          = std::chrono::high_resolution_clock::now();
  double time_taken_ch = std::chrono::duration_cast<std::chrono::nanoseconds>(end_ch - start_ch).count() * 1e-9;
  return time_taken_ch;
  for (int i = 0; i < numberOfDatasets; i++) {
    dataStructure->loadFromCSV(inputFolder + "students_" + std::to_string(initialNumber + i * step) + ".csv");
    std::cout << "Dataset " << initialNumber + i * step << ": ";
    std::cout << utils::measureTime(operation, dataStructure) << " ms" << std::endl;
  }
}

enum measuredOperation {
  INSERT,
  REMOVE,
  SEARCH
};

} // namespace experiment

int main(int argc, char const *argv[]) {

  int numberOfDatasets = 50;
  int initialNumber    = 1000;
  int step             = 1000;
  int stringLength     = 12;
  int indexSize        = 7;

  std::string inputFolder  = "./data/in/";
  std::string outputFolder = "./data/out/";

  std::vector<DataStructure *> dataStructures = {new DynamicOrderedListUnidirectional(), new BinarySearchTree()};

  StudnetsGenerator *students = new StudnetsGenerator();
  // experiment::generateDatasets(students, numberOfDatasets, initialNumber, step, indexSize, stringLength, inputFolder);
  for (int i = 0; i < numberOfDatasets; i++) {
    students->loadFromCSV(inputFolder + "students_" + std::to_string(initialNumber + i * step) + ".csv");
    for (auto dataStructure : dataStructures) {
      for (auto student : students->students) {

        dataStructure->insert(student, true);
      }
    }
  }
  return 0;
}
