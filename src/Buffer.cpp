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

  printPage_table();
}

vector<Page>& Buffer::getFrames() { return frames; }

void Buffer::setPage(Page& page, int frameID) {
  if (frameID >= 0 && frameID < numFrames) {
    frames[frameID] = page;
    page_table[frameID] = 1;
  } else {
    cout << "SetP: Frame ID fuera de rango" << endl;
    return;
  }

  printPage(frameID);
  printPage_table();

  cout << "\nPagina [" << frameID << "] cargada Correctamente\n" << endl;
}

void Buffer::printPage(int pageID) {
  cout << "= ===================================" << endl;
  if (pageID >= 0 && pageID < numFrames) {
    if (page_table[pageID] == 1) {
      Page& page = frames[pageID];

      cout << "Frame ID: " << pageID << endl;
      cout << "Capacity: " << page.pageCapacity << endl;
      cout << "Dirty Flag: " << (page.isDirty() ? "true" : "false") << endl;
      cout << "Pin Count: " << page.getPinCount() << endl;

      cout << "Contenido del frame " << pageID << ":\n" << endl;
      for (const string& content : page.getContent()) {
        cout << content << endl;
      }
    } else {
      cout << "El frame " << pageID << " está vacío" << endl;
    }
  } else {
    cout << "PP: Page ID fuera de rango" << endl;
  }

  cout << "= ===================================" << endl;
}

void Buffer::addRecord(int pageID) {
  string record = "Transformer    3454354  cybertron";
  if (pageID >= 0 && pageID < numFrames) {
    if (page_table[pageID] == 1) {
      Page& page = frames[pageID];
      page.setContent(record);
      page.setDirtyFlag(true);
      page.setPinCount(1);
      cout << "Registro agregado al frame " << pageID << endl;
    } else {
      cout << "AddRecord: El frame " << pageID << " está vacío" << endl;
    }
  } else {
    cout << "Frame ID fuera de rango" << endl;
  }
}

int Buffer::freeFrame() {
  for (auto it = page_table.begin(); it != page_table.end(); ++it) {
    if (it->second == -1) return it->first;
  }

  /*Si retorna -2 es porque todos los frames ya tienen cargado una pagina*/
  return -2;
}

void Buffer::printPage_table() {
  for (auto it = page_table.begin(); it != page_table.end(); ++it) {
    if (it->second == 1)
      std::cout << "PageId: " << it->first << ", (status) Used: " << it->second
                << std::endl;
    else
      std::cout << "FrameId: " << it->first << ", (status) Free: " << it->second
                << std::endl;
  }
}