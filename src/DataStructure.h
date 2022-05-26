#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <iostream>
#include <string>

class InsertData {
protected:
  int index;

public:
  InsertData(int index);
  virtual ~InsertData(); // to allow polymorphism
  void print();
  int getIndex();
  std::string toString();

  bool operator==(const InsertData &other) const;
};

class DataStructure {
public:
  virtual void insert(InsertData *data, bool withDuplicates)     = 0;
  virtual void remove(InsertData *data, bool byIndexOnly)        = 0;
  virtual InsertData *search(InsertData *data, bool byIndexOnly) = 0;
  virtual void print(bool indicesOnly)                           = 0;
};

#endif // DATASTRUCTURES_H