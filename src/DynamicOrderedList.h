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
  ;

public:
  ~DynamicOrderedListUnidirectional();
  void insert(InsertData *data, bool withDuplicates = true);
  void remove(InsertData *data, bool byIndexOnly = true);
  InsertData *search(InsertData *data, bool byIndexOnly = true);
  void print(bool indicesOnly);
};

#endif // DYNAMICORDEREDLIST_H