#include "experiment.h"

namespace experiment {

void generateDatasets(StudnetsGenerator *generator, int numberOfDatasets, int initialNumber, int step, int indexSize, int stringLength, std::string inputFolder) {
  for (int i = 0; i < numberOfDatasets; i++) {
    generator->generate(initialNumber + i * step, indexSize, stringLength, true);
    generator->saveToCSV(inputFolder + "students_" + std::to_string(initialNumber + i * step) + ".csv");
  }
}

} // namespace experiment

int main(int argc, char const *argv[]) {

  int numberOfDatasets = 50;
  int initialNumber    = 1000;
  int step             = 1000;
  int stringLength     = 12;
  int indexSize        = 7;

  std::string inputFolder  = "./data/in/";
  std::string outputFolder = "./data/out/";

  StudnetsGenerator *students = new StudnetsGenerator();
  experiment::generateDatasets(students, numberOfDatasets, initialNumber, step, indexSize, stringLength, inputFolder);
  for (int i = 0; i < numberOfDatasets; i++) {
    students->loadFromCSV(inputFolder + "students_" + std::to_string(initialNumber + i * step) + ".csv");
    students->print(false, 10);
  }
  return 0;
}
