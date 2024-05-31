#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "../include/BufferPool.h"
#include "../include/Frame.h"

using namespace std;

BufferPool::BufferPool() {
  this->numFrames = 6;
  this->capacity = 720;

  for (int i = 0; i < this->numFrames; i++) {
    Frame frame(i);
    this->frames.push_back(frame);
    page_table[i] = -1;
  }
}

vector<Frame> &BufferPool::getFrames() { return frames; }

Frame & BufferPool::getFrame(int frameID) {
  for (int i = 0; i < frames.size(); i++) {
    if (frames[i].getframeID() == frameID) {
      return frames[i];
    }
  }
}

void BufferPool::modifyPinInExistingFrame(int pageID, char flag) {
  for (int i = 0; i < frames.size(); i++) {
    if (page_table[frames[i].getframeID()] == pageID) {
      if (flag == 'i') {
        frames[i].incrementPinCount();
      } else if (flag == 'k' && frames[i].getPinCount() > 0) {
        frames[i].decrementPinCount();
      }
    }
  }
}

void BufferPool::setPage(Frame &frame, int frameID) {
  if (frameID >= 0 && frameID < numFrames) {
    frames[frameID] = frame;
    page_table[frameID] = 1;
  } else {
    cout << "SetP: Frame ID fuera de rango" << endl;
    return;
  }
  cout << "\nPagina [" << frameID << "] cargada correctamente." << endl;
}

void BufferPool::printPage(int frameID) {
  if (frameID >= 0 && frameID < numFrames) {
    if (page_table[frameID] == 1) {
      Frame &frame = frames[frameID];
      cout << "Frame ID: " << frameID << endl;
      cout << "Dirty Flag: " << "(frame.isDirty() ? \" true \" : \" false \")" << endl;
      cout << "Pin Count: " << "frame.getPinCount()" << endl;
      cout << "Page Capacity: " << "frame.getPage().getPageCapacity()" << endl;
      cout << "Page Content: " << "frame.getPage().getPageContent() " << endl;
    } else {
      cout << "Frame ID: " << frameID << " no contiene una página." << endl;
    }
  } else {
    cout << "Frame ID fuera de rango." << endl;
  }
}

void BufferPool::addRecord(int frameID, string record) {
  if (frameID >= 0 && frameID < numFrames) {
    if (page_table[frameID] == 1) {
      Frame &frame = frames[frameID];
      // frame.getPage().addRecord(record);
      cout << "Registro agregado correctamente." << endl;
    } else {
      cout << "Frame ID: " << frameID << " no contiene una página." << endl;
    }
  } else {
    cout << "Frame ID fuera de rango." << endl;
  }
}

void BufferPool::deleteRecord(int frameID, string record) {
  if (frameID >= 0 && frameID < numFrames) {
    if (page_table[frameID] == 1) {
      Frame &frame = frames[frameID];
      // frame.getPage().deleteRecord(record);
      cout << "Registro eliminado correctamente." << endl;
    } else {
      cout << "Frame ID: " << frameID << " no contiene una página." << endl;
    }
  } else {
    cout << "Frame ID fuera de rango." << endl;
  }
}

void BufferPool::pageIsDirty(int pageID) {
  if (pageID >= 0 && pageID < numFrames) {
    if (page_table[pageID] == 1) {
      Frame &frame = frames[pageID];
      // return frame.isDirty();
      return;
    } else {
      cout << "Frame ID: " << pageID << " no contiene una página." << endl;
      return;
    }
  } else {
    cout << "Frame ID fuera de rango." << endl;
    return;
  }
}

void BufferPool::freeFrame(int frameID) {
  if (frameID >= 0 && frameID < numFrames) {
    if (page_table[frameID] == 1) {
      Frame &frame = frames[frameID];
      frame.incrementPinCount();
      page_table[frameID] = -1;
      cout << "Frame liberado correctamente." << endl;
    } else {
      cout << "Frame ID: " << frameID << " no contiene una página." << endl;
    }
  } else {
    cout << "Frame ID fuera de rango." << endl;
  }
}

int BufferPool::findFreeFrame() {
  for (auto it = page_table.begin(); it != page_table.end(); ++it) {
    if (it->second == -1) return it->first;
  }

  /*Si retorna -2 es porque todos los frames ya tienen cargado una pagina*/
  return -2;
}

void BufferPool::setPageInFrame(int frameID, int pageID, Frame &frame) {
   if (frameID >= 0 && frameID < numFrames) {
    frames[frameID] = frame;
    page_table[frameID] = pageID;
  } else {
    cout << "SetP: Frame ID fuera de rango" << endl;
    return;
  }

  //printTableFrame();

  cout << "\nPagina [" << frameID << "] cargada Correctamente\n" << endl;
}

bool BufferPool::isPageLoaded(int pageID) {
  for (const auto& pair : page_table) {
    if (pair.second == pageID) {
      return true;
    }
  }
  return false;
}

int BufferPool::getFrameId(int pageID) {
  for (const auto& pair : page_table) {
    if (pair.second == pageID) {
      return pair.first;
    }
  }
}

void BufferPool::printTableFrame() {
  cout << setw(10) << "Frame Id" << "\t"
      << setw(10) << "Page Id" << "\t"
      << setw(10) << "Dirty Bit" << "\t"
      << setw(10) << "Pin Count" << endl;

  for (int i = 0; i < frames.size(); i++) {
    cout << setw(10) << frames[i].getframeID() << "\t"
        << setw(10) << frames[i].getPage().getPageId() << "\t"
        << setw(10) << (frames[i].isDirty() ? "Yes" : "No") << "\t"
        << setw(10) << frames[i].getPinCount() << endl;
  }
}

void LRU() {
  cout << "LRU" << endl;
  /*
  En el unordered_map history, se guardará el frameID y el tiempo en el que fue accedido. Atraves de las veces que se llame en general con +1.
  Ahora se buscara cual frame tiene mas tiempo en estar. Luego se revisara si el pin count esta en cero y ahi recien se llamara la funcion freeFrame.
  */
}
