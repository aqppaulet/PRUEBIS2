#include "../include/Buffer.h"

#include <iostream>

#include "../include/Page.h"

using namespace std;

Buffer::Buffer() {
  this->numFrames = 3;
  this->capacity = 360;

  Page frame;

  for (int i = 0; i < 3; i++) {
    this->frames.push_back(frame);
    page_table[i] = -1;
  }
}

vector<Page>& Buffer::getFrames() { return frames; }

void Buffer::setPage(Page& page, int frameID) {
  if (frameID >= 0 && frameID < numFrames) {
    frames[frameID] = page;
    page_table[frameID] = 1;
  } else {
    cout << "Frame ID fuera de rango" << endl;
  }

  printPage(frameID);
}

void Buffer::printPage(int frameID) {
  cout << "= ===================================" << endl;
  if (frameID >= 0 && frameID < numFrames) {
    if (page_table[frameID] == 1) {
      Page& page = frames[frameID];

      cout << "Frame ID: " << frameID << endl;
      cout << "Capacity: " << page.pageCapacity << endl;
      cout << "Dirty Flag: " << (page.isDirty() ? "true" : "false") << endl;
      cout << "Pin Count: " << page.getPinCount() << endl;

      cout << "Contenido del frame " << frameID << ":\n" << endl;
      for (const string& content : page.getContent()) {
        cout << content << endl;
      }
    } else {
      cout << "El frame " << frameID << " está vacío" << endl;
    }
  } else {
    cout << "Frame ID fuera de rango" << endl;
  }

  cout << "= ===================================" << endl;
}

void Buffer::addRecord(int frameID) {
  string record = "Transformer    3454354  cybertron";
  if (frameID >= 0 && frameID < numFrames) {
    if (page_table[frameID] == 1) {
      Page& page = frames[frameID];
      page.setContent(record);
      page.setDirtyFlag(true);
      page.setPinCount(1);
      cout << "Registro agregado al frame " << frameID << endl;
    } else {
      cout << "El frame " << frameID << " está vacío" << endl;
    }
  } else {
    cout << "Frame ID fuera de rango" << endl;
  }
}