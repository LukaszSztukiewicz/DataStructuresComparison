#include "DynamicOrderedList.h"

ListItemUnidirectional::ListItemUnidirectional(InsertData *data) : data(data), next(nullptr){};

ListItemUnidirectional::~ListItemUnidirectional() {
  delete data; // date destructor is called
  delete next;
};

DynamicOrderedListUnidirectional::DynamicOrderedListUnidirectional() : head(nullptr) {
  selfName = "DynamicOrderedListUnidirectional";
};

DynamicOrderedListUnidirectional::~DynamicOrderedListUnidirectional() {
  ListItemUnidirectional *current = head;
  while (current != nullptr) {
    ListItemUnidirectional *next = current->next;
    delete current; // calls destructor that also deletes data
    current = next;
  }
}

void DynamicOrderedListUnidirectional::insert(InsertData *data, bool withDuplicates) {
  ListItemUnidirectional *newItem = new ListItemUnidirectional(data);
  newItem->next                   = nullptr;
  if (head == nullptr) {
    head = newItem;
    return;
  }
  ListItemUnidirectional *current = head;
  while (current->next != nullptr) {
    current = current->next;
    if (!withDuplicates && current->data->getIndex() == data->getIndex()) {
      return;
    }
  }
  current->next = newItem;
}

void DynamicOrderedListUnidirectional::remove(InsertData *data, bool byIndexOnly) {
  ListItemUnidirectional *current  = head;
  ListItemUnidirectional *previous = nullptr;
  bool isEqual;
  while (current != nullptr) {
    if (byIndexOnly) {
      isEqual = current->data->getIndex() == data->getIndex();
    } else {
      isEqual = *current->data == *data;
    }
    if (isEqual) {
      if (previous == nullptr) {
        head = current->next;
      } else {
        previous->next = current->next;
      }
      current->next = nullptr;
      delete current;
      return;
    } else {
      previous = current;
      current  = current->next;
    }
  }
}

InsertData *DynamicOrderedListUnidirectional::search(InsertData *data, bool byIndexOnly) {
  ListItemUnidirectional *current = head;
  while (current != nullptr) {
    if (byIndexOnly) {
      if (current->data->getIndex() == data->getIndex()) {
        return current->data;
      }
    } else {
      if (*current->data == *data) {
        return current->data;
      }
    }
    current = current->next;
  }
  return nullptr;
}

void DynamicOrderedListUnidirectional::print(bool indicesOnly) {
  ListItemUnidirectional *current = head;
  while (current != nullptr) {
    if (indicesOnly) {
      std::cout << current->data->getIndex() << " ";
    } else {
      std::cout << current->data->toString() << "\n";
    }
    current = current->next;
  }
  std::cout << '\n';
}
