#include "../include/Page.h"

#include <iostream>

//Constructor por defecto que inicializa los atributos de la página con valores predeterminados
Page::Page()
    : pageCapacity(120),
      frameID(-1),
      dirty_flag(false),
      pinCount(0),
      lastUsedTime(0),
      content() {}

//Marca la página como sucia, indicando que ha sido modificada
void Page::activateDirty() { dirty_flag = true; }

//Incrementa el contador de pin cuando la pagina es usada
void Page::incrementPinCount() { ++pinCount; }

//Decrementa el contador de pines si es mayor que cero
void Page::decrementPinCount() {
  if (pinCount > 0) {
    --pinCount;
  }
}

//Devuelve el contador de pines actual
int Page::getPinCount() const { return pinCount; }

//Devuelve la marca de la página como sucia
bool Page::isDirty() const { return dirty_flag; }


const vector<string>& Page::getContent() const { return content; }

void Page::setContent(string record) {
  if (this->pageCapacity < record.length()) {
    cout << "= ===================================" << endl;
    cout << "Error: La capcidad excedio su limite" << endl;
    cout << "= ===================================" << endl;
    return;
  }
  content.push_back(record);
  this->pageCapacity -= record.length();
}

void Page::setPageCapacity(int capacity) { pageCapacity = capacity; }

void Page::setFrameID(int id) { frameID = id; }

void Page::setDirtyFlag(bool dirty) { dirty_flag = dirty; }

void Page::setPinCount(int count) { pinCount = count; }


