#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include "BalancedBinarySearchTree.h"
#include "BinarySearchTree.h"
#include "DynamicOrderedList.h"
#include "Student.h"
#include "utils.h"
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

namespace experiment {
enum measuredOperation {
  INSERT,
  REMOVE,
  SEARCH
};
void generateDatasets(StudnetsGenerator *generator, int numberOfDatasets, int initialNumber, int step, int indexSize, int stringLength, std::string inputFolder);
double measureTimeOfOperation(DataStructure *dataStructure, StudnetsGenerator *students, std::string inputFolder, experiment::measuredOperation operation);
} // namespace experiment
#endif // EXPERIMENT_H
