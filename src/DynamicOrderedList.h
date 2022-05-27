#ifndef DYNAMICORDEREDLIST_H
#define DYNAMICORDEREDLIST_H

#include "DataStructure.h"
#include <iostream>

class ListItemUnidirectional {
public:
  ListItemUnidirectional(InsertData *data);
  ~ListItemUnidirectional();
  InsertData *data;
  ListItemUnidirectional *next;
};

class DynamicOrderedListUnidirectional : public DataStructure {
private:
  ListItemUnidirectional *head;

public:
  DynamicOrderedListUnidirectional();
  ~DynamicOrderedListUnidirectional();
  void insert(InsertData *data);
  void remove(InsertData *data);
  InsertData *search(InsertData *data);
  void print(bool indicesOnly) override;
};

#endif // DYNAMICORDEREDLIST_H